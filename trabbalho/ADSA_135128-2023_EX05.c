/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Crie um programa que contenha um array de inteiros contendo 5 elementos.
   Utilizando apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.
*/

#include <stdio.h>

int main() {
    int array[5]; // Array de inteiros com 5 elementos
    int *ptr = array; // Ponteiro para o primeiro elemento do array

    // Lendo os valores do array do teclado
    printf("Digite os valores do array:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i); // Utilizando aritmética de ponteiros para acessar os elementos do array
    }

    // Imprimindo o dobro de cada valor lido
    printf("O dobro dos valores lidos:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i) * 2); // Utilizando aritmética de ponteiros para acessar os elementos do array e imprimir o dobro
    }
    printf("\n");

    return 0;
}
