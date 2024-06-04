/*
** Função : TAD Vetor de Inteiros
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include "ED-lista2-questao1.h"

// Função para criar um vetor dinâmico
DynamicArray* create_array(int capacity) {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    array->data = (int*)malloc(capacity * sizeof(int));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

// Função para inserir um elemento no vetor dinâmico
void insert_element(DynamicArray* array, int element) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = (int*)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size] = element;
    array->size++;
}

// Função para remover um elemento do vetor dinâmico
void remove_element(DynamicArray* array, int position) {
    if (position < 0 || position >= array->size) {
        printf("Posição inválida!\n");
        return;
    }
    for (int i = position; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

// Função para obter um elemento em uma determinada posição do vetor dinâmico
int get_element(DynamicArray* array, int position) {
    if (position < 0 || position >= array->size) {
        printf("Posição inválida!\n");
        return -1;
    }
    return array->data[position];
}

// Função para imprimir os elementos do vetor dinâmico
void print_array(DynamicArray* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Função para deletar o vetor dinâmico
void delete_array(DynamicArray* array) {
    free(array->data);
    free(array);
}
