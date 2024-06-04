/*
** Função : Sistema de Agendamento de Consultas
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#include "ED-lista2-questao2.h"
#include <stdio.h>
#include <string.h>

void exibirMenu() {
    printf("\nSistema de Agendamento de Consultas\n");
    printf("1. Agendar consulta com Médico\n");
    printf("2. Agendar consulta com Enfermagem\n");
    printf("3. Cancelar consulta com Médico\n");
    printf("4. Cancelar consulta com Enfermagem\n");
    printf("5. Exibir consultas agendadas com Médico\n");
    printf("6. Exibir consultas agendadas com Enfermagem\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

void exibirConsultasMedico(FilaMedico* fila) {
    if (fila->tamanho == 0) {
        printf("Nenhuma consulta agendada com o Médico.\n");
        return;
    }
    printf("Consultas agendadas com o Médico:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        int idx = (fila->inicio + i) % MAX_MEDICO;
        printf("%d. %s - %s\n", i + 1, fila->consultas[idx].nome, fila->consultas[idx].data);
    }
}

void exibirConsultasEnfermagem(FilaEnfermagem* fila) {
    if (fila->inicio == NULL) {
        printf("Nenhuma consulta agendada com a Enfermagem.\n");
        return;
    }
    printf("Consultas agendadas com a Enfermagem:\n");
    No* atual = fila->inicio;
    int i = 1;
    while (atual != NULL) {
        printf("%d. %s - %s\n", i, atual->consulta.nome, atual->consulta.data);
        atual = atual->proximo;
        i++;
    }
}

int main() {
    FilaMedico filaMedico;
    FilaEnfermagem filaEnfermagem;
    inicializaFilaMedico(&filaMedico);
    inicializaFilaEnfermagem(&filaEnfermagem);

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // consumir o '\n' deixado pelo scanf

        Consulta consulta;
        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                fgets(consulta.nome, 100, stdin);
                consulta.nome[strcspn(consulta.nome, "\n")] = '\0'; // remover o '\n' do final
                printf("Data da consulta (YYYY-MM-DD): ");
                fgets(consulta.data, 20, stdin);
                consulta.data[strcspn(consulta.data, "\n")] = '\0'; // remover o '\n' do final
                if (agendarConsultaMedico(&filaMedico, consulta) == 0) {
                    printf("Consulta agendada com sucesso.\n");
                }
                break;
            case 2:
                printf("Nome do paciente: ");
                fgets(consulta.nome, 100, stdin);
                consulta.nome[strcspn(consulta.nome, "\n")] = '\0'; // remover o '\n' do final
                printf("Data da consulta (YYYY-MM-DD): ");
                fgets(consulta.data, 20, stdin);
                consulta.data[strcspn(consulta.data, "\n")] = '\0'; // remover o '\n' do final
                agendarConsultaEnfermagem(&filaEnfermagem, consulta);
                printf("Consulta agendada com sucesso.\n");
                break;
            case 3:
                consulta = cancelarConsultaMedico(&filaMedico);
                if (strcmp(consulta.nome, "") != 0) {
                    printf("Consulta de %s na data %s foi cancelada.\n", consulta.nome, consulta.data);
                }
                break;
            case 4:
                consulta = cancelarConsultaEnfermagem(&filaEnfermagem);
                if (strcmp(consulta.nome, "") != 0) {
                    printf("Consulta de %s na data %s foi cancelada.\n", consulta.nome, consulta.data);
                }
                break;
            case 5:
                exibirConsultasMedico(&filaMedico);
                break;
            case 6:
                exibirConsultasEnfermagem(&filaEnfermagem);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
