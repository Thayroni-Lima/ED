/*
** Função : Pilha de Processos
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um processo
typedef struct {
    int id;
    char descricao[100];
} Processo;

// Definição da estrutura da pilha
typedef struct {
    Processo *processos;
    int topo;
    int capacidade;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha, int capacidade) {
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->processos = (Processo *)malloc(capacidade * sizeof(Processo));
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para incluir um processo na pilha
void incluirProcesso(Pilha *pilha, int id, char descricao[]) {
    if (estaCheia(pilha)) {
        printf("A pilha está cheia. Não é possível adicionar mais processos.\n");
        return;
    }
    pilha->topo++;
    pilha->processos[pilha->topo].id = id;
    strcpy(pilha->processos[pilha->topo].descricao, descricao);
    printf("Processo #%d - %s incluído na pilha.\n", id, descricao);
}

// Função para retirar um processo da pilha
void retirarProcesso(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    Processo removido = pilha->processos[pilha->topo];
    pilha->topo--;
    printf("Removido o processo #%d - %s\n", removido.id, removido.descricao);
}

// Função para imprimir o estado atual da pilha
void imprimirPilha(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Estado atual da pilha:\n");
    for (int i = 0; i <= pilha->topo; i++) {
        printf("Processo #%d - %s\n", pilha->processos[i].id, pilha->processos[i].descricao);
    }
}

// Função para esvaziar a pilha
void esvaziarPilha(Pilha *pilha) {
    while (!estaVazia(pilha)) {
        retirarProcesso(pilha);
    }
    free(pilha->processos);
}

int main() {
    Pilha pilha;
    int capacidade = 10;  // Capacidade máxima da pilha
    inicializarPilha(&pilha, capacidade);

    int opcao;
    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Incluir processo\n");
        printf("2. Retirar processo\n");
        printf("3. Encerrar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int id;
                char descricao[100];
                printf("Digite o identificador do processo: ");
                scanf("%d", &id);
                printf("Digite a descrição do processo: ");
                scanf(" %[^\n]", descricao);
                incluirProcesso(&pilha, id, descricao);
                imprimirPilha(&pilha);
                break;
            }
            case 2:
                retirarProcesso(&pilha);
                imprimirPilha(&pilha);
                break;
            case 3:
                printf("Encerrando o programa e esvaziando a pilha...\n");
                esvaziarPilha(&pilha);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
