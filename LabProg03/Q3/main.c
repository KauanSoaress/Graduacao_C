#include <stdio.h>

int preencherVetor(int tam, float *vet) {
    for (int i = 0; i < tam; i++) {
        float elemento;
        printf("Digite o tempo da %d volta: ", (i + 1));
        scanf("%f", &elemento);
        vet[i] = elemento;
    }
    return 0;
}

void melhorTempo(int tam, float *vet) {
    float melhor_tempo = vet[0];

    for (int i = 0; i < tam; i++) {
        if (vet[i] < melhor_tempo) {
            melhor_tempo = vet[i];
        }
    }
    printf("O melhor tempo foi: %.2f\n", melhor_tempo);
}

void piorTempo(int tam, float *vet) {
    float pior_tempo = vet[0];

    for (int i = 0; i < tam; i++) {
        if (vet[i] > pior_tempo) {
            pior_tempo = vet[i];
        }
    }
    printf("O pior tempo foi: %.2f\n", pior_tempo);
}

void voltaMelhorTempo(int tam, float *vet) {
    int volta_melhor_tempo = 1;
    float melhor_tempo = vet[0];

    for (int i = 0; i < tam; i++) {
        if (vet[i] < melhor_tempo) {
            volta_melhor_tempo = i + 1;
        }
    }
    printf("Volta do melhor tempo: %d\n", volta_melhor_tempo);
}

void voltaPiorTempo(int tam, float *vet) {
    int volta_pior_tempo = 1;
    float pior_tempo = vet[0];

    for (int i = 0; i < tam; i++) {
        if (vet[i] > pior_tempo) {
            volta_pior_tempo = i + 1;
        }
    }
    printf("Volta do pior tempo: %d\n", volta_pior_tempo);
}

void mediaTempos(int tam, float *vet) {
    float soma_tempos = 0, media;

    for (int i = 0; i < tam; i++) {
        soma_tempos += vet[i];
    }

    media = soma_tempos/tam;

    printf("O tempo medio das %d voltas e: %.2f\n", tam, media);
}

int main(void) {
    int quantVoltas;

    printf("Digite a quantidade de voltas do piloto: ");
    scanf("%d", &quantVoltas);

    float *voltas = (float*) malloc(quantVoltas * sizeof(float));

    preencherVetor(quantVoltas, voltas);

    melhorTempo(quantVoltas, voltas);
    voltaMelhorTempo(quantVoltas, voltas);
    piorTempo(quantVoltas, voltas);
    voltaPiorTempo(quantVoltas, voltas);
    mediaTempos(quantVoltas, voltas);

    return 0;
}
