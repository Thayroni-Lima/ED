/*
** Função : Lista de Compras
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct Node {
    char produto[100];
    int quantidade;
    struct Node* proximo;
} Node;

// Função para criar um novo nó
Node* criarNode(char produto[], int quantidade) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    strcpy(novoNode->produto, produto);
    novoNode->quantidade = quantidade;
    novoNode->proximo = NULL;
    return novoNode;
}

// Função para inserir um item na lista de compras
void inserirItem(Node** head, char produto[], int quantidade) {
    Node* novoNode = criarNode(produto, quantidade);
    novoNode->proximo = *head;
    *head = novoNode;
    printf("Item '%s' com quantidade %d inserido na lista.\n", produto, quantidade);
}

// Função para remover um item da lista de compras
void removerItem(Node** head, char produto[]) {
    Node* temp = *head;
    Node* anterior = NULL;

    // Se a lista estiver vazia
    if (temp == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Se o item a ser removido estiver no início da lista
    if (temp != NULL && strcmp(temp->produto, produto) == 0) {
        *head = temp->proximo;
        free(temp);
        printf("Item '%s' removido da lista.\n", produto);
        return;
    }

    // Procurar o item a ser removido
    while (temp != NULL && strcmp(temp->produto, produto) != 0) {
        anterior = temp;
        temp = temp->proximo;
    }

    // Se o item não for encontrado
    if (temp == NULL) {
        printf("Item '%s' não encontrado na lista.\n", produto);
        return;
    }

    // Desconectar o nó da lista encadeada
    anterior->proximo = temp->proximo;
    free(temp);
    printf("Item '%s' removido da lista.\n", produto);
}

// Função para consultar um item na lista de compras
void consultarItem(Node* head, char produto[]) {
    Node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->produto, produto) == 0) {
            printf("Item encontrado: '%s' com quantidade %d\n", produto, temp->quantidade);
            return;
        }
        temp = temp->proximo;
    }
    printf("Item '%s' não encontrado na lista.\n", produto);
}

// Função para mostrar todos os itens da lista de compras
void mostrarLista(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Lista de compras:\n");
    while (temp != NULL) {
        printf("Produto: '%s', Quantidade: %d\n", temp->produto, temp->quantidade);
        temp = temp->proximo;
    }
}

// Função principal
int main() {
    Node* head = NULL;
    int opcao, quantidade;
    char produto[100];

    do {
        printf("\nEscolha uma operação:\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Consultar item\n");
        printf("4. Mostrar lista de compras\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", produto);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                inserirItem(&head, produto, quantidade);
                break;
            case 2:
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", produto);
                removerItem(&head, produto);
                break;
            case 3:
                printf("Digite o nome do produto a ser consultado: ");
                scanf(" %[^\n]", produto);
                consultarItem(head, produto);
                break;
            case 4:
                mostrarLista(head);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    // Liberar a memória alocada para a lista antes de sair
    while (head != NULL) {
        Node* temp = head;
        head = head->proximo;
        free(temp);
    }

    return 0;
}
