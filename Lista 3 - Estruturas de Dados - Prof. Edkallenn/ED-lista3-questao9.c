/*
** Função : Bubble Sort com contagem de if's e trocas
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar o BubbleSort e contar if's e trocas
void bubbleSort(int arr[], int n, int *if_count, int *swap_count) {
    *if_count = 0;
    *swap_count = 0;
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*if_count)++;
            if (arr[j] > arr[j+1]) {
                // Realiza a troca
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swap_count)++;
            }
        }
    }
}

int main() {
    int n, if_count, swap_count;

    // Solicita a quantidade de elementos do vetor
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    // Aloca memória para o vetor
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Preenche o vetor com valores aleatórios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Valores entre 0 e 99
    }

    // Mostra o vetor antes da ordenação
    printf("Vetor antes da ordenação: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o vetor e conta if's e trocas
    bubbleSort(arr, n, &if_count, &swap_count);

    // Mostra o vetor após a ordenação
    printf("Vetor após a ordenação: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Mostra o número de if's e trocas realizados
    printf("Número de comparações (if's): %d\n", if_count);
    printf("Número de trocas: %d\n", swap_count);

    // Libera a memória alocada
    free(arr);

    return 0;
}