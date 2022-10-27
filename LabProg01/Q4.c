#include <stdio.h>

int main(void) {

    int valorReais, cem, cinquenta, vinte, dez, cinco, dois, um;

    printf("Digite o valor em reais: ");
    scanf("%d", &valorReais);

    cem = valorReais / 100;
    cinquenta = (valorReais % 100) / 50;
    vinte = ((valorReais % 100) % 50) / 20;
    dez = (((valorReais % 100) % 50) % 20) / 10;
    cinco = ((((valorReais % 100) % 50) % 20) % 10) / 5;
    dois = (((((valorReais % 100) % 50) % 20) % 10) % 5) / 2;
    um = (((((valorReais % 100) % 50) % 20) % 10) % 5) % 2;

    printf("Quantidade de notas de 100: %d. \n", cem);
    printf("Quantidade de notas de 50: %d. \n", cinquenta);
    printf("Quantidade de notas de 20: %d. \n", vinte);
    printf("Quantidade de notas de 10: %d. \n", dez);
    printf("Quantidade de notas de 5: %d. \n", cinco);
    printf("Quantidade de notas de 2: %d. \n", dois);
    printf("Quantidade de notas de 1: %d. \n", um);

    return 0;
}