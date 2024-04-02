/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Faça um programa que possua uma função para
   ler 2 notas e retorná-las por parâmetro (chamar uma função dedicada a ler 2 notas válidas e que devolver os 2 números lidos);
   calcular a média simples e a média ponderada e retorná-las por parâmetro, onde a segunda nota tem peso 2 médias ponderada = (n1 + n2 ∗ 2) / 3;
*/

#include <stdio.h>

// Função para ler duas notas válidas
void lerNotas(float *nota1, float *nota2) {
    printf("Digite a primeira nota: ");
    scanf("%f", nota1);

    // Verifica se a nota é válida
    while (*nota1 < 0 || *nota1 > 100) {
        printf("Nota invalida! Digite novamente: ");
        scanf("%f", nota1);
    }

    printf("Digite a segunda nota: ");
    scanf("%f", nota2);

    // Verifica se a nota é válida
    while (*nota2 < 0 || *nota2 > 100) {
        printf("Nota invalida! Digite novamente: ");
        scanf("%f", nota2);
    }
}

// Função para calcular media simples e media ponderada
void calcularMedias(float nota1, float nota2, float *mediaSimples, float *mediaPonderada) {
    *mediaSimples = (nota1 + nota2) / 2;
    *mediaPonderada = (nota1 + nota2 * 2) / 3;
}

int main() {
    float nota1; 
    float nota2;
    float mediaSimples;
    float mediaPonderada;

    // Declaração das variáveis
    nota1 = 0;
    nota2 = 0;
    mediaSimples = 0;
    mediaPonderada = 0;

    // Chama a função para ler as notas
    lerNotas(&nota1, &nota2);

    // Chama a função para calcular as medias
    calcularMedias(nota1, nota2, &mediaSimples, &mediaPonderada);

    // Exibe os resultados
    printf("Media simples: %.2f\n", mediaSimples);
    printf("Media ponderada: %.2f\n", mediaPonderada);

    return 0;
}
