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

int MeuProduto(){

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

        switch(opc){
            case 1: {
                Cadastrar();
                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

}

int MovEstoque(){

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
        printf("1 - Consultar Fichario do Produto");
        gotoxy(20, 9);
        printf("2 - Consultar em Ordem de Codigo");
        gotoxy(20, 10);
        printf("3 - Consultar em Ordem Alfabetica");
        gotoxy(20, 11);
        printf("4 - Consultar o Codigo Especifico");
        gotoxy(20, 12);
        printf("5 - Retornar Menu Principal");
       
        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch(opc){
            case 1: {
                Consultar();
                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                    main();
                break;
           
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

}

int Cadastrar(){

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
        printf("Cadastrar Produto");
        gotoxy(20, 8);
        printf("    Codigo do Produto......:");
        gotoxy(20, 9);
        printf("1 - Descricao do Produto...:");
        gotoxy(20, 10);
        printf("2 - Unidade de Medida......:");
        gotoxy(20, 11);
        printf("3 - Data de Validade.......:");
        gotoxy(14, 12);
        printf("+-------------------------------------+");
        gotoxy(14, 13);
        printf("|      Saldo do Estoque do Produto    |");
        gotoxy(14, 14);
        printf("+-------------------------------------+");
        gotoxy(14, 15);
        printf("+-------------+--------------+--------+");
        gotoxy(14, 16);
        printf("| Quantidade  | Custo Medio  | Valor  | ");
        gotoxy(14, 17);
        printf("+-------------+--------------+--------+");
        gotoxy(14, 18);
        printf("|             |              |        |");
        gotoxy(14, 19);
        printf("+-------------+--------------+--------+");

        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch(opc){
            case 1: {
                //Menu_produto(&L);
                break;
            }
            case 2:
                break;
            case 3:
                break;
            
           
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

}


int Consultar(){

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
        printf("Consultar Produto");
        gotoxy(01, 04);
        printf("+------------------------------------------------------------------------------+\n");
        gotoxy(02, 05);
        printf("CD | Descricao do Produto   | Uind | Data Valid | Qtde  | VL.Unit | VL Total");
        gotoxy(01, 06);
        printf("+--- ------------------------ ------ ------------ ------- --------- -----------+\n");
        
       

        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch(opc){
            case 1: {
                //Menu_produto(&L);
                break;
            }
            case 2:
                break;
            case 3:
                break;
            
           
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

}


int MenuMovEstoque(){

    TipoLista L;
    L.primeiro= NULL;
    L.ultimo= NULL;
    int opc;
    system("color 1F");
    setlocale(LC_ALL, "portuguese-brazilian");
    // le_arquivo(&L);

    do {
        tela();
       gotoxy(20, 10);
        printf("1 - Cadastra Movimentacao de Estoque");
        gotoxy(20, 12);
        printf("2 - Lista Movimentacao de Estoque");
        gotoxy(20, 14);
        printf("3 - Retornar ao Menu Principal");
       

        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch(opc){
            case 1: {
                CadastrarMovmentacao();
                break;
            }
            case 2:
                break;
            case 3:
                main();
                break;
            
           
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

}


int CadastrarMovmentacao(){

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
        printf("Cadastrar Movimentacao");
        gotoxy(20, 8);
        printf("Codigo do Produto......:");
        gotoxy(20, 9);
        printf("Data da Movimentacao...:");
        gotoxy(20, 10);
        printf("Tipo de Movimentacao...:");
        gotoxy(20, 11);
        printf("Quantidade.............:");
        gotoxy(20, 12);
        printf("Valor Unitario.........:");
        gotoxy(20, 13);
        printf("Valor Total............:");
        
        gotoxy(14, 15);
        printf("+-------------+--------------+-------------+");
        gotoxy(14, 16);
        printf("| Quantidade  | Custo Medio  | Valor Total |");
        gotoxy(14, 17);
        printf("+-------------+--------------+-------------+");
        gotoxy(14, 18);
        printf("|             |              |             |");
        gotoxy(14, 19);
        printf("+-------------+--------------+-------------+");

        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch(opc){
            case 1: {
                //Menu_produto(&L);
                break;
            }
            case 2:
                break;
            case 3:
                break;
            
           
            default:
                gotoxy(20, 23);
                printf("Opcao Invalida");
                break;
        }

        
    } while(opc = 9);

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
        gotoxy(20, 10);
        printf("1 - Menu Cadastro de Produto");
        gotoxy(20, 12);
        printf("2 - Menu Movimentacao de Estoque");
        gotoxy(20, 14);
        printf("3 - Finalizar Programa");
        gotoxy(8, 23);
        printf("Digite sua opcao.:");
        gotoxy(28, 23);
        scanf("%d", &opc);

       switch (opc){
        case 1: {
            MeuProduto();
            break;
        }
        case 2:
            MenuMovEstoque();
            break;
        case 3:
            break;
        default:
            gotoxy(20, 23);
            printf("Opcao Invalida");
            break;
       }

        
    } while(opc = 9);

    return 0;

}