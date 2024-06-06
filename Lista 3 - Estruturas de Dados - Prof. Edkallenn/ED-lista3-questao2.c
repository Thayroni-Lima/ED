/*
** Função : Registro Empregado
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Empregado
typedef struct {
    char nome[100];
    char dataNascimento[11]; // formato: dd/mm/yyyy
    char rg[20];
    char dataAdmissao[11]; // formato: dd/mm/yyyy
    double salario;
} Empregado;

// Função para ler os dados de um empregado
void lerEmpregado(Empregado *emp) {
    printf("Digite o nome do empregado: ");
    scanf(" %[^\n]", emp->nome); // Lê até a quebra de linha

    printf("Digite a data de nascimento (dd/mm/yyyy): ");
    scanf("%s", emp->dataNascimento);

    printf("Digite o RG: ");
    scanf("%s", emp->rg);

    printf("Digite a data de admissão (dd/mm/yyyy): ");
    scanf("%s", emp->dataAdmissao);

    printf("Digite o salário: ");
    scanf("%lf", &emp->salario);
}

// Função para imprimir os dados de um empregado
void imprimirEmpregado(const Empregado *emp) {
    printf("Nome: %s\n", emp->nome);
    printf("Data de Nascimento: %s\n", emp->dataNascimento);
    printf("RG: %s\n", emp->rg);
    printf("Data de Admissão: %s\n", emp->dataAdmissao);
    printf("Salário: %.2lf\n", emp->salario);
}

// Função para excluir um empregado (substitui pelo último no vetor)
void excluirEmpregado(Empregado *empregados, int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Índice inválido!\n");
        return;
    }

    // Subtstitui o empregado a ser excluído pelo último
    empregados[index] = empregados[*n - 1];
    (*n)--;
}

int main() {
    int n;
    printf("Digite o número de empregados: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor de empregados
    Empregado *empregados = (Empregado*) malloc(n * sizeof(Empregado));

    // Leitura dos dados dos empregados
    for (int i = 0; i < n; i++) {
        printf("Empregado %d:\n", i + 1);
        lerEmpregado(&empregados[i]);
    }

    // Impressão dos dados dos empregados
    printf("\nLista de empregados:\n");
    for (int i = 0; i < n; i++) {
        printf("Empregado %d:\n", i + 1);
        imprimirEmpregado(&empregados[i]);
    }

    // Excluir um empregado (exemplo)
    int index;
    printf("\nDigite o índice do empregado a ser excluído (1 a %d): ", n);
    scanf("%d", &index);
    excluirEmpregado(empregados, &n, index - 1); // Ajuste do índice para 0-based

    // Impressão dos dados dos empregados após exclusão
    printf("\nLista de empregados após exclusão:\n");
    for (int i = 0; i < n; i++) {
        printf("Empregado %d:\n", i + 1);
        imprimirEmpregado(&empregados[i]);
    }

    // Liberação da memória alocada
    free(empregados);

    return 0;
}
