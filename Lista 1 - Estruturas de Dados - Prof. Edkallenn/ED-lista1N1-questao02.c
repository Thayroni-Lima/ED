/*
** Função : Fatorial Duplo
** Autor : Thayroni Lima (3ºP CC noturno)
** Data : 01/04/2024
** Observações: none
*/

#include <stdio.h>
#include<math.h>

int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int fatorial_duplo (int n){
    int resultado = n;
    for (int i = (n-2); i > 0; i-= 2){
        resultado = resultado * (n - i);
        printf("\n%d", resultado);
    }
    return resultado;
}

int main() {
    int fatoriais[18];
    int fatoriais_duplos[18];
    int diferencas[18];

    for (int i = 2; i <= 20; ++i) {
        fatoriais[i - 2] = fatorial(i);
        fatoriais_duplos[i - 2] = fatorial_duplo(i);
    }

    for (int i = 2; i <= 20; ++i) {
        diferencas[i-2] = fatoriais[i-2] - fatoriais_duplos[i-2];
    }

    printf("---------------------------------------------------------------------\n");
    printf("| Número |   Fatorial Normal   |   Fatorial Duplo    |      Diferença       |\n");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 2; i <= 20; ++i) {
        printf("| %7d | %20d | %20d | %20d |\n", (i), fatoriais[i-2], fatoriais_duplos[i-2], diferencas[i-2]);
    }
    printf("-------------------------------------------------------------------------------\n");

    return 0;
}