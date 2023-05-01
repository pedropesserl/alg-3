#include <stdio.h>
#include "lib_avl.h"

int main() {
    struct avl_t *avl = cria_avl();

    if (!insere_avl(avl, 5)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 10)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 1)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 9)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 2)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 8)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 3)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 11)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    imprime_em_ordem(avl);

    avl = destroi_avl(avl);
}
