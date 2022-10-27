#include <stdio.h>  // biblioteca para ler valores do teclado e para exibir valores no monitor
#include <stdlib.h> // biblioteca para alocar memória, gerar números aleatórios, converter variáveis, etc...

void main () {
    int a = 10;

    // conectivo lógico E (AND)
    if (a > 5 && a < 15) {
        printf("\nA variavel a esta entre 5 e 15.");
    }

    // conectivo lógico OU (OR)
    if (a > 5 || a > 15) {
        printf("\nA variavel e maior que 5 ou 15.");
    }

    // misturando conectivos

    if ((a > 5 && a <15) || a == 20) {
        printf("\nA variavel 'a' esta entre 5 e 15 ou ela vale 20");
    }

}