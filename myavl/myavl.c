#include <stdio.h>
#include <stdlib.h>
#include "lib_avl.h"

int main(void) {
    struct Avl *avl = cria_avl();
    char acao;
    int chave;

    while (scanf(" %c %d", &acao, &chave) != EOF) {
        if (acao == 'i') {
            if (!insere_avl(avl, chave)) {
                fprintf(stderr, "Erro: falha na alocação de memória\n");
                exit(1);
            }
        } else if (acao == 'r') {
            exclui_avl(avl, chave);
        } else {
            fprintf(stderr, "Erro: caracter inválido inserido\n");
            exit(2);
        }
    }

    imprime_em_ordem(avl);
    avl = destroi_avl(avl);

    return 0;
}
