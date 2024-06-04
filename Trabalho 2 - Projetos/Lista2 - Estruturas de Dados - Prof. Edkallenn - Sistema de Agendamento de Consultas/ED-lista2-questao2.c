/*
** Função : Sistema de Agendamento de Consultas
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include "ED-lista2-questao2.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializaFilaMedico(FilaMedico* fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

int agendarConsultaMedico(FilaMedico* fila, Consulta consulta) {
    if (fila->tamanho == MAX_MEDICO) {
        printf("Limite de consultas para o médico atingido.\n");
        return -1;
    }
    fila->consultas[fila->fim] = consulta;
    fila->fim = (fila->fim + 1) % MAX_MEDICO;
    fila->tamanho++;
    return 0;
}

Consulta cancelarConsultaMedico(FilaMedico* fila) {
    Consulta consultaVazia = {"", ""};
    if (fila->tamanho == 0) {
        printf("Nenhuma consulta para cancelar.\n");
        return consultaVazia;
    }
    Consulta consulta = fila->consultas[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_MEDICO;
    fila->tamanho--;
    return consulta;
}

void inicializaFilaEnfermagem(FilaEnfermagem* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void agendarConsultaEnfermagem(FilaEnfermagem* fila, Consulta consulta) {
    No* novo = (No*)malloc(sizeof(No));
    novo->consulta = consulta;
    novo->proximo = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
}

Consulta cancelarConsultaEnfermagem(FilaEnfermagem* fila) {
    Consulta consultaVazia = {"", ""};
    if (fila->inicio == NULL) {
        printf("Nenhuma consulta para cancelar.\n");
        return consultaVazia;
    }
    No* temp = fila->inicio;
    Consulta consulta = temp->consulta;
    fila->inicio = temp->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return consulta;
}
