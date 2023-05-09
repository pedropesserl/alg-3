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


// Retorna um ponteiro para o nó da subárvore enraizada em n que contém a
// chave chave. Se não houver, retorna NULL.
static struct No *bb_r(struct No *n, int chave) {
    if (!n)
        return NULL;
    if (chave < n->chave)
        return bb_r(n->esq, chave);
    if (chave > n->chave)
        return bb_r(n->dir, chave);
    return n;
}

// Retorna um ponteiro para o nó com a menor chave da subárvore enraizada em n.
static struct No *minimo(struct No *n) {
    struct No *min = n;
    while (min->esq)
        min = min->esq;
    return min;
}

// Calcula e devole a altura de um nó n da árvore. Considera que um nó sem
// filhos tem altura 0, e consequentemente um NULL tem altura -1.
static int altura_r(struct No *n) {
    if (!n)
        return -1;
    int e = altura_r(n->esq);
    int d = altura_r(n->dir);
    return e > d ? e+1 : d+1;
}

// Arruma altura do pai, avô, etc de n
/* static void arruma_altura(struct No *n) { */
/*     struct No *aux = n; */
/*     while (aux->pai && aux->pai->h == aux->h) { */
/*         aux = aux->pai; */
/*         (aux->h)++; */
/*     } */
/* } */

static int balanceamento(struct No *n) {
    return altura_r(n->esq) - altura_r(n->dir);
}

static int no_balanceado(struct No *n) {
    return abs(altura_r(n->esq) - altura_r(n->dir)) <= 1;
}

static struct No *rot_esq(struct Avl *avl, struct No *x) {
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
    return y;
}

static struct No *rot_dir(struct Avl *avl, struct No *x) {
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
    return y;
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

static void balanceia_avl_r(struct Avl *avl, struct No *x) {
    if (!x)
        return;
    if (!no_balanceado(x)) {
        if (balanceamento(x) == -2) {    // pendendo para a esquerda
            if (balanceamento(x->dir) > 0)    // zig-zag
                x->dir = rot_dir(avl, x->dir);
            x = rot_esq(avl, x);
        } else {                        // pendendo para a direita
            if (balanceamento(x->esq) < 0)    // zig-zag
                x->esq = rot_esq(avl, x->esq);
            x = rot_dir(avl, x);
        }
    }
    balanceia_avl_r(avl, x->pai);
}

int insere_avl(struct Avl *avl, int chave) {
    struct No *n = (struct No*)calloc(1, sizeof(struct No));
    if (!n)
        return 0;

    n->chave = chave;
    /* n->h = 0; */
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;

    if (avl_vazia(avl)) {
        avl->raiz = n;
        return 1;
    }

    insere_r(avl->raiz, n);

    /* arruma_altura(n); */

    balanceia_avl_r(avl, n->pai);

    return 1;
}

void exclui_avl(struct Avl *avl, int chave) {
    struct No *n = bb_r(avl->raiz, chave);
    if (!n)
        return;

    // n não tem filhos
    if (!n->esq && !n->dir) {
        if (n == avl->raiz) {
            free(n);
            free(avl);
            return;
        }
        if (n == n->pai->esq)
            n->pai->esq = NULL;
        else
            n->pai->dir = NULL;
        balanceia_avl_r(avl, n->pai);
        free(n);
        return;
    }

    // somente filho esquerdo
    if (!n->dir) {
        if (n == avl->raiz)
            avl->raiz = n->esq;
        else {
            if (n == n->pai->esq)
                n->pai->esq = n->esq;
            else
                n->pai->dir = n->esq;
        }
        n->esq->pai = n->pai;
        balanceia_avl_r(avl, n->pai);
        free(n);
        return;
    }

    // somente filho direito
    if (!n->esq) {
        if (n == avl->raiz)
            avl->raiz = n->dir;
        else {
            if (n == n->pai->esq)
                n->pai->esq = n->dir;
            else
                n->pai->dir = n->dir;
        }
        n->dir->pai = n->pai;
        balanceia_avl_r(avl, n->pai);
        free(n);
        return;
    }

    // dois filhos
    struct No *suc = minimo(n->dir);
    n->chave = suc->chave;

    // o sucessor pode ter, no máximo, um filho (da direita), sem netos.
    if (!suc->dir) {
        if (suc == suc->pai->esq)
            suc->pai->esq = NULL;
        else
            suc->pai->dir = NULL;
    } else {
        if (suc == suc->pai->esq)
            suc->pai->esq = suc->dir;
        else
            suc->pai->dir = suc->dir;
        suc->dir->pai = suc->pai;
    }
    balanceia_avl_r(avl, suc->pai);
    free(suc);
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
