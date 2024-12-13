#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void)
{
    node *tree = init();
    int v, opcao = 0;

    do
    {
        printf("O que você deseja fazer?\n");
        printf("(1) Inserir elemento (2) Listar elementos (3) Buscar (4) Finalizar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a inserir: ");
            scanf("%d", &v);
            inserir(&tree, v);
            break;
        case 2:
            listar(tree);
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
            printf("Finalizando...\n");
            libera_arvore(&tree);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n");
        }
    } while (opcao != 4);

    return 0;
}
