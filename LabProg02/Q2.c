#include <stdio.h>
#include <math.h>
#define N 100

void imprimirPrimos(int num);
int primo(int n);
void quantPrimosDesejada(int num);

int main(void) {
    int num, quantDesejada;

    // A
    printf("Digite o numero limite: ");
    scanf("%d", &num);
    imprimirPrimos(num);

    // B
    printf("\nDigite o a quantidade de primos desejada: ");
    scanf("%d", &quantDesejada);
    quantPrimosDesejada(quantDesejada);
 
    return 0;
}

void imprimirPrimos(int num) {
    int quantPrimos = 0;

    for (int i = 2; i < num; i++) {
        if(primo(i) == 1) {
            quantPrimos++;
        }
    }

    printf("Quantidade de primos ate %d: %d", num, quantPrimos);
}

int primo(int n) {
    if (n == 2) {
        return 1;
    } else if (n<2 || (n%2)== 0) {
        return 0;
    } else {
        int lim = (int) sqrt(n);
        for (int i=3; i<= lim; i+=2) {
            if (n% i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

void quantPrimosDesejada(int num) {
    int i = 0;
    int quantPrimos = 0;

    printf("QUantidade de primos até %d: \n", num);

    while (quantPrimos < num) {
        if(primo(i) == 1) {
            printf("%d \n", i);
            quantPrimos++;
        }
        i++;
    }
}
