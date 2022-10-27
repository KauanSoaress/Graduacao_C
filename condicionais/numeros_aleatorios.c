#include <stdio.h>  // biblioteca para ler valores do teclado e para exibir valores no monitor
#include <stdlib.h> // biblioteca para alocar memória, gerar números aleatórios, converter variáveis, etc...
#include <time.h>

void main () {
    // parte responsável por alimentar o rand de forma diferente
    srand((unsigned) time(NULL));

    // variavel que recebe o resto da divisao do numero por 3 (aleatorio entre 0 e 2)
    int aleatorio = rand() % 3;

    // variavel que recebe o resto da divisao do numero por 5 (aleatorio entre 1 e 5)
    int aleatorioSegundo = (rand() % 5) + 1;

    //imprime o valor
    printf("\n%d", aleatorio);
    printf("\n%d", aleatorioSegundo);
}