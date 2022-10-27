#include <stdio.h>

void FicouAF(float nota1, float nota2);

int main(void) {
    float nota1, nota2, mediaParcial;

    printf("Digite suas notas, nas 2 primeiras provas: \n");
    scanf("%f %f", &nota1, &nota2);

    mediaParcial = (nota1 + nota2) / 2;

    if (mediaParcial >= 5) {
        if (nota1 >= 3 && nota2 >= 3) {
            printf("Parabens, voce passou direto!!");
        } else {
            FicouAF (nota1, nota2);
        }
    } else {
        FicouAF (nota1, nota2);
    }

    return 0;
}

void FicouAF (float nota1, float nota2) {
    float nota3, notaMaior, mediaFinal;

    if (nota1 >= nota2) {
        notaMaior = nota1;
    } else {
        notaMaior = nota2;
    }

    printf("Voce nao conseguiu passar direto :( \n");

    printf("Digite sua nota na terceira prova: ");
    scanf("%f", &nota3);

    mediaFinal = (notaMaior + nota3) / 2;

    if (mediaFinal >= 5) {
        printf("Voce foi aprovado");
    } else {
        printf("Voce foi reprovado");
    }
}