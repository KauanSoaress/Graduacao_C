#include <stdio.h>
#include <math.h>

int main(void) {
    float raio, angA, x, y;

    printf("Digite o raio: ");
    scanf("%f", &raio);

    printf("Digite o angulo A: ");
    scanf("%f", &angA);

    x = raio * cos(angA);
    y = raio * sin(angA);

    printf("abscissa %f e ordenada %f", x, y);

    return 0;
}