#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore.h"

void menu()
{
    printf("MENU ÁRVORE\n");
    printf("(1) Inserir elemento (2) Listar elementos\n(3) Buscar (4) Altura da árvore\n(5) Balanceamento (6) Finalizar\n");
    printf("Escolha uma opção: ");
}

void inserir(node **r, int v)
{
    if (*r == NULL)
    {
        *r = (node *)malloc(sizeof(node));
        (*r)->info = v;
        (*r)->left = NULL;
        (*r)->right = NULL;
    }
    else
    {
        if ((*r)->info > v)
            inserir(&(*r)->left, v);
        else
        {
            if ((*r)->info != v)
                inserir(&(*r)->right, v);
        }
    }
}

void imprimir(node *r)
{
    printf("<");
    if (r != NULL)
    {
        printf("%d", r->info);
        imprimir(r->left);
        imprimir(r->right);
    }
    printf(">");
}

int busca_binaria(node **r, int v)
{
    if (*r == NULL)
        return 0;

    if ((*r)->info == v)
        return 1;
    else if ((*r)->info > v)
        return busca_binaria(&(*r)->left, v);
    else
        return busca_binaria(&(*r)->right, v);
}

int altura(node *r)
{
    if (r == NULL)
        return -1;
    else
    {
        int e = altura(r->left);
        int d = altura(r->right);
        if (e > d)
            return e + 1;
        else
            return d + 1;
    }
}

int cont(node *r)
{
    if (r != NULL)
        return (cont(r->left) + cont(r->right) + 1);
    else
        return 0;
}

// Usar a flag -lm no compilador gcc para incluir a biblioteca matemática padrão
int eh_balanceada(node *r)
{
    if (altura(r) >= ceil(log2(cont(r))))
        return 1;
    else
        return 0;
}

void libera_arvore(node **r)
{
    if (*r != NULL)
    {
        libera_arvore(&(*r)->left);
        libera_arvore(&(*r)->right);
        free(*r);
    }
}
