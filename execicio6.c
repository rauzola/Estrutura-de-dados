#include <stdio.h>

int main() {
    int num_empregados;
    int num_bicicletas_vendidas;
    float salario_minimo;
    float preco_custo_bicicleta;
    float salario_vendedor;
    float comissao_por_bicicleta;
    float comissao_total;
    float comissao_por_empregado;
    float salario_final_empregado;
    float preco_venda_bicicleta;
    float lucro_bruto;
    float lucro_liquido;

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
    salario_vendedor = 2 * salario_minimo;
    comissao_por_bicicleta = preco_custo_bicicleta * 0.15;
    comissao_total = comissao_por_bicicleta * num_bicicletas_vendidas;
    comissao_por_empregado = comissao_total / num_empregados;
    salario_final_empregado = salario_vendedor + comissao_por_empregado;

    // Calcula o lucro líquido da loja
    preco_venda_bicicleta = preco_custo_bicicleta * 1.5;
    lucro_bruto = (preco_venda_bicicleta * num_bicicletas_vendidas) -(preco_custo_bicicleta * num_bicicletas_vendidas);
    lucro_liquido = lucro_bruto - (num_empregados * salario_vendedor) - comissao_total;

    // Apresenta os resultados
    printf("\nSalario final de cada empregado: R$ %.2f\n", salario_final_empregado);
    printf("Lucro liquido da loja: R$ %.2f\n", lucro_liquido);

    return 0;
}
