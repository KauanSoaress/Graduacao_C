#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int tam, int *vet);
int calcularEscalar(int *vet1, int *vet2);

int main() {
    int *vet1 = (int*) malloc(10 * sizeof(int));
    int *vet2 = (int*) malloc(10 * sizeof(int));
    int escalar;

    preencherVetor(10, vet1);
    preencherVetor(10, vet2);

    escalar = calcularEscalar(vet1, vet2);

    printf("Produto escalar dos vetores: %d \n", escalar);

    return 0;
}

void preencherVetor(int tam, int *vet) {
    for (int i = 0; i < tam; i++) {
        float elemento;
        printf("Digite o %d numero: ", (i + 1));
        scanf("%f", &elemento);
        vet[i] = elemento;
    }
}

int calcularEscalar(int *vet1, int *vet2) {
    int escalar = 0;

    for (int i = 0; i < 10; i++) {
        escalar += vet1[i] * vet2[i];
    }

    return escalar;
}
