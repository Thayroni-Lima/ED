/*
** Função : Números de Armstrong
** Autor : Thayroni Lima (3ºP CC noturno)
** Data : 01/04/2024
** Observações: none
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int contar_digitos(int n) {
    int contagem = 0;
    while (n != 0) {
        n /= 10;
        contagem++;
    }
    return contagem;
}

bool eh_numero_armstrong(int n) {
    int num_digitos = contar_digitos(n);
    int soma = 0;
    int original = n;

    while (n != 0) {
        int digito = n % 10;
        soma += pow(digito, num_digitos);
        n /= 10;
    }

    return soma == original;
}

int main() {
    int num;

    printf("Digite um número inteiro positivo para verificar se é um número de Armstrong: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    if (eh_numero_armstrong(num)) {
        printf("%d é um número de Armstrong.\n", num);
    } else {
        printf("%d não é um número de Armstrong.\n", num);
    }

    return 0;
}