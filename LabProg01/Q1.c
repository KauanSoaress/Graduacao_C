#include <stdio.h>
#include <math.h>

int main(void) {
    float raio;
    printf("Digite o valor do raio da esfera: ");
    scanf("%f", &raio);

    float volume = (4/3) * (3.14 * pow(raio,3));

    printf("O volume da esfera de raio %.2f eh %.2f.", raio, volume);

    return 0;
}