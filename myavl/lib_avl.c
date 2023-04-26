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

// Retorna um ponteiro para o nó que contém a chave chave.
static struct no *bb_recursiva(struct no *n, int chave) {
    fprintf("bb_recursiva: não implementado");
    exit(1);
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
