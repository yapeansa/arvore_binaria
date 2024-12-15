#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void)
{
    node *root = NULL; // Inicializando uma árvore vazia
    int v, opcao = 0;

    do
    {
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a inserir: ");
            scanf("%d", &v);
            inserir(&root, v);
            break;
        case 2:
            imprimir(root);
            printf("\n");
            break;
        case 3:
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &v);
            if (busca_binaria(&root, v))
                printf("O elemento %d está na árvore.\n\n", v);
            else
                printf("O elemento %d não está na árvore.\n\n", v);
            break;
        case 4:
            printf("Altura da álvore: %d.\n", altura(root));
            break;
        case 5:
            if (eh_balanceada(root))
                printf("Árvore balanceada.\n");
            else
                printf("Árvore NÃO balanceada.\n");
            break;
        case 6:
            printf("Finalizando...\n");
            libera_arvore(&root);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n");
        }
    } while (opcao != 6);

    return 0;
}
