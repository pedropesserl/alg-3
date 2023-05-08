#ifndef LIB_AVL_H_
#define LIB_AVL_H_

struct No {
    int chave;
    /* int h; */
    struct No *pai, *esq, *dir;
};

struct Avl {
    struct No *raiz;
};

// Cria uma AVL vazia e a retorna; se falhar retorna NULL.
struct Avl *cria_avl();

// Retorna 1 se a AVL está vazia e 0 caso contrário.
int avl_vazia(struct Avl *avl);

// Imprime os elementos da árvore em ordem (esq, raiz, dir), juntamente com o
// nível da árvore em que o elemento se encontra.
void imprime_em_ordem(struct Avl *avl);

// Insere um nó com a chave chave na AVL e arruma o balanceamento da árvore.
// Retorna 1 se a operação foi bem-sucedida e 0 caso contrário.
int insere_avl(struct Avl *avl, int chave);

// Remove todos os elementos da AVL, libera espaço e retorna NULL.
struct Avl *destroi_avl(struct Avl *avl);

#endif // LIB_AVL_H_
