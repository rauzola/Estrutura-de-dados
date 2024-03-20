// escrever um programa em c que le o numero de um vendedor , o nome , o seu salario fixo, o total de vendas por ele efetuadas que ganha sobre o total  de vendas.
// calcular o salario total do vendedor.
// Escrever numero do vendedor , o nome e o salario total.
// fazer em ligunagem C, usar somente ponteiro e malloc

#include <stdio.h>
#include <stdlib.h>

// Função para calcular o salário total de um vendedor
double calcularSalarioTotal(int *id, char *nome, double *salarioFixo, double *vendasTotais) {
    // Assumindo que a taxa de comissão é de 10% sobre as vendas totais
    double comissao = 0.10 * (*vendasTotais); // Calcula a comissão
    return (*salarioFixo) + comissao; // Retorna o salário total somando o salário fixo com a comissão
}

int main() {
    int *id = (int *)malloc(sizeof(int)); // Aloca memória dinamicamente para o ID do vendedor
    char *nome = (char *)malloc(50 * sizeof(char)); // Aloca memória dinamicamente para o nome do vendedor
    double *salarioFixo = (double *)malloc(sizeof(double)); // Aloca memória dinamicamente para o salário fixo
    double *vendasTotais = (double *)malloc(sizeof(double)); // Aloca memória dinamicamente para o total de vendas

    printf("Informe o ID do vendedor: ");
    scanf("%d", id);

    printf("Informe o nome do vendedor: ");
    scanf("%s", nome);

    printf("Informe o salario fixo: ");
    scanf("%lf", salarioFixo);

    printf("Informe o total de vendas: ");
    scanf("%lf", vendasTotais);

    double salarioTotal = calcularSalarioTotal(id, nome, salarioFixo, vendasTotais);

    printf("\nID do vendedor: %d\n", *id);
    printf("Nome do vendedor: %s\n", nome);
    printf("Salario Total: %.2lf\n", salarioTotal);

    free(id); // Libera a memória alocada para o ID
    free(nome); // Libera a memória alocada para o nome
    free(salarioFixo); // Libera a memória alocada para o salário fixo
    free(vendasTotais); // Libera a memória alocada para o total de vendas

    return 0;
}
