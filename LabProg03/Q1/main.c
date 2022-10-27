#include <stdio.h>

int preencherVetor(int tam, int *vet) {
    for (int i = 0; i < tam; i++) {
        int elemento;
        printf("Digite o valor na posicao %d do vetor: ", (i + 1));
        scanf("%d", &elemento);
        vet[i] = elemento;
    }

    return 0;
}

int main(void) {
  int tam1, tam2;

  printf("-- PREENCHER VETOR 1 --\n");
  printf("Digite o tamanho do vetor 1: ");
  scanf("%d", &tam1);
  int vet1[tam1];
  preencherVetor(tam1, vet1);

  printf("-- PREENCHER VETOR 2 --\n");
  printf("Digite o tamanho do vetor 2: ");
  scanf("%d", &tam2);
  int vet2[tam2];
  preencherVetor(tam2, vet2);

  printf("Valores iguais: \n");

  if (tam1 >= tam2) {
    for (int i = 0; i < tam1; i++) {
      for (int j = 0; j < tam2; j++) {
        if (vet1[i] == vet2[j]) {
          printf("%d\n", vet1[i]);
        }
      }
    }
  } else {
    for (int i = 0; i < tam2; i++) {
      for (int j = 0; j < tam1; j++) {
        if (vet2[i] == vet1[j]) {
          printf("%d\n", vet2[i]);
        }
      }
    }
  }

  return 0;
}
