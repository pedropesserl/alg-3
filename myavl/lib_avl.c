#include <stdio.h>
#include <stdlib.h>
#include "lib_avl.h"

struct avl_t *cria_avl() {
    struct avl_t *avl = (struct avl_t*)calloc(1, sizeof(struct avl_t));
    if (!avl)
        return NULL;

    avl->raiz = NULL;
    return avl;
}

int avl_vazia(struct avl_t *avl) {
    return avl->raiz == NULL;
}

static void em_ordem_r(struct no *n, int nivel) {
    if (!n)
        return;
    em_ordem_r(n->esq, nivel + 1);
    printf("%d,%d\n", n->chave, nivel);
    em_ordem_r(n->dir, nivel + 1);
}

void imprime_em_ordem(struct avl_t *avl) {
    em_ordem_r(avl->raiz, 0);
}

static void rot_esq(struct avl_t *avl, struct no *x) {
    struct no *y = x->dir;
    x->dir = y->esq;

    if (y->esq)
        y->esq->pai = x;

    y->pai = x->pai;

    if (!x->pai)
        avl->raiz = y;
    else
        if (x == x->pai->esq)
            x->pai->esq = y;
        else
            x->pai->dir = y;
    
    y->esq = x;
    x->pai = y;
}

static void rot_dir(struct avl_t *avl, struct no *x) {
    struct no *y = x->esq;
    x->esq = y->dir;

    if (y->dir)
        y->dir->pai = x;

    y->pai = x->pai;

    if (!x->pai)
        avl->raiz = y;
    else
        if (x == x->pai->esq)
            x->pai->esq = y;
        else
            x->pai->dir = y;
    
    y->dir = x;
    x->pai = y;
}

static int no_balanceado(struct no *n) {
    if (!n->esq && !n->dir)
        return 1;
    if (!n->esq)
        return n->dir->h == 0;
    if (!n->dir)
        return n->esq->h == 0;
    return abs(n->esq->h - n->dir->h) <= 1;
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

// Arruma altura do pai, avô, etc de n
static void arruma_altura(struct no *n) {
    struct no *aux = n;
    while (aux->pai && aux->pai->h == aux->h) {
        aux = aux->pai;
        (aux->h)++;
    }
}

static void balanceia_avl_r(struct avl_t *avl, struct no *x) {
    fprintf(stderr, "balanceia_avl() nao implementada\n");
    exit(69);

    if (!x)
        return;
    
    if (no_balanceado(x->dir) )
        rot_esq(avl, x);
    else if (no_balanceado(x->esq))
        rot_dir(avl, x);
    else

    balanceia_avl_r(avl, x->pai);
}

int insere_avl(struct avl_t *avl, int chave) {
    struct no *n = (struct no*)calloc(1, sizeof(struct no));
    if (!n)
        return 0;

    n->chave = chave;
    n->h = 0;
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;

    if (avl_vazia(avl)) {
        avl->raiz = n;
        return 1;
    }

    insere_r(avl->raiz, n);

    arruma_altura(n);

    balanceia_avl(n->pai);

    return 1;
}

// Libera os nós no formato pós-ordem (esq, dir, raiz)
static void libera_no_r(struct no *n) {
    if (!n)
        return;
    libera_no_r(n->esq);
    libera_no_r(n->dir);
    free(n);
}

struct avl_t *destroi_avl(struct avl_t *avl) {
    libera_no_r(avl->raiz);
    free(avl);
    return NULL;
}
