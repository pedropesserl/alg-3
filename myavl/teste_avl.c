#include <stdio.h>
#include "lib_avl.h"

int main() {
    struct Avl *avl = cria_avl();

    for (int i = 0; i <= 10; i++) {
        if (!insere_avl(avl, i))
            perror("AAAAAAAAAAAAAAAAAAAAAAA\n");
    }

    exclui_avl(avl, 7);
    exclui_avl(avl, 8);

    exclui_avl(avl, 10);
    /* exclui_avl(avl, 9); */

    /* if (!insere_avl(avl, 10)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 20)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 30)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 40)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 50)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 45)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    /* if (!insere_avl(avl, 48)) { */
    /*     perror("AAAAAAAAAAAAAAAAAAAAAAAA\n"); */
    /* } */

    imprime_em_ordem(avl);

    avl = destroi_avl(avl);
}
