/*
** Função : Vetor de Ponteiros - Aeroporto
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGLA 4
#define MAX_CIDADE 51
#define MAX_PAIS 31

// Definição da estrutura aeroporto
typedef struct {
    char sigla[MAX_SIGLA];
    char cidade[MAX_CIDADE];
    char pais[MAX_PAIS];
    float taxa;
    int capacidade;
} aeroporto;

typedef aeroporto* Aeroporto;

// Função para ler os dados de um aeroporto
void lerAeroporto(Aeroporto a) {
    printf("Digite a sigla do aeroporto (3 caracteres): ");
    scanf("%s", a->sigla);
    
    printf("Digite a cidade do aeroporto: ");
    scanf(" %[^\n]", a->cidade);  // Lê até o final da linha
    
    printf("Digite o país do aeroporto: ");
    scanf(" %[^\n]", a->pais);  // Lê até o final da linha
    
    printf("Digite a taxa do aeroporto: ");
    scanf("%f", &a->taxa);
    
    printf("Digite a capacidade do aeroporto: ");
    scanf("%d", &a->capacidade);
}

// Função para escrever os dados de um aeroporto
void escreverAeroporto(Aeroporto a) {
    printf("Sigla: %s\n", a->sigla);
    printf("Cidade: %s\n", a->cidade);
    printf("País: %s\n", a->pais);
    printf("Taxa: %.2f\n", a->taxa);
    printf("Capacidade: %d\n", a->capacidade);
}

// Função para excluir um aeroporto do vetor
void excluirAeroporto(Aeroporto* aeroportos, int* n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Índice inválido!\n");
        return;
    }
    
    free(aeroportos[indice]);
    
    for (int i = indice; i < *n - 1; i++) {
        aeroportos[i] = aeroportos[i + 1];
    }
    
    (*n)--;
    aeroportos = realloc(aeroportos, (*n) * sizeof(Aeroporto));
    if (*n > 0 && aeroportos == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

int main() {
    int n = 0;  // Número de aeroportos
    Aeroporto* aeroportos = NULL;  // Vetor de aeroportos
    
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar aeroporto\n");
        printf("2. Listar aeroportos\n");
        printf("3. Excluir aeroporto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                n++;
                aeroportos = realloc(aeroportos, n * sizeof(Aeroporto));
                if (aeroportos == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                aeroportos[n - 1] = malloc(sizeof(aeroporto));
                if (aeroportos[n - 1] == NULL) {
                    printf("Erro ao alocar memória!\n");
                    exit(1);
                }
                lerAeroporto(aeroportos[n - 1]);
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("\nAeroporto %d:\n", i + 1);
                    escreverAeroporto(aeroportos[i]);
                }
                break;
            case 3:
                printf("Digite o índice do aeroporto a ser excluído (1 a %d): ", n);
                int indice;
                scanf("%d", &indice);
                excluirAeroporto(aeroportos, &n, indice - 1);
                break;
            case 0:
                for (int i = 0; i < n; i++) {
                    free(aeroportos[i]);
                }
                free(aeroportos);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
