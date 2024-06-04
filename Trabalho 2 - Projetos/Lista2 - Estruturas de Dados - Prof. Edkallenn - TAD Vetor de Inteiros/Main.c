/*
** Função : TAD Vetor de Inteiros
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/


#include <stdio.h>
#include "ED-lista2-questao1.h"

int main() {
    int capacidade_inicial;
    printf("Digite a capacidade inicial do vetor: ");
    scanf("%d", &capacidade_inicial);

    // Criação do vetor dinâmico
    DynamicArray* array = create_array(capacidade_inicial);

    int escolha, elemento, posicao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Consultar elemento\n");
        printf("4. Imprimir vetor\n");
        printf("5. Deletar vetor e sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                insert_element(array, elemento);
                break;
            case 2:
                printf("Digite a posição do elemento a ser removido: ");
                scanf("%d", &posicao);
                remove_element(array, posicao);
                break;
            case 3:
                printf("Digite a posição do elemento a ser consultado: ");
                scanf("%d", &posicao);
                elemento = get_element(array, posicao);
                if (elemento != -1) {
                    printf("Elemento na posição %d: %d\n", posicao, elemento);
                }
                break;
            case 4:
                print_array(array);
                break;
            case 5:
                delete_array(array);
                printf("Vetor deletado. Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 5);

    return 0;
}