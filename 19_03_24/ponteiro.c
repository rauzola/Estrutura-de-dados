#include <stdio.h>

int main() {
    int *p;

    p = (int*) malloc (sizeof(int));

    printf("Digite um valor...: ")/
    scanf("%d", p);

    printf("O Endereço e &p = %d\n", &p);
    printf("O Valor digitado foi *p=: %d\n", *p);
    printf("O Valor esta no endereco p.: %d\n", p);
}