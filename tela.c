#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela()
{
    int lin;
    system("color 1F");
    system("cls");

    for (lin = 1; lin <= 24; lin++)
    {
        gotoxy(01, lin);
        printf("|");
        gotoxy(80, lin);
        printf("|");
    }

    gotoxy(01, 01);
    printf("+------------------------------------------------------------------------------+\n");

    gotoxy(03, 02);
    printf("Raul Sigoli");
    gotoxy(38, 02);
    printf("UNICV");
    gotoxy(61, 02);
    printf("Estrutura de Dados");

    gotoxy(01, 03);
    printf("+------------------------------------------------------------------------------+\n");

    gotoxy(01, 22);
    printf("+------------------------------------------------------------------------------+\n");

    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+------------------------------------------------------------------------------+\n");
}

int main()
{
    char nome[40];
    float n1;
    float n2;
    float n3;
    float media;

    tela();

    gotoxy(10, 10);
    printf("Digite o nome do Aluno..: ");
    gotoxy(10, 12);
    printf("Digite a Nota 1.........: ");
    gotoxy(10, 14);
    printf("Digite a Nota 2.........: ");
    gotoxy(10, 16);
    printf("Digite a Nota 3.........: ");

    gotoxy(36, 10);
    fgets(nome, 40, stdin);

    do
    {
        gotoxy(36, 12);
        printf("         ");
        gotoxy(36, 12);
        scanf("%f", &n1);
        if (n1 < 0 || n1 > 10)
        {
            gotoxy(07, 23);
            printf("Nota Invalida. Digite nota entre 0 e 10");
            getch();
            gotoxy(07, 23);
            printf("+                                                        +\n");
        }
    } while (n1 < 0 || n1 > 10);

   
     do
    {
        gotoxy(36, 14);
        printf("         ");
        gotoxy(36, 14);
        scanf("%f", &n2);
        if (n2 < 0 || n2 > 10)
        {
            gotoxy(07, 23);
            printf("Nota Invalida. Digite nota entre 0 e 10");
            getch();
            gotoxy(07, 23);
            printf("+                                                        +\n");
        }
    } while (n2 < 0 || n2 > 10);


    do
    {
        gotoxy(36, 16);
        printf("         ");
        gotoxy(36, 16);
        scanf("%f", &n2);
        if (n2 < 0 || n2 > 10)
        {
            gotoxy(07, 23);
            printf("Nota Invalida. Digite nota entre 0 e 10");
            getch();
            gotoxy(07, 23);
            printf("+                                                        +\n");
        }
    } while (n2 < 0 || n2 > 10);

    media = ((n1 * 2) + (n2 * 3) + (n3 * 5)) / 10;

    gotoxy(07, 24);
    if(media <=4){
        printf("Conceito D");
    } else {
        if(media<=6){
            printf("Conceito C");
        } else {
            if(media<=8){
                printf("Conceito B");
            } else {
                if(media<=10){
                    printf("Conceito A");
                }
            }
        }
        
    }
    return 0;
}