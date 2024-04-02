#include <stdio.h>

int main() {
    float preco_combustivel = 5.24;
    float marcacao_inicial;
    float marcacao_final;
    float litros_combustivel;
    float valor_recebido;
    float quilometros_percorridos;
    float lucro_liquido;
    float media_consumo;

    // Solicita as informações do usuário
    printf("Digite a marcacao do odometro inicial (em Km)............: ");
    scanf("%f", &marcacao_inicial);

    printf("Digite a marcacao do odometro final (em Km)..............: ");
    scanf("%f", &marcacao_final);

    printf("Digite a quantidade de litros de combustivel gastos......: ");
    scanf("%f", &litros_combustivel);

    printf("Digite o valor total recebido dos passageiros............: ");
    scanf("%f", &valor_recebido);

    // Calcula a quantidade de quilometros percorridos no dia
    quilometros_percorridos = marcacao_final - marcacao_inicial;

    // Calcula o lucro liquido do dia
    lucro_liquido = valor_recebido - (litros_combustivel * preco_combustivel);

    // Calcula a media do consumo em Km/L
    media_consumo = quilometros_percorridos / litros_combustivel;

    // Apresenta os resultados
    printf("\nMarcacao do odometro inicial.............................: %.2f Km\n", marcacao_inicial);
    printf("Marcacao do odometro final...............................: %.2f Km\n", marcacao_final);
    printf("Quantidade de quilometros percorridos no dia.............: %.2f Km\n", quilometros_percorridos);
    printf("Lucro liquido do dia.....................................: R$ %.2f\n", lucro_liquido);
    printf("Media do consumo em Km/L.................................: %.2f Km/L\n", media_consumo);

    return 0;
}
