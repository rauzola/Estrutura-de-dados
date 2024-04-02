#include <stdio.h>

void troca(int *x, int *y)
{
    int aux;

    if (*y > *x)
    {
        aux = *x;
        *x = *y;
        *y = aux;
    }
}

int main()
{
    int a;
    int b;

    printf("Digite o valor de A \n");
    scanf("%d", &a);

    printf("Digite o valor de B \n");
    scanf("%d", &b);

    troca(&a, &b);

    printf("O valor de A. = %d\n", a);
    printf("O valor de B. = %d\n", b);
    return 0;
}
