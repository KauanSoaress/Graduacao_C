#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int tam, float *vet);
float calcularMedia(int tam, float *vet);
float calcularVariancia(int tam, float *vet, float media);

int main() {
    int tam_N;
    float media, variancia;

    printf("Digite a quantidade de valores desejada: ");
    scanf("%d", &tam_N);

    float *numbers = (float*) malloc(tam_N * sizeof(float));

    preencherVetor(tam_N, numbers);

    media = calcularMedia(tam_N, numbers);
    variancia = calcularVariancia(tam_N, numbers, media);

    printf("A media dos valores e: %.2f\n", media);
    printf("A variancia dos valores e: %.2f\n", variancia);

    return 0;
}

float calcularMedia(int tam, float *vet) {
    float soma_valores = 0, media;

    for (int i = 0; i < tam; i++) {
        soma_valores += vet[i];
    }

    media = soma_valores/tam;

    return media;
}

float calcularVariancia(int tam, float *vet, float media) {
    float soma_valores = 0, variancia;

    for (int i = 0; i < tam; i++) {
        soma_valores += pow((vet[i] - media), 2);
    }

    variancia = soma_valores/(tam - 1);

    return variancia;
}

void preencherVetor(int tam, float *vet) {
    for (int i = 0; i < tam; i++) {
        float elemento;
        printf("Digite o %d numero: ", (i + 1));
        scanf("%f", &elemento);
        vet[i] = elemento;
    }
}
