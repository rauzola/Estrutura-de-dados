#include <stdio.h>

int main() {
    float litros_combustivel;
    float km_percorridos;
    float custo_litro_combustivel;
    float total_gasto_combustivel;
    float consumo_medio;

    // Solicita ao usuário as entradas necessárias
    printf("Digite os litros de combustivel gastos....: ");
    scanf("%f", &litros_combustivel);

    printf("Digite os quilometros percorridos.........: ");
    scanf("%f", &km_percorridos);

    // Considerando que um litro custa R$ 5,24
    custo_litro_combustivel = 5.24;

    // Calcula o total gasto de combustível em Reais
    total_gasto_combustivel = litros_combustivel * custo_litro_combustivel;

    // Calcula o consumo médio de combustível
    consumo_medio = km_percorridos / litros_combustivel;

    // Exibe os resultados
    printf("\nLitros de Combustivel Gasto...............: %.2f\n", litros_combustivel);
    printf("Total de Quilometros Percorridos..........: %.2f\n", km_percorridos);
    printf("Total gasto de combustivel em Real........: R$ %.2f\n", total_gasto_combustivel);
    printf("Consumo Medio de Combustivel..............: %.2f km/l\n", consumo_medio);

    return 0;
}
