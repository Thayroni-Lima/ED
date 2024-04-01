/*
** Função : Potências Fatoriais
** Autor : Thayroni Lima (3ºP CC noturno)
** Data : 01/04/2024
** Observações: none
*/

#include<stdio.h>
#include<math.h>


int potencia_fatorial_crescente(int x, int n){
    int soma = x;
    for (int i = 1; i < n; i++){
        soma = soma * (x + i);
        printf("\n%d", soma);
    }
    return soma;
};

int potencia_fatorial_decrescente(int x, int n){
    int soma = x;
    for (int i = 1; i < n; i++){
        soma = soma * (x - i);
        printf("\n%d", soma);
    }
    return soma;
}
    
int main (void){
    while (1<2){
        int decision = 0;

        printf("\nDigite 1 para Potência Fatorial CRESCENTE\nDigite 2 para Potência Fatorial DECRESCENTE:\n");
        scanf("%d", &decision);
        int x = 0;
        int n = 0;

        switch (decision){
            case 1:
                printf("Digite x:\n");
                scanf("%d", &x);

                printf("Digite n:\n");
                scanf("%d", &n);

                printf("\nO resultado é %d\n", potencia_fatorial_crescente(x,n));
                break;
            case 2:
                printf("Digite x:\n");
                scanf("%d", &x);

                printf("Digite n:\n");
                scanf("%d", &n);
                printf("\nO resultado é %d\n", potencia_fatorial_decrescente(x,n));
                break;
            default:
                printf("Erro de entrada");
                break;
        }
    }
    return 0;
    
};