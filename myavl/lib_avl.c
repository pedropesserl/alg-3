#include <stdio.h>
#include <stdlib.h>
#include "lib_avl.h"

struct Avl *cria_avl() {
    struct Avl *avl = (struct Avl*)calloc(1, sizeof(struct Avl));
    if (!avl)
        return NULL;

    avl->raiz = NULL;
    return avl;
}

int avl_vazia(struct Avl *avl) {
    return avl->raiz == NULL;
}

static void em_ordem_r(struct No *n, int nivel) {
    if (!n)
        return;
    em_ordem_r(n->esq, nivel + 1);
    printf("%d,%d\n", n->chave, nivel);
    em_ordem_r(n->dir, nivel + 1);
}

void imprime_em_ordem(struct Avl *avl) {
    em_ordem_r(avl->raiz, 0);
}

// Devolve a altura de um dado nó da árvore. Considera que um nó sem filhos
// tem altura 0, e consequentemente um NULL tem altura -1.
static int altura_r(struct No *n) {
    if (!n)
        return -1;
    int e = altura_r(n->esq);
    int d = altura_r(n->dir);
    return e > d ? e+1 : d+1;
}

// TODO: se possível, remover essa função porque ela é paia
static int no_balanceado(struct No *n) {
    return abs(altura_r(n->esq) - altura_r(n->dir)) <= 1;
}

static void rot_esq(struct Avl *avl, struct No *x) {
    struct No *y = x->dir;
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

static void rot_dir(struct Avl *avl, struct No *x) {
    struct No *y = x->esq;
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

static void insere_r(struct No *atual, struct No *novo) {
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

// OBS: Teoricamente essa função não tem mais utilidade por causa da
// altura_r(). Mesmo assim, seria melhor poder saber a altura de um nó
// instantaneamente em vez de ter que calcular ela toda vez.
//
// Arruma altura do pai, avô, etc de n
// static void arruma_altura(struct No *n) {
//     struct No *aux = n;
//     while (aux->pai && aux->pai->h == aux->h) {
//         aux = aux->pai;
//         (aux->h)++;
//     }
// }

static void balanceia_avl_r(struct Avl *avl, struct No *x) {
    // TODO: essa função aqui ¯\_(ツ)_/¯
    fprintf(stderr, "balanceia_avl() nao implementada\n");
    exit(69);



}

int insere_avl(struct Avl *avl, int chave) {
    struct No *n = (struct No*)calloc(1, sizeof(struct No));
    if (!n)
        return 0;

    n->chave = chave;
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;

    if (avl_vazia(avl)) {
        avl->raiz = n;
        return 1;
    }

    insere_r(avl->raiz, n);

    /* arruma_altura(n); */

    balanceia_avl(n->pai);

    return 1;
}

// Libera os nós no formato pós-ordem (esq, dir, raiz)
static void libera_no_r(struct No *n) {
    if (!n)
        return;
    libera_no_r(n->esq);
    libera_no_r(n->dir);
    free(n);
}

struct Avl *destroi_avl(struct Avl *avl) {
    libera_no_r(avl->raiz);
    free(avl);
    return NULL;
}
