#include <stdio.h>  // biblioteca para ler valores do teclado e para exibir valores no monitor
#include <stdlib.h> // biblioteca para alocar memória, gerar números aleatórios, converter variáveis, etc...

void main () {
    int a = 4, opcao = 3;
    float b = 2.5;
    char c = 'x';

    // Condicional simples
    if (a == 5){
        printf("\nA variavel a = 5.");
    } 

    if (b == 2.5) {
        printf("\nA variavel b = 2.5.");
    }

    if (c == 'x') {
        printf("\nA variavel c = x.");
    }

    // condicional composta
    if (opcao == 1) {
        printf("\nOpcao = 1");
    }
    else if (opcao == 2) {
        printf("\nOpcao = 2");
    }
    else {
        printf("\nOpcao nao e igual a 2 nem a 1.");
    }

    // Número par ou ímpar
    if (a % 2 == 0) {
        printf("\nO numero %d e par.", a);
    }
    else {
        printf("\nO numero %d e impar.", a);
    }

}