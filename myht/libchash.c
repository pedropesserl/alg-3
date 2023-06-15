#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libchash.h"

struct Hash cria_tabela() {
    struct Hash hash = {0};
    for (int i = 0; i < TABLESIZE; i++)
        hash.t1[i].vazia = hash.t2[i].vazia = 1;
    return hash;
}

int h1(int k) {
    return k % TABLESIZE;
}

int h2(int k) {
    return floor(TABLESIZE * (k * 0.9 - floor(k * 0.9)));
}

int busca_chash(struct Hash *hash, int k) {
    if (hash->t1[h1(k)].vazia && !hash->t1[h1(k)].delet)
        return -1;
    if (!hash->t1[h1(k)].vazia && hash->t1[h1(k)].chave == k)
        return h1(k);
    if (!hash->t2[h2(k)].vazia && hash->t2[h2(k)].chave == k)
        return h2(k) + TABLESIZE;
    return -1;
}

int insere_chash(struct Hash *hash, int k) {
    if (hash->t1[h1(k)].vazia) {
        hash->t1[h1(k)].chave = k;
        hash->t1[h1(k)].vazia = 0;
        hash->t1[h1(k)].delet = 0;
        return 0;
    }
    // houve colisão em T1
    if (hash->t1[h1(k)].chave == k)
        return 1; // valor repetido, não trataremos
    if (hash->t2[h2(k)].vazia) {
        int j = hash->t1[h1(k)].chave;
        hash->t2[h2(j)].chave = j;
        hash->t2[h2(j)].vazia = 0;
        hash->t2[h2(j)].delet = 0;
        hash->t1[h1(k)].chave = k;
        return 0;
    }
    if (hash->t2[h2(k)].chave == k)
        return 1; // valor repetido, não trataremos
    return 2; // colisão em T2, não trataremos
}

int exclui_chash(struct Hash *hash, int k) {
    if (!hash->t1[h1(k)].vazia && hash->t1[h1(k)].chave == k) {
        hash->t1[h1(k)].vazia = 1;
        hash->t1[h1(k)].delet = 1;
        return 0;
    }
    if (!hash->t2[h2(k)].vazia && hash->t2[h2(k)].chave == k) {
        hash->t2[h2(k)].vazia = 1;
        hash->t2[h2(k)].delet = 1;
        return 0;
    }
    return 1; // a chave não está na tabela
}

static int compara_chaves(const void *a, const void *b) {
    return ((struct Entrada*)a)->chave - ((struct Entrada*)b)->chave;
}

void imprime_chash(struct Hash *hash) {
    struct Entrada total[2*TABLESIZE];
    for (int i = 0; i < TABLESIZE; i++) {
        total[i] = hash->t1[i];
        total[i + TABLESIZE] = hash->t2[i];
    }
    qsort(total, 2*TABLESIZE, sizeof(struct Entrada), compara_chaves);
    for (int i = 0; i < 2*TABLESIZE; i++)
        if (!total[i].vazia)
            printf("%d,T%d,%d\n",
                    total[i].chave,
                    busca_chash(hash, total[i].chave) / TABLESIZE + 1, // [1..2]
                    busca_chash(hash, total[i].chave) % TABLESIZE);    // [0..10]
}
