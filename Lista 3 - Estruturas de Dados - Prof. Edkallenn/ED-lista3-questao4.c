/*
** Função : Conjectura de Goldbach
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
    printf("Verificando a Conjectura de Goldbach para números pares entre 700 e 1100:\n");
    for (int n = 700; n <= 1100; n += 2) {
        verificarGoldbach(n);
    }
    return 0;
}
