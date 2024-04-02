/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Elaborar um programa que leia dois valores inteiros (A e B).
    Em seguida faça uma função que retorne a soma do dobro dos dois números lidos.
    A função deverá armazenar o dobro de A na própria variável A e o dobro de B na própria variável B.
*/

#include <stdio.h>

// Função para calcular o dobro dos números e retornar a soma deles
int somaDobro(int *A, int *B) {
    // Armazenando o dobro de A em A
    *A = *A * 2;
    // Armazenando o dobro de B em B
    *B = *B * 2;
    // Retornando a soma dos valores
    return *A + *B;
}

int main() {
    int A, B;

    // Lendo os valores de A e B
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    // Chamando a função para calcular o dobro e retornar a soma
    int resultado = somaDobro(&A, &B);

    // Imprimindo o resultado
    printf("A soma do dobro de A e B: %d\n", resultado);

    // Imprimindo os valores modificados de A e B
    printf("Novo valor de A: %d\n", A);
    printf("Novo valor de B: %d\n", B);

    return 0;
}
