#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore.h"

int main(void)
{
    node *tree = NULL; // Inicializando uma árvore vazia
    int v, opcao = 0;

    do
    {
        printf("O que você deseja fazer?\n");
        printf("(1) Inserir elemento (2) Listar elementos (3) Buscar (4) Altura da árvore (5) Finalizar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a inserir: ");
            scanf("%d", &v);
            inserir(&tree, v);
            break;
        case 2:
            imprimir(tree);
            printf("\n");
            break;
        case 3:
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &v);
            if (busca_binaria(&tree, v))
                printf("O elemento %d está na árvore.\n\n", v);
            else
                printf("O elemento %d não está na árvore.\n\n", v);
            break;
        case 4:
            printf("Altura da álvore: %d.\n", altura(tree));
            break;
        case 5:
            if (eh_balanceada(tree))
                printf("Árvore balanceada.\n");
            else
                printf("Árvore NÃO balanceada.\n");
        case 6:
            printf("Finalizando...\n");
            libera_arvore(&tree);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n");
        }
    } while (opcao != 6);

    return 0;
}
