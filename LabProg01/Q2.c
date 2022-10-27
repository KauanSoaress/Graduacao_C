#include <stdio.h>

int main(void) {
    float preco_galao_eua;
    float taxa_conversao_dolar_para_real;
    float preco_correspondente;
    float valor_litro_dol;

    printf("Digite o preco do galao de gasolina nos EUA: ");
    scanf("%f", &preco_galao_eua);

    printf("Digite a taxa de conversao do dolar para o real: ");
    scanf("%f", &taxa_conversao_dolar_para_real);

    valor_litro_dol = preco_galao_eua / 3.7854;

    preco_correspondente = valor_litro_dol * taxa_conversao_dolar_para_real;

    printf("O valor correspondendo ao litro de gasolina nos EUA eh: %.2f", preco_correspondente);
    
    return 0;
}