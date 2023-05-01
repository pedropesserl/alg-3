#ifndef LIB_AVL_H_
#define LIB_AVL_H_

struct no {
    int chave;
    size_t h;
    struct no *pai;
    struct no *esq;
    struct no *dir;
};

struct avl_t {
    struct no *raiz;
};

// Cria uma AVL vazia e a retorna; se falhar retorna NULL.
struct avl_t *cria_avl();

// Retorna 1 se a AVL está vazia e 0 caso contrário.
int avl_vazia(struct avl_t *avl);

// Imprime os elementos da árvore em ordem (esq, raiz, dir), juntamente com o
// nível da árvore em que o elemento se encontra.
void imprime_em_ordem(struct avl_t *avl);

// Insere um nó com a chave chave na AVL e arruma o balanceamento da árvore.
// Retorna 1 se a operação foi bem-sucedida e 0 caso contrário.
int insere_avl(struct avl_t *avl, int chave);

// Remove todos os elementos da AVL, libera espaço e retorna NULL.
struct avl_t *destroi_avl(struct avl_t *avl);

#endif // LIB_AVL_H_
