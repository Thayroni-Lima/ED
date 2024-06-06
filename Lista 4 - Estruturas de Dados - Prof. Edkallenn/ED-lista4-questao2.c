/*
** Função : Pilha de Reais
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na pilha
typedef struct Node {
    float valor;
    struct Node* prox;
} Node;

// Função para criar um novo nó
Node* criarNode(float valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novoNode->valor = valor;
    novoNode->prox = NULL;
    return novoNode;
}

// Função para empilhar um valor na pilha (push)
void push(Node** topo, float valor) {
    Node* novoNode = criarNode(valor);
    novoNode->prox = *topo;
    *topo = novoNode;
    printf("Valor %f empilhado com sucesso.\n", valor);
}

// Função para desempilhar um valor da pilha (pop)
void pop(Node** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia, não é possível desempilhar.\n");
        return;
    }
    Node* temp = *topo;
    *topo = (*topo)->prox;
    printf("Valor %f desempilhado com sucesso.\n", temp->valor);
    free(temp);
}

// Função para verificar se a pilha está vazia
int isEmpty(Node* topo) {
    return topo == NULL;
}

// Função para exibir os elementos da pilha
void exibirPilha(Node* topo) {
    if (isEmpty(topo)) {
        printf("Pilha vazia.\n");
        return;
    }
    Node* atual = topo;
    printf("Elementos na pilha:\n");
    while (atual != NULL) {
        printf("%f\n", atual->valor);
        atual = atual->prox;
    }
}

int main() {
    Node* pilha = NULL;
    int opcao;
    float valor;

    do {
        printf("\nMenu\n");
        printf("1. Inserir (push)\n");
        printf("2. Retirar (pop)\n");
        printf("3. Verificar se a pilha está vazia\n");
        printf("4. Exibir pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &valor);
                push(&pilha, valor);
                exibirPilha(pilha);
                break;
            case 2:
                pop(&pilha);
                exibirPilha(pilha);
                break;
            case 3:
                if (isEmpty(pilha)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;
            case 4:
                exibirPilha(pilha);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    // Liberar a memória alocada para a pilha
    while (!isEmpty(pilha)) {
        pop(&pilha);
    }

    return 0;
}
