#include <stdio.h>

// Estrutura para armazenar informações do funcionário
struct Funcionario
{
    char nome[50];
    int idade;
    char cargo[50];
    float salario_bruto;
};

int main()
{
    // Declaração do funcionário e outras variáveis
    struct Funcionario funcionario;
    float salario_bruto_corrigido;
    float gratificacao;
    float desconto_ir;
    float salario_liquido;

    // Solicitando informações do usuário
    printf("Digite o nome do funcionario...........: ");
    scanf("%s", funcionario.nome);

    printf("Digite a idade do funcionario..........: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o cargo do funcionario..........: ");
    scanf("%s", funcionario.cargo);

    printf("Digite o salario bruto do funcionario..: ");
    scanf("%f", &funcionario.salario_bruto);

    // Calculando o salário bruto corrigido (com reajuste de 38%)
    salario_bruto_corrigido = funcionario.salario_bruto * 1.38;

    // Calculando a gratificação (20% do salário bruto corrigido)
    gratificacao = salario_bruto_corrigido * 0.20;

    // Calculando o desconto de imposto de renda (15% do salário bruto corrigido)
    desconto_ir = salario_bruto_corrigido * 0.15;

    // Calculando o salário líquido
    salario_liquido = salario_bruto_corrigido - desconto_ir;

    // Imprimindo as informações
    printf("Nome...................................: %s\n", funcionario.nome);
    printf("Idade..................................: %d\n", funcionario.idade);
    printf("Cargo..................................: %s\n", funcionario.cargo);
    printf("Salario bruto anterior.................: %.2f\n", funcionario.salario_bruto);
    printf("Salario bruto corrigido................: %.2f\n", salario_bruto_corrigido);
    printf("Valor da gratificacao..................: %.2f\n", gratificacao);
    printf("Valor do desconto (Imposto de Renda)...: %.2f\n", desconto_ir);
    printf("Salario liquido........................: %.2f\n", salario_liquido);

    return 0;
}
