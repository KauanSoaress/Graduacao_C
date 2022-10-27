#include <stdio.h>

int MDC (int x, int y);
int MDC3(int x, int y, int z);

int main(void) {
    int x, y, z;

    printf("Digite tres numeros: \n");
    scanf("%d %d %d", &x, &y, &z);

    printf("O mdc de %d, %d e %d eh: %d", x, y, z, MDC3(x, y, z));

    return 0;
}

int MDC3(int x, int y, int z) {
    MDC(MDC(x, y), z);
}

int MDC (int x, int y) {
    int r, mdc;

    r = x % y;

    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    
    mdc = y;

    return mdc;
}