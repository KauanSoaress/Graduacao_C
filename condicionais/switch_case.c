#include <stdio.h>  // biblioteca para ler valores do teclado e para exibir valores no monitor
#include <stdlib.h> // biblioteca para alocar memória, gerar números aleatórios, converter variáveis, etc...

void main () {
    int a = 5;
    char b = 'x';

    switch (a) {
        case 1:
            printf("\nOpcao escolhida: 1");
            break;
        case 2:
            printf("\nOpcao escolhida: 2");
            break;
        case 3:
            printf("\nOpcao escolhida: 3");
            break;
        default:
            printf("\nOpcao invalida");
            break;
    }

    // switch com char
    switch (b) {
        case 'x':
            printf("\nA letra e x");
            break;
    }
}