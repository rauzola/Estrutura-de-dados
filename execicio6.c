#include <stdio.h>

int main() {
    int num_empregados, num_bicicletas_vendidas;
    float salario_minimo, preco_custo_bicicleta;

    // Solicita as informações do usuário
    printf("Digite o numero de empregados da loja: ");
    scanf("%d", &num_empregados);

    printf("Digite o valor do salario minimo: ");
    scanf("%f", &salario_minimo);

    printf("Digite o preco de custo de cada bicicleta: ");
    scanf("%f", &preco_custo_bicicleta);

    printf("Digite o numero de bicicletas vendidas: ");
    scanf("%d", &num_bicicletas_vendidas);

    // Calcula o salário final de cada empregado
    float salario_vendedor = 2 * salario_minimo;
    float comissao_por_bicicleta = preco_custo_bicicleta * 0.15;
    float comissao_total = comissao_por_bicicleta * num_bicicletas_vendidas;
    float comissao_por_empregado = comissao_total / num_empregados;
    float salario_final_empregado = salario_vendedor + comissao_por_empregado;

    // Calcula o lucro líquido da loja
    float preco_venda_bicicleta = preco_custo_bicicleta * 1.5;
    float lucro_bruto = preco_venda_bicicleta * num_bicicletas_vendidas;
    float lucro_liquido = lucro_bruto - (num_empregados * salario_vendedor) - comissao_total;

    // Apresenta os resultados
    printf("\nSalario final de cada empregado: R$ %.2f\n", salario_final_empregado);
    printf("Lucro liquido da loja: R$ %.2f\n", lucro_liquido);

    return 0;
}
