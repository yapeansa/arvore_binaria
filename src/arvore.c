#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

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
            inserir(&(*r)->right, v);
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

void libera_arvore(node **r)
{
    if (*r != NULL)
    {
        libera_arvore(&(*r)->left);
        libera_arvore(&(*r)->right);
        free(*r);
    }
}
