#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double delta(double a, double b, double c);
int raizes(double a, double b, double c, double *px1, double *px2);

int main (void) {
    double a, b, c, valorDelta, *x1, *x2;
    printf ("Insira os valores de a, b e c, respectivamente: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
 
    if (a != 0) {
        valorDelta = delta(a, b, c);

        printf("Valor de delta: %.2lf\n", valorDelta);

        raizes(a, b, c, x1, x2);

        if (valorDelta > 0) {
            printf("Existem 2 raizes reais: %.2lf e %.2lf\n", *x1, *x2);
        } else if (valorDelta == 0) {
            printf("So existe 1 raiz real: %.2lf\n", *x1);
        }
    } else {
        printf("O coeficiente a teria que ser diferente de 0.");
    }

    return 0;
}

double delta(double a, double b, double c) {
    double delta;
    delta = (b * b) - (4 * a * c);

    return delta;
}

int raizes(double a, double b, double c, double *px1, double *px2) {
    double valorDelta;
    valorDelta = delta(a, b, c);
    printf("aaaaaaaaaaaaaaaaaa%lf", valorDelta);
    if (valorDelta == 0) {
        *px1 = *px2 = -b/(2*a);
    } else if (valorDelta > 0) {
        *px1 = (-b - sqrt(valorDelta)) / (2 * a);
        *px2 = (-b + sqrt(valorDelta)) / (2 * a);
    } else {
        printf("Nao existem raizes reais.\n");
    }
  return 0;
}
