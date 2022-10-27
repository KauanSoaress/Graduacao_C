#include <stdio.h>

int main(void) {

    int qtd_sec, qtd_horas, qtd_minutos, novo_qtd_sec;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &qtd_sec);

    qtd_horas = (qtd_sec / 3600);
    qtd_minutos = (qtd_sec % 3600) / 60;
    novo_qtd_sec = (qtd_sec % 3600) % 60;

    printf("%02d:%02d:%02d", qtd_horas, qtd_minutos, novo_qtd_sec);

    return 0;
}