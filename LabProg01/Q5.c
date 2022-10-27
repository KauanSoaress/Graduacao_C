#include <stdio.h>

int MaiorNum (int a, int b, int c);
void OrdenarMaiorMenor (int a, int b, int c, int maiorNum);

int main(void) {
    int a, b, c, maiorNum;
    printf("Digite 3 numeros: \n");
    scanf("%d %d %d", &a, &b, &c);

    maiorNum = MaiorNum(a, b, c);

    printf("O maior numero e: %d\n", maiorNum);
    OrdenarMaiorMenor(a, b, c, maiorNum);

    return 0;
}

int MaiorNum (int a, int b, int c) {
    int maiorNum;

    if (a >= b && a >= c) {
        maiorNum = a;
    } else if (b >= a && b >= c) {
        maiorNum = b;
    } else if (c >= a && c >= b) {
        maiorNum = c;
    }

    return maiorNum;
}

void OrdenarMaiorMenor (int a, int b, int c, int maiorNum) {
    if (maiorNum == a) {
        if (b >= c) {
            printf ("%d > %d > %d", a, b, c);
        } else if (c >= b) {
            printf ("%d > %d > %d", a, c, b);
        }
    } else if (maiorNum == b) {
        if (a >= c) {
            printf ("%d > %d > %d", b, a, c);
        } else if (c >= a) {
            printf ("%d > %d > %d", b, c, a);
        }
    } else if (maiorNum == c) {
        if (a >= b) {
            printf ("%d > %d > %d", c, a, b);
        } else if (b >= a) {
            printf ("%d > %d > %d", c, b, a);
        }
    }
}