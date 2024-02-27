#include <stdio.h>

int main() {
    char nome[50];
    int horas_trabalhadas, num_dependentes;
    float salario_bruto, salario_liquido, desconto_inss, desconto_ir;

    // Solicita as informações do usuário
    printf("Digite o nome do funcionario: ");
    scanf("%s", nome);
    
    printf("Digite o numero de horas trabalhadas: ");
    scanf("%d", &horas_trabalhadas);
    
    printf("Digite o numero de dependentes: ");
    scanf("%d", &num_dependentes);

    // Calcula o salário bruto
    salario_bruto = (horas_trabalhadas * 12) + (num_dependentes * 40);

    // Calcula os descontos de INSS e IR
    desconto_inss = salario_bruto * 0.085;
    desconto_ir = salario_bruto * 0.05;

    // Calcula o salário líquido
    salario_liquido = salario_bruto - desconto_inss - desconto_ir;

    // Apresenta os resultados
    printf("\nNome: %s\n", nome);
    printf("Salario bruto: R$ %.2f\n", salario_bruto);
    printf("Desconto INSS: R$ %.2f\n", desconto_inss);
    printf("Desconto IR: R$ %.2f\n", desconto_ir);
    printf("Salario liquido: R$ %.2f\n", salario_liquido);

    return 0;
}
