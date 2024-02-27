#include <stdio.h>

// Estrutura para armazenar informações do funcionário
struct Funcionario {
    char nome[50];
    int idade;
    char cargo[50];
    float salario_bruto;
};

int main() {
    // Declaração do funcionário
    struct Funcionario funcionario;

    // Solicitando informações do usuário
    printf("Digite o nome do funcionario: \n");
    scanf("%s", funcionario.nome);
    printf("\n");
    
    printf("Digite a idade do funcionario: \n");
    scanf("%d", &funcionario.idade);
    printf("\n");
    
    printf("Digite o cargo do funcionario: \n");
    scanf("%s", funcionario.cargo);
    printf("\n");
    
    printf("Digite o salario bruto do funcionario: \n");
    scanf("%f", &funcionario.salario_bruto);
    printf("\n");

    // Calculando o salário bruto corrigido (com reajuste de 38%)
    float salario_bruto_corrigido = funcionario.salario_bruto * 1.38;

    // Calculando a gratificação (20% do salário bruto corrigido)
    float gratificacao = salario_bruto_corrigido * 0.20;

    // Calculando o desconto de imposto de renda (15% do salário bruto corrigido)
    float desconto_ir = salario_bruto_corrigido * 0.15;

    // Calculando o salário líquido
    float salario_liquido = salario_bruto_corrigido - desconto_ir;

    // Imprimindo as informações
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario bruto anterior: %.2f\n", funcionario.salario_bruto);
    printf("Salario bruto corrigido: %.2f\n", salario_bruto_corrigido);
    printf("Valor da gratificacao: %.2f\n", gratificacao);
    printf("Valor do desconto (Imposto de Renda): %.2f\n", desconto_ir);
    printf("Salario liquido: %.2f\n", salario_liquido);

    return 0;
}
