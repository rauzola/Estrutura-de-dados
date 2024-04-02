/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Crie  um  programa  que  contenha  uma  função  que  permita  passar  por  parâmetro  dois números inteiros A e B. 
   A função deverá  calcular a soma entre estes dois números e armazenar o resultado na variável A.
    Esta função não devera´ possuir retorno, mas devera´ modificar o valor do primeiro parâmetro. 
    Imprima os valores de A e B na função principal.
*/

#include <stdio.h>

// Função para calcular a soma entre dois números inteiros e armazenar o resultado em A
void calcularSoma(int *A, int B) {
    *A = *A + B;
}

int main() {
    int A = 5;
    int B = 10;

    // Imprimindo os valores de A e B antes da chamada da função
    printf("Valores antes da chamada da funcao:\n");
    printf("A: %d\n", A);
    printf("B: %d\n", B);

    // Chamando a função para calcular a soma e modificar o valor de A
    calcularSoma(&A, B);

    // Imprimindo os valores de A e B após a chamada da função
    printf("\nValores apos a chamada da funcao:\n");
    printf("A: %d\n", A);
    printf("B: %d\n", B);

    return 0;
}
