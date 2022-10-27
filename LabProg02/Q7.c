#include <stdio.h>

double pot (double x, int k);


int main (void) {
    double x, k, potencia;

    printf("Digite o numero e a potencia desejados: \n");
    scanf("%lf %lf", &x, &k);

    potencia = pot(x, k);

    printf("%lf", potencia);

    return 0;
}

double pot(double x, int k) {
    double potencia;

    if ((k-1) > 0) {
        potencia = x * pot(x, (k-1));
    }

    return potencia;
}