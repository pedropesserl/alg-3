#ifndef LIBCHASH_H_
#define LIBCHASH_H_

#define TABLESIZE 11

struct Entrada {
    int chave, vazia, delet;
};

struct Hash {
    struct Entrada t1[TABLESIZE], t2[TABLESIZE];
};

// cria uma tabela hash com todas as entradas vazias.
struct Hash cria_tabela();

// função hash para a tabela 1.
int h1(int k);

// função hash para a tabela 2.
int h2(int k);

// se a chave não estiver na tabela, retorna -1.
// se estiver na tabela 1, retorna a posição (um valor [0..10]).
// se estiver na tabela 2, retorna a posição mais TABLESIZE (um valor [11..21]).
int busca_chash(struct Hash *hash, int k);

// se a inserção ocorrer normalmente, retorna 0.
// se houver tentativa de inserir um valor duplicado, não faz nada e retorna 1.
// se o valor não puder ser incluído (colisão em T2), não faz nada e retorna 2.
int insere_chash(struct Hash *hash, int k);

// se a exclusão ocorrer normalmente, retorna 0.
// se a chave k não estiver na tabela, não faz nada e retorna 1.
int exclui_chash(struct Hash *hash, int k);

// imprime as chaves armazenadas na tabela em ordem crescente,
// seguido pela tabela na qual a chave se encontra ("T1" ou "T2"),
// seguido pela posição da chave na tabela (valor [0..10]).
void imprime_chash(struct Hash *hash);

#endif // LIBCHASH_H_
