/*
** Função : Fila de Pacientes
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um nó da fila
typedef struct Node {
    char nome[100];
    struct Node* proximo;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* frente;
    Node* traseira;
    int quantidade;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->traseira = NULL;
    fila->quantidade = 0;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->quantidade == 0;
}

// Função para adicionar um paciente à fila
void adicionarPaciente(Fila* fila, char nome[]) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    strcpy(novoNode->nome, nome);
    novoNode->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = novoNode;
        fila->traseira = novoNode;
    } else {
        fila->traseira->proximo = novoNode;
        fila->traseira = novoNode;
    }
    fila->quantidade++;
    printf("Paciente '%s' adicionado à fila.\n", nome);
}

// Função para atender (remover) o próximo paciente da fila
char* proximoPaciente(Fila* fila) {
    if (estaVazia(fila)) {
        return "Não há pacientes na fila.";
    }

    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->traseira = NULL;
    }

    char* nome = (char*)malloc(100 * sizeof(char));
    strcpy(nome, temp->nome);
    free(temp);
    fila->quantidade--;
    return nome;
}

// Função para retornar a quantidade de pacientes na fila
int quantidadePacientes(Fila* fila) {
    return fila->quantidade;
}

// Definição da estrutura Atendimento
typedef struct {
    Fila fila;
    void (*adicionar_paciente)(Fila*, char*);
    char* (*proximo_paciente)(Fila*);
    int (*quantidade_pacientes)(Fila*);
} Atendimento;

// Função para inicializar a estrutura Atendimento
void inicializarAtendimento(Atendimento* atendimento) {
    inicializarFila(&atendimento->fila);
    atendimento->adicionar_paciente = adicionarPaciente;
    atendimento->proximo_paciente = proximoPaciente;
    atendimento->quantidade_pacientes = quantidadePacientes;
}

// Função principal
int main() {
    Atendimento atendimento;
    inicializarAtendimento(&atendimento);

    int opcao;
    char nome[100];

    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Quantidade de pacientes na fila\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]", nome);
                atendimento.adicionar_paciente(&atendimento.fila, nome);
                break;
            case 2: {
                char* paciente = atendimento.proximo_paciente(&atendimento.fila);
                if (strcmp(paciente, "Não há pacientes na fila.") == 0) {
                    printf("%s\n", paciente);
                } else {
                    printf("Paciente '%s' atendido.\n", paciente);
                    free(paciente);  // Liberar a memória alocada para o nome do paciente
                }
                break;
            }
            case 3:
                printf("Quantidade de pacientes na fila: %d\n", atendimento.quantidade_pacientes(&atendimento.fila));
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar a memória alocada para a fila antes de sair
    while (!estaVazia(&atendimento.fila)) {
        char* paciente = atendimento.proximo_paciente(&atendimento.fila);
        free(paciente);
    }

    return 0;
}
