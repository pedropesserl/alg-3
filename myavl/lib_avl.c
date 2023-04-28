#include <stdio.h>
#include <stdlib.h>
#include "lib_avl.h"

struct avl_t *cria_avl() {
    struct avl_t *avl = (struct avl_t*)calloc(1, sizeof(struct avl_t));
    if (!avl)
        return NULL;

    avl->h = 0;
    avl->raiz = NULL;
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
    struct no *n = (struct no*)calloc(1, sizeof(struct no));
    if (!n)
        return 0;

    n->chave = chave;
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;

    insere_r(avl->raiz, no);

    fprintf("balanceamento na inserção não implementado\n");
    exit(1);

    return 1;
}
