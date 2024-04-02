/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Faca um programa que leia dois valores inteiros e chame uma função
   que receba estes 2  valores  de  entrada  e  retorne  o  maior  valor  na  
   primeira  variável  e  o  menor  valor  na segunda variável. Escreva o conteúdo das 2 variáveis na tela.
*/

#include <stdio.h>

// Função para encontrar o maior e o menor valor entre dois inteiros
void encontrarMaiorMenor(int *a, int *b) {
    int temp;

    // Verifica se a segunda variável é maior que a primeira
    if (*b > *a) {
        // Troca os valores das variáveis usando uma variável temporária
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int var1, var2;

    // Lendo os valores do teclado
    printf("Digite o valor da var1: ");
    scanf("%d", &var1);

    printf("Digite o valor da var2: ");
    scanf("%d", &var2);

    // Chamando a função para encontrar o maior e o menor valor
    encontrarMaiorMenor(&var1, &var2);

    // Exibindo os valores encontrados
    printf("Maior valor: %d\n", var1);
    printf("Menor valor: %d\n", var2);

    return 0;
}
