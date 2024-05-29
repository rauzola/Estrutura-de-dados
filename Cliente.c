#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

typedef struct {
    int cd_cliente;
    int nm_cliente;
    int ds_endereco;
    int nr_numero;
    int nr_documento;
    int ds_cidade;
    int cd_uf;
    int dt_cadastro;
    int nr_telefone;
} reg_cliente;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem {
    reg_cliente conteudo;
    TipoApontador proximo;
} TipoItem ;

typedef struct {
    TipoApontador primeiro;
    TipoApontador ultimo;
} TipoLista;

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

int main(){

    TipoLista L;
    L.primeiro= NULL;
    L.ultimo= NULL;
    int opc;
    system("color 1F");
    setlocale(LC_ALL, "portuguese-brazilian");
    // le_arquivo(&L);
    do {
        tela();
        gotoxy(30, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 8);
        printf("1 - Cadastrar Cliente no final da Lista");
        gotoxy(20, 9);
        printf("2 - Cadastrar Cliente no Inicio da Lista");
        gotoxy(20, 10);
        printf("3 - Cadastrar Cliente em uma Possicao da Lista");
        gotoxy(20, 11);
        printf("4 - Remover Cliente no Final da Lista");
        gotoxy(20, 12);
        printf("5 - Remover Cliente na Posicao da Lista");
        gotoxy(20, 13);
        printf("6 - Remover Cliente no Inicio da Lista");
        gotoxy(20, 14);
        printf("7 - Consultar Todos Cliente");
        gotoxy(20, 15);
        printf("8 - Alterar dados do Cliente");
        gotoxy(20, 16);
        printf("9 - Finalizar Programa");
        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        
    } while(opc < 9);
    return 0;

}