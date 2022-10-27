#include <stdio.h>

int preencherVetor(int *vet) {
    for (int i = 0; i < 10; i++) {
        int elemento;
        printf("Digite o valor na posicao %d do vetor: ", (i + 1));
        scanf("%d", &elemento);
        vet[i] = elemento;
    }

    return 0;
}

void retornarMaior (int *vet) {
  int maior = vet[0];
  for (int i = 1; i < 10; i++) {
    if (vet[i] > maior) {
      maior = vet[i];
    }
  }
  printf("O maior valor do vetor eh: %d\n", maior);
}

void retornarMenor (int *vet) {
  int menor = vet[0];
  for (int i = 1; i < 10; i++) {
    if (vet[i] < menor) {
      menor = vet[i];
    }
  }
  printf("O menor valor do vetor eh: %d", menor);
}

int main(void) {
  int vet[10];
  preencherVetor(vet);

  retornarMaior(vet);
  retornarMenor(vet);
  return 0;
}
