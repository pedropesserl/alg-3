#include <stdio.h>
#include "libchash.h"

int main(void) {
    struct Hash tabela = cria_tabela();
    char acao;
    int chave;

    while (scanf(" %c %d", &acao, &chave) != EOF) {
        if (acao == 'i') {
            insere_chash(&tabela, chave);
        } else if (acao == 'r') {
            exclui_chash(&tabela, chave);
        } else {
            fprintf(stderr, "Erro: caracter inválido inserido\n");
            return 1;
        }
    }

    imprime_chash(&tabela);

    return 0;
}
