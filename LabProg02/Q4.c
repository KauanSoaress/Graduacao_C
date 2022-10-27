#include <stdio.h>
#define Pi 3.14

float area (float r) {
    float area; 
    area = 4 * Pi * (r * r);
    printf("A area eh: %.2f\n", area);
}

float volume (float r) {
    float volume; 
    volume = (4 * Pi * (r * r * r))/3;
    printf("A area eh: %.2f\n", volume);
}

int main (void) {
    float raio;
    printf("Digite o valor do raio da esfera: ");
    scanf("%f", &raio);
    area(raio);
    volume(raio);
}