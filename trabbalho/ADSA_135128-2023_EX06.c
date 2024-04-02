/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Faça um programa que leia três valores inteiros e chame uma função que 
   receba estes 3 valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável,
   o segundo menor valor na variável do meio, e o maior valor na última variável. A função deve retornar o valor 1 
   se os três valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.
*/

#include <stdio.h>

// Função para ordenar os valores e verificar se são iguais
int ordenarValores(int *a, int *b, int *c) {
    int temp;

    // Ordenando os valores em ordem crescente
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    // Verificando se os valores são iguais
    if (*a == *b && *b == *c) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num1, num2, num3;

    // Lendo os valores do usuário
    printf("Digite tres numeros inteiros:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Chamando a função para ordenar os valores
    int iguais = ordenarValores(&num1, &num2, &num3);

    // Exibindo os valores ordenados na tela
    printf("Valores ordenados: %d %d %d\n", num1, num2, num3);

    // Exibindo se os valores são iguais ou diferentes
    if (iguais) {
        printf("Os tres valores sao iguais.\n");
    } else {
        printf("Os tres valores sao diferentes.\n");
    }

    return 0;
}
