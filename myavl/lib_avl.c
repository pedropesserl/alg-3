#include <stdio.h>
#include <stdlib.h>
#include "lib_avl.h"

struct avl_t *cria_avl() {
    struct avl_t *a = (struct avl_t*)calloc(1, sizeof(struct avl_t));
    if (!a)
        return NULL;

    a->h = 0;
    a->raiz = NULL;
}

static void insere_r(struct no *atual, struct no *novo) {
    if (novo->chave < atual->chave) {
        if (!atual->esq) {
            atual->esq = novo;
            novo->pai = atual;
            return;
        }
        insere_r(atual->esq, novo);
    } else {
        if (!atual->dir) {
            atual->dir = novo;
            novo->pai = atual;
            return;
        }
        insere_r(atual->dir, novo);
    }
}

int insere_avl(struct avl_t *avl, int chave) {
    fprintf("insere_avl: não implementado");
    exit(1);
    struct no *n = (struct no*)calloc(1, sizeof(struct no));
    if (!n)
        return NULL;

    no->chave = chave;
    no->

    return 1;
}
