#ifndef ARVORE
#define ARVORE

// Estrutura de um nó da árvore
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} node;

// Interface do menu
void menu();

// Inserindo elementos na árvore
void inserir(node **r, int v);

// Listanto os elementos da árvore em ordem decrescente
void imprimir(node *r);

// Buscando elemento na árvore
int busca_binaria(node **r, int v);

// Altura da árvore
int altura(node *r);

// Conta nó
int cont(node *r);

// Balanceamento
int eh_balanceada(node *r);

// Função para liberar a árvore
void libera_arvore(node **r);

#endif
