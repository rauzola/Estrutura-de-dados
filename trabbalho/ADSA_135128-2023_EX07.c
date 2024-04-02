/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Escreva um programa que contenha duas variáveis inteiras. 
   Compare seus endereços e exiba o maior endereço.
*/

#include <stdio.h>

int main() {
    int var1, var2;
    int *ptr1, *ptr2;

    // Atribuindo endereços das variáveis aos ponteiros
    ptr1 = &var1;
    ptr2 = &var2;

    // Comparando endereços
    if (ptr1 > ptr2) {
        printf("O endereco de var1 (%p) e maior.\n", ptr1);
    } else if (ptr2 > ptr1) {
        printf("O endereco de var2 (%p) e maior.\n", ptr2);
    } else {
        printf("Os enderecos de var1 e var2 sao iguais.\n");
    }

    return 0;
}
