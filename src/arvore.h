#ifndef ARVORE
#define ARVORE

// Estrutura de um nó da árvore
typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
} node;

// Inicializando uma árvore vazia
node *init(void);

// Inserindo elementos na árvore
void inserir(node **r, int v);

// Listanto os elementos da árvore em ordem decrescente
void listar(node *r);

// Buscando elemento na árvore
int busca_binaria(node **r, int v);

// Função para liberar a árvore
void libera_arvore(node **r);

#endif
