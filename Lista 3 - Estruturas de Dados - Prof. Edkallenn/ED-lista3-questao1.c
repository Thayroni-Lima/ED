/*
** Função : classificação por seleção
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para realizar a ordenação por seleção
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Mova o limite do subvetor de 0 para n-1
    for (i = 0; i < n-1; i++) {
        // Encontre o menor elemento no subvetor não ordenado
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troque o menor elemento encontrado com o primeiro elemento
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int n;

    // Leitura do tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor
    int *arr = (int*) malloc(n * sizeof(int));

    // Leitura dos elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Vetor original: \n");
    printArray(arr, n);

    // Ordenação do vetor
    selectionSort(arr, n);

    printf("Vetor ordenado: \n");
    printArray(arr, n);

    // Liberação da memória alocada
    free(arr);

    return 0;
}