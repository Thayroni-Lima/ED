/*
** Função : Conjectura de Goldbach de 2 até N
** Autor : Thayroni Lima
** Data : 05/06/2024
** Observações: -
*/
#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Função para encontrar dois primos que somam ao número par dado
void verificarGoldbach(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (ehPrimo(i) && ehPrimo(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            return;
        }
    }
}

int main() {
    int N;

    // Solicita ao usuário para digitar o valor de N
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    // Verifica se o valor de N é maior que 2
    if (N <= 2) {
        printf("Por favor, insira um número maior que 2.\n");
        return 1;
    }

    // Percorre todos os números pares de 2 até N
    printf("Verificando a Conjectura de Goldbach para números pares de 2 até %d:\n", N);
    for (int n = 4; n <= N; n += 2) {
        verificarGoldbach(n);
    }

    return 0;
}
