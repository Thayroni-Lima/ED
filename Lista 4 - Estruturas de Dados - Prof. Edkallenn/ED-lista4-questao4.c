/*
** Função : Classificação por Seleção
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/
#include <stdio.h>

// Função para realizar a troca de dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação por seleção
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Percorrer todo o vetor
    for (i = 0; i < n-1; i++) {
        // Encontrar o menor elemento no subvetor não ordenado
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Trocar o menor elemento encontrado com o primeiro elemento do subvetor não ordenado
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir um vetor
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // Ler o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int arr[n];

    // Ler os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Imprimir o vetor original
    printf("Vetor original:\n");
    printArray(arr, n);

    // Ordenar o vetor
    selectionSort(arr, n);

    // Imprimir o vetor ordenado
    printf("Vetor ordenado:\n");
    printArray(arr, n);

    return 0;
}
