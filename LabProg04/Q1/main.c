#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int tam, int *vet);
void adicionarMais(int tam, int tamAntigo, int *vet);

int main() {
    int quantElementos, quantAdicionada, decision = 1;

    printf("Digite a quantidade inicial de elementos do vetor: ");
    scanf("%d", &quantElementos);

    int *vetor = (int*) malloc(quantElementos * sizeof(int));

    preencherVetor(quantElementos, vetor);

    while (decision == 1) {
        printf("Voce deseja adicionar mais elementos? (1 - SIM / 0 - NAO) ");
        scanf("%d", &decision);
        if (decision == 1) {
            printf("Quantidade de elementos a ser adicionada: ");
            scanf("%d", &quantAdicionada);

            quantElementos += quantAdicionada;

            int quantResto = quantElementos - quantAdicionada;

            vetor = (int*) realloc(vetor, quantAdicionada * sizeof(int));

            if (vetor == NULL) {
                printf("Memoria insuficiente.\n");
                exit(1);
            }

            adicionarMais(quantElementos, quantResto, vetor);
        }
    }

    for (int i = 0; i < quantElementos; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}

void preencherVetor(int tam, int *vet) {
    for (int i = 0; i < tam; i++) {
        printf("Digite o elemento na posicao %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}

void adicionarMais(int tam, int tamAntigo, int *vet) {
    for (int i = tamAntigo; i < tam; i++) {
        printf("Digite o elemento na posicao %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}