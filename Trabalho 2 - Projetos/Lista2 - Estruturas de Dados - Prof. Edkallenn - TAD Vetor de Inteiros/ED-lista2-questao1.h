/*
** Função : TAD Vetor de Inteiros
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

// Definição da estrutura do vetor dinâmico
typedef struct {
    int *data;   // Ponteiro para os dados
    int size;    // Número atual de elementos no vetor
    int capacity; // Capacidade do vetor
} DynamicArray;

// Funções do TAD
DynamicArray* create_array(int capacity);
void insert_element(DynamicArray* array, int element);
void remove_element(DynamicArray* array, int position);
int get_element(DynamicArray* array, int position);
void print_array(DynamicArray* array);
void delete_array(DynamicArray* array);