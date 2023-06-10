Nome: Pedro Folloni Pesserl
GRR: 20220072

Esse é um trabalho desenvolvido para a disciplina CI1057 - Algoritmos e Estruturas de Dados 3, do Departamento de Informática da UFPR. Implementa a inserção e exclusão balanceadas numa árvore de busca binária AVL.


### Estruturas de dados utilizadas:

A AVL foi implementada usando as seguintes estruturas, definidas na biblioteca libavl.h:

- Nó da árvore: contém uma chave de busca e três ponteiros para nó: o pai, o filho esquerdo e o filho direito
```c
struct No {
    int chave;
    struct No *pai, *esq, *dir;
};
```

- Árvore AVL: contém um ponteiro para um nó da árvore (a raiz)
```c
struct Avl {
    struct No *raiz;
};
```

### Bibliotecas desenvolvidas:

A biblioteca desenvolvida para o trabalho foi a libavl.[hc], que define as structs acima, além das seguintes funções:
- `struct Avl *cria_avl();`
    - Cria uma AVL vazia e a retorna; se falhar retorna NULL.

- `void imprime_em_ordem(struct Avl *avl);`
    - Imprime os elementos da árvore em ordem (esq, raiz, dir), juntamente com o nível da árvore em que o elemento se encontra.

- `int insere_avl(struct Avl *avl, int chave);`
    - Insere um nó com a chave chave na AVL e arruma o balanceamento da árvore. Retorna 1 se a operação foi bem-sucedida e 0 caso haja erro de memória.

- `void exclui_avl(struct Avl *avl, int chave);`
    - Exclui o nó com a chave chave da AVL e arruma o balanceamento da árvore. Substitui pelo sucessor, se houver. Se o nó não estiver na árvore, não faz nada.

- `struct Avl *destroi_avl(struct Avl *avl);`
    - Remove todos os elementos da AVL, libera espaço e retorna NULL.

Os algoritmos utilizados são, em sua maioria, recursivos, como o cálculo da altura de um nó (maior entre a altura do filho esquerdo e a altura do filho direito, mais um), a busca binária na árvore e o balanceamento da árvore (a partir de um nó, balanceia todos os nós até a raiz). Outros algoritmos, como a busca pelo maior nó de uma subárvore são implementados em sua forma iterativa.
