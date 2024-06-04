/*
** Função : Sistema de Agendamento de Consultas
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/

#define MAX_MEDICO 5

typedef struct {
    char nome[100];
    char data[20];
} Consulta;

typedef struct {
    Consulta consultas[MAX_MEDICO];
    int inicio;
    int fim;
    int tamanho;
} FilaMedico;

typedef struct No {
    Consulta consulta;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} FilaEnfermagem;

void inicializaFilaMedico(FilaMedico* fila);
int agendarConsultaMedico(FilaMedico* fila, Consulta consulta);
Consulta cancelarConsultaMedico(FilaMedico* fila);

void inicializaFilaEnfermagem(FilaEnfermagem* fila);
void agendarConsultaEnfermagem(FilaEnfermagem* fila, Consulta consulta);
Consulta cancelarConsultaEnfermagem(FilaEnfermagem* fila);