// escrever um programa em c que le o numero de um vendedor , o nome , o seu salario fixo, o total de vendas por ele efetuadas que ganha sobre o total  de vendas.
// calcular o salario total do vendedor.
// Escrever numero do vendedor , o nome e o salario total.

#include <stdio.h>

int main()
{
    int *numero;
    float *salario, *total_vendas, *percentual, *salario_total;

    numero = (int *)malloc(sizeof(int));
    salario = (float *)malloc(sizeof(float));
    total_vendas = (float *)malloc(sizeof(float));
    percentual = (float *)malloc(sizeof(float));
    salario_total = (float *)malloc(sizeof(float));

    printf("Digite o Numero do Vendedor...:");
    scanf("%d", numero);

    printf("Digite o salario do Vendedor...:");
    scanf("%f", salario);

    printf("Digite o total vendas do Vendedor...:");
    scanf("%f", total_vendas);

    printf("Digite o percentual do Vendedor...:");
    scanf("%f", percentual);

    printf("Digite o salario total do Vendedor...:");
    scanf("%f", salario_total);

    return 0;
}