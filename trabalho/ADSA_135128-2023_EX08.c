/* Autor....: Raul Sigoli
   Data.....: 01/04/2024
   Objetivo.: Escreva  um  programa  que  contenha  duas  variáveis  inteiras.   
   Leia  essas  variáveis  do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
*/

#include <stdio.h>

int main() {
    int var1, var2;
    int *ptr1, *ptr2;

    // Lendo os valores do teclado
    printf("Digite o valor da var1: ");
    scanf("%d", &var1);

    printf("Digite o valor da var2: ");
    scanf("%d", &var2);

    // Atribuindo endereços das variáveis aos ponteiros
    ptr1 = &var1;
    ptr2 = &var2;

    // Comparando endereços
    if (ptr1 > ptr2) {
        printf("Conteudo do maior endereco: %d\n", *ptr1);
    } else if (ptr2 > ptr1) {
        printf("Conteudo do maior endereco: %d\n", *ptr2);
    } else {
        printf("Os enderecos de var1 e var2 sao iguais.\n");
    }

    return 0;
}
