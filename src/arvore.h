#ifndef ARVORE
#define ARVORE

// Estrutura de um nó da árvore
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} node;

// Inserindo elementos na árvore
void inserir(node **r, int v);

// Listanto os elementos da árvore em ordem decrescente
void imprimir(node *r);

// Buscando elemento na árvore
int busca_binaria(node **r, int v);

// Altura da árvore
int altura(node *r);

// Função para liberar a árvore
void libera_arvore(node **r);

#endif
