/*
** Função : Soma de Divisores Amigáveis
** Autor : Thayroni Lima (3ºP CC noturno)
** Data : 01/04/2024
** Observações: none
*/

#include <stdio.h>
#include<math.h>

int soma_divisores(int num) {
    int soma = 0;
    for (int i = 1; i < (num); i++) {
        if (num % i == 0) {
            soma += i;
        }
    }
    return soma;
}

void numeros_amigaveis(int a, int b) {
    int soma_a = soma_divisores(a);
    int soma_b = soma_divisores(b);

    printf("Divisores próprios de %d: ", a);
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", a, soma_a);

    printf("Divisores próprios de %d: ", b);
    for (int i = 1; i < b; i++) {
        if (b % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", b, soma_b);

    if (soma_a == b && soma_b == a) {
        printf("%d e %d são um par de números amigáveis.\n", a, b);
    } else {
        printf("%d e %d não são um par de números amigáveis.\n", a, b);
    }
}

int main() {
    int num1, num2;

    printf("Digite dois números inteiros positivos: ");
    scanf("%d %d", &num1, &num2);

    numeros_amigaveis(num1, num2);

    return 0;
}