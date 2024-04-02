/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Faca um programa que leia 2 valores inteiros e chame uma função que 
   receba estas 2 variáveis e troque o seu conteúdo,  ou seja,  esta função e´  
   chamada passando duas variáveis A e B por exemplo e, após a execução da função, 
   A conterá  o valor de B e B terá o valor de A.
*/

#include <stdio.h>

// Função para trocar o conteúdo de duas variáveis
void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int var1, var2;

    // Lendo os valores do teclado
    printf("Digite o valor da var1: ");
    scanf("%d", &var1);

    printf("Digite o valor da var2: ");
    scanf("%d", &var2);

    // Chamando a função para trocar os valores
    trocarValores(&var1, &var2);

    // Exibindo os valores trocados
    printf("Valores trocados:\n");
    printf("var1: %d\n", var1);
    printf("var2: %d\n", var2);

    return 0;
}
