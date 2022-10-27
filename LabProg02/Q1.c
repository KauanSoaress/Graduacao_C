#include <stdio.h>

int MDC (int x, int y);

int main(void) {
    int x, y;

    printf("Digite dois numeros: \n");
    scanf("%d %d", &x, &y);

    printf("O mdc de %d e %d eh: %d", x, y, MDC(x, y));

    return 0;
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