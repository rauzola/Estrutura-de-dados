/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
   Associe as variáveis aos ponteiros (use &).Modifique os valores de cada  variável  usando  os  ponteiros. 
   Imprima  os  valores  das  variáveis antes  e  após  a modificação.
*/

#include <stdio.h>

int main() {
    int inteiro = 10;
    float real = 3.14;
    char caractere = 'A';

    // Declarando ponteiros para os tipos de dados
    int *ptrInteiro;
    float *ptrReal;
    char *ptrCaractere;

    // Associando os endereços das variáveis aos ponteiros
    ptrInteiro = &inteiro;
    ptrReal = &real;
    ptrCaractere = &caractere;

    // Imprimindo os valores das variáveis antes da modificação
    printf("Valores antes da modificacao:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);

    // Modificando os valores das variáveis usando os ponteiros
    *ptrInteiro = 20;
    *ptrReal = 6.28;
    *ptrCaractere = 'B';

    // Imprimindo os valores das variáveis após a modificação
    printf("\nValores apos a modificacao:\n");
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    printf("Caractere: %c\n", caractere);

    return 0;
}
