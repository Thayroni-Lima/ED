/*
** Função : Lista Encadeada - Biblioteca
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de um livro
typedef struct Livro {
    char autor[50];
    char titulo[50];
    char editora[50];
    int ano;
    struct Livro* prox;
} Livro;

// Função para criar um novo nó de livro
Livro* criarLivro(char* autor, char* titulo, char* editora, int ano) {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->editora, editora);
    novoLivro->ano = ano;
    novoLivro->prox = NULL;
    return novoLivro;
}

// Função para inserir um livro de forma ordenada na lista
void inserirLivro(Livro** head, char* autor, char* titulo, char* editora, int ano) {
    Livro* novoLivro = criarLivro(autor, titulo, editora, ano);
    if (*head == NULL || strcmp((*head)->titulo, titulo) > 0) {
        novoLivro->prox = *head;
        *head = novoLivro;
    } else {
        Livro* atual = *head;
        while (atual->prox != NULL && strcmp(atual->prox->titulo, titulo) < 0) {
            atual = atual->prox;
        }
        novoLivro->prox = atual->prox;
        atual->prox = novoLivro;
    }
}

// Função para remover um livro pelo título
void removerLivro(Livro** head, char* titulo) {
    Livro* atual = *head;
    Livro* anterior = NULL;

    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    
    free(atual);
    printf("Livro removido com sucesso.\n");
}

// Função para alterar as informações de um livro pelo título
void alterarLivro(Livro* head, char* titulo) {
    Livro* atual = head;

    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Digite o novo autor: ");
    scanf(" %[^\n]", atual->autor);
    printf("Digite o novo título: ");
    scanf(" %[^\n]", atual->titulo);
    printf("Digite a nova editora: ");
    scanf(" %[^\n]", atual->editora);
    printf("Digite o novo ano: ");
    scanf("%d", &atual->ano);
    printf("Livro alterado com sucesso.\n");
}

// Função para buscar um livro pelo título
void buscarPorTitulo(Livro* head, char* titulo) {
    Livro* atual = head;

    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            printf("Autor: %s\n", atual->autor);
            printf("Título: %s\n", atual->titulo);
            printf("Editora: %s\n", atual->editora);
            printf("Ano: %d\n", atual->ano);
            return;
        }
        atual = atual->prox;
    }
    printf("Livro não encontrado.\n");
}

// Função para buscar livros pelo autor
void buscarPorAutor(Livro* head, char* autor) {
    Livro* atual = head;
    int encontrado = 0;

    while (atual != NULL) {
        if (strcmp(atual->autor, autor) == 0) {
            printf("Autor: %s\n", atual->autor);
            printf("Título: %s\n", atual->titulo);
            printf("Editora: %s\n", atual->editora);
            printf("Ano: %d\n", atual->ano);
            encontrado = 1;
        }
        atual = atual->prox;
    }
    if (!encontrado) {
        printf("Nenhum livro encontrado para o autor.\n");
    }
}

// Função para imprimir todos os livros
void imprimirLivros(Livro* head) {
    Livro* atual = head;
    while (atual != NULL) {
        printf("Autor: %s\n", atual->autor);
        printf("Título: %s\n", atual->titulo);
        printf("Editora: %s\n", atual->editora);
        printf("Ano: %d\n", atual->ano);
        printf("\n");
        atual = atual->prox;
    }
}

// Função para liberar a memória da lista
void liberarLista(Livro* head) {
    Livro* atual = head;
    Livro* prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main() {
    Livro* lista = NULL;
    int opcao;
    char autor[50], titulo[50], editora[50];
    int ano;

    do {
        printf("\nBiblioteca\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Alterar livro\n");
        printf("4. Buscar por título\n");
        printf("5. Buscar por autor\n");
        printf("6. Listar todos os livros\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        switch (opcao) {
            case 1:
                printf("Digite o autor: ");
                scanf(" %[^\n]", autor);
                printf("Digite o título: ");
                scanf(" %[^\n]", titulo);
                printf("Digite a editora: ");
                scanf(" %[^\n]", editora);
                printf("Digite o ano: ");
                scanf("%d", &ano);
                inserirLivro(&lista, autor, titulo, editora, ano);
                break;
            case 2:
                printf("Digite o título do livro a ser removido: ");
                scanf(" %[^\n]", titulo);
                removerLivro(&lista, titulo);
                break;
            case 3:
                printf("Digite o título do livro a ser alterado: ");
                scanf(" %[^\n]", titulo);
                alterarLivro(lista, titulo);
                break;
            case 4:
                printf("Digite o título do livro a ser buscado: ");
                scanf(" %[^\n]", titulo);
                buscarPorTitulo(lista, titulo);
                break;
            case 5:
                printf("Digite o autor a ser buscado: ");
                scanf(" %[^\n]", autor);
                buscarPorAutor(lista, autor);
                break;
            case 6:
                imprimirLivros(lista);
                break;
            case 7:
                liberarLista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}
