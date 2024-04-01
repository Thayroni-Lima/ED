/*
** Função : Soma de Fatoriais Inversos
** Autor : Thayroni Lima (3ºP CC noturno)
** Data : 01/04/2024
** Observações: none
*/

#include <stdio.h>
#include<math.h>
#include <stdio.h>

float fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        double fat = 1.0;
        for (int i = 2; i <= n; i++) {
            fat *= i;
        }
        return fat;
    }
}

float soma_fatoriais_inversos(int n) {
    float soma = 0.0;
    for (int i = 1; i <= n; i++) {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

int main() {
    int n;
    printf("Digite um número inteiro positivo n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    double resultado = soma_fatoriais_inversos(n);
    printf("A soma dos fatoriais inversos de 1 a %d é: %.6f\n", n, resultado);

    return 0;
}
