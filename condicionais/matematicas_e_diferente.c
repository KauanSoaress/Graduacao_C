#include <stdio.h>  // biblioteca para ler valores do teclado e para exibir valores no monitor
#include <stdlib.h> // biblioteca para alocar memória, gerar números aleatórios, converter variáveis, etc...

void main () {
    int a = 5, b = 10, c = 15;
    char d = 'x';

    // maior
    if (a > 2) {
        printf("\n%d e maior que 2.", a);
    }

    // maior ou igual
    if (c >= b) {
        printf("\n%d maior ou igual a %d.", c, b);
    }

    // menor 
    if (a < 10) {
        printf("\n%d e menor que 10.", a);
    }

    // menor ou igual
    if (a <= 10) {
        printf("\n%d e menor ou igual a 10.", a);
    }

    // diferente
    if (c != 10) {
        printf("\n%d nao e 10.", c);
    }

    if (d != 'a') {
        printf("\n%c nao e a", d);
    }
}