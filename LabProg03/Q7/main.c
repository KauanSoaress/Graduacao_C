#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int tam, int *vet);
void calcularSequencia(int tam, int *seq1, int *seq2, int *seqResult);

int main()
{
    int num_alg;

    printf("Digite o tamanho das sequencias: ");
    scanf("%d", &num_alg);

    int *seq1 = (int*) malloc(num_alg * sizeof(int));
    int *seq2 = (int*) malloc(num_alg * sizeof(int));
    int *seqResult = (int*) malloc((num_alg + 1) * sizeof(int));

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    preencherVetor(num_alg, seq1);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    preencherVetor(num_alg, seq2);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    calcularSequencia(num_alg, seq1, seq2, seqResult);

    for (int i = 0; i < num_alg; i++) {
        printf("%d ", seq1[i]);
    }
    printf("\n");
    for (int i = 0; i < num_alg; i++) {
        printf("%d ", seq2[i]);
    }
    printf("\n");
    printf("----------------------------------");
    printf("\n");
    for (int i = 0; i < (num_alg + 1); i--) {
        printf("%d ", seqResult[i]);
    }

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

void calcularSequencia(int tam, int *seq1, int *seq2, int *seqResult) {
    int sobra = 0;
    int aux;

    for (int i = 0; i < tam; i++) {
        
        printf("%d\n", seqResult[i]);
    }
    printf("%d\n", sobra);
    // seqResult[tam+1] = sobra;
}