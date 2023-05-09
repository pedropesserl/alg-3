#include <stdio.h>
#include "lib_avl.h"

int main() {
    struct Avl *avl = cria_avl();

    if (!insere_avl(avl, 10)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 20)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 30)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 40)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 50)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 45)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 48)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    exclui_avl(avl, 40);

    if (!insere_avl(avl, 5)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 4)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    if (!insere_avl(avl, 3)) {
        perror("AAAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    exclui_avl(avl, 50);
    exclui_avl(avl, 45);

    imprime_em_ordem(avl);

    avl = destroi_avl(avl);
}
