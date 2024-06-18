
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

// Dados produto
typedef struct
{
    int cd_produto;
    char nm_produto[50];
    char und_produto[03];
    char dt_validade[11];
    float qtd_produto;
    float vl_CustoMedio;
    float vl_total;
} reg_produto;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{
    reg_produto conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

// Dados movimentação estoque
typedef struct
{
    char dt_mov[11];
    int cd_prod_mov;
    char tp_mov[7];
    float qt_mov;
    float vl_unit_mov;
    float vl_total_mov;
    float qtd_estoque;
    float customed_mov;
    float vl_final;
} reg_movimentacao;

typedef struct TipoItem_mov *TipoApontador_mov;

typedef struct TipoItem_mov
{
    TipoApontador_mov anterior_mov;
    reg_movimentacao conteudo_mov;
    TipoApontador proximo_mov;
} TipoItem_mov;

typedef struct
{
    TipoApontador_mov Primeiro_mov;
    TipoApontador_mov Ultimo_mov;
} TipoLista_mov;

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

// Funcoes inicio
// tudo que tem le siginifica que le alguma coisa

// Função genérica para leitura de strings
char *le_string(int max_length, int x, int y, const char *mensagem_erro)
{
    char *str = malloc(max_length);
    if (!str)
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    do
    {
        gotoxy(x, y);
        printf("                         ");
        gotoxy(x, y);
        fgets(str, max_length, stdin);
        str[strcspn(str, "\n")] = 0; // Remove newline character

        if (strlen(str) == 0)
        {
            gotoxy(8, 29);
            printf("%s", mensagem_erro);
            getch();
            gotoxy(8, 29);
            printf("                                                  ");
        }
    } while (strlen(str) == 0);

    return str;
}

// Funções específicas utilizando a função genérica
char *le_nm_produto()
{
    return le_string(50, 40, 9, "Nome do Produto é Obrigatório");
}

char *le_und_produto()
{
    return le_string(3, 40, 11, "Unidade de Medida é Obrigatória");
}

char *le_dt_validade()
{
    return le_string(11, 40, 13, "Data de Validade é Obrigatória");
}

// Função para pesquisar se o elemento tem na leitura
TipoApontador pesquisa(TipoLista *L, int codigo)
{
    TipoApontador aux = L->Primeiro;
    // Irá percorrer a lista do primeiro até o final
    while (aux != NULL)
    {
        // Caso encontre ele para o processo e devolve o aux para a função
        if (aux->conteudo.cd_produto == codigo)
        {
            break;
        }
        // Se percorrer a lista e não encontrar devolve o NULL para a função
        aux = aux->proximo;
    }
    return aux;
}

// Função Leitura de Produto
void leitura(reg_produto *reg_prod)
{
    // Lê o nome do produto e armazena na estrutura reg_prod
    strcpy(reg_prod->nm_produto, le_nm_produto());
    // Lê a unidade de medida do produto e armazena na estrutura reg_prod
    strcpy(reg_prod->und_produto, le_und_produto());
    // Lê a data de validade do produto e armazena na estrutura reg_prod
    strcpy(reg_prod->dt_validade, le_dt_validade());
}

// Função para cadastrar produto no início da lista
void cadastrarInicio(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o novo item
    TipoApontador aux1;   // Ponteiro auxiliar para pesquisa
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int resp;             // Variável para armazenar a resposta do usuário

    do
    {
        tela();        // Exibe a tela inicial
        telaProduto(); // Exibe a tela de cadastro de produto
        gotoxy(30, 3);
        printf("CADASTRAR PRODUTO NO INICIO");
        gotoxy(40, 7);
        // Lê o código do produto
        scanf("%d", &reg_prod.cd_produto);
        getchar(); // Limpa o buffer de entrada

        // Verifica se o código do produto já existe na lista
        aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 != NULL)
        {
            gotoxy(8, 29);
            printf("Codigo ja Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(8, 29);
            printf("                    "); // Limpa a mensagem
        }
    } while (aux1 != NULL); // Continua pedindo o código até encontrar um não cadastrado

    leitura(&reg_prod);         // Lê os dados do produto
    reg_prod.qtd_produto = 0;   // Inicializa a quantidade do produto
    reg_prod.vl_CustoMedio = 0; // Inicializa o custo médio do produto
    reg_prod.vl_total = 0;      // Inicializa o valor total do produto

    gotoxy(8, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp); // Lê a resposta do usuário
    if (resp == 1)
    {
        P = (TipoApontador)malloc(sizeof(TipoItem)); // Aloca memória para o novo item
        P->conteudo = reg_prod;                      // Copia os dados do produto para o novo item
        P->proximo = L->Primeiro;                    // Faz o novo item apontar para o primeiro item da lista
        L->Primeiro = P;                             // Faz a lista começar pelo novo item

        // Se a lista estava vazia, atualiza o último item
        if (L->Ultimo == NULL)
        {
            L->Ultimo = P;
        }
    }
}

// Função para cadastrar produto no final da lista
void cadastrarFinal(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o novo item
    TipoApontador aux1;   // Ponteiro auxiliar para pesquisa
    int resp;             // Variável para armazenar a resposta do usuário
    reg_produto reg_prod; // Estrutura para armazenar dados do produto

    do
    {
        tela(); // Exibe a tela inicial
        gotoxy(30, 3);
        printf("CADASTRAR PRODUTO NO FIM");
        telaProduto(); // Exibe a tela de cadastro de produto
        gotoxy(40, 7);
        // Lê o código do produto
        scanf("%d", &reg_prod.cd_produto);
        getchar(); // Limpa o buffer de entrada

        // Verifica se o código do produto já existe na lista
        aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 != NULL)
        {
            gotoxy(8, 29);
            printf("Codigo ja Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(8, 29);
            printf("                    "); // Limpa a mensagem
        }
    } while (aux1 != NULL); // Continua pedindo o código até encontrar um não cadastrado

    leitura(&reg_prod);         // Lê os dados do produto
    reg_prod.qtd_produto = 0;   // Inicializa a quantidade do produto
    reg_prod.vl_CustoMedio = 0; // Inicializa o custo médio do produto
    reg_prod.vl_total = 0;      // Inicializa o valor total do produto

    gotoxy(8, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp); // Lê a resposta do usuário
    if (resp == 1)
    {
        P = (TipoApontador)malloc(sizeof(TipoItem)); // Aloca memória para o novo item
        P->conteudo = reg_prod;                      // Copia os dados do produto para o novo item
        P->proximo = NULL;                           // O próximo do novo item é NULL (final da lista)

        // Se a lista estava vazia, inicializa o primeiro e o último item
        if (L->Primeiro == NULL)
        {
            L->Primeiro = P;
            L->Ultimo = P;
        }
        else
        {
            L->Ultimo->proximo = P; // O último item aponta para o novo item
            L->Ultimo = P;          // Atualiza o último item da lista
        }
    }
}

// Função para cadastrar produto em uma posição específica da lista
void cadastrarPosicao(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o novo item
    TipoApontador aux1;   // Ponteiro auxiliar para pesquisa
    int resp;             // Variável para armazenar a resposta do usuário
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int posicao;          // Variável para armazenar a posição desejada

    do
    {
        tela(); // Exibe a tela inicial
        gotoxy(30, 3);
        printf("CADASTRAR PRODUTO EM UMA POSICAO");
        telaProduto();                     // Exibe a tela de cadastro de produto
        gotoxy(40, 7);                     // Arruma o cursor
        scanf("%d", &reg_prod.cd_produto); // Lê o código do produto
        getchar();                         // Limpa o buffer de entrada

        // Verifica se o código do produto já existe na lista
        aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 != NULL)
        {
            gotoxy(8, 29);
            printf("Codigo ja Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(8, 29);
            printf("                    "); // Limpa a mensagem
        }
    } while (aux1 != NULL); // Continua pedindo o código até encontrar um não cadastrado

    leitura(&reg_prod);         // Lê os dados do produto
    reg_prod.qtd_produto = 0;   // Inicializa a quantidade do produto
    reg_prod.vl_CustoMedio = 0; // Inicializa o custo médio do produto
    reg_prod.vl_total = 0;      // Inicializa o valor total do produto

    gotoxy(8, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp); // Lê a resposta do usuário
    if (resp == 1)
    {
        P = (TipoApontador)malloc(sizeof(TipoItem)); // Aloca memória para o novo item
        P->conteudo = reg_prod;                      // Copia os dados do produto para o novo item

        if (L->Primeiro == NULL)
        {
            L->Primeiro = P;   // Define o primeiro item da lista
            L->Ultimo = P;     // Define o último item da lista
            P->proximo = NULL; // Não há próximo item
        }
        else
        {
            gotoxy(8, 29);
            printf("Informe a posicao..:");
            scanf("%d", &posicao); // Lê a posição desejada

            if (posicao == 1)
            {
                P->proximo = L->Primeiro; // O novo item aponta para o primeiro item
                L->Primeiro = P;          // O novo item se torna o primeiro da lista
            }
            else
            {
                aux1 = L->Primeiro;
                for (int i = 1; i < posicao - 1 && aux1 != NULL; i++)
                {
                    aux1 = aux1->proximo; // Avança até a posição desejada
                }
                if (aux1 != NULL)
                {
                    P->proximo = aux1->proximo; // O novo item aponta para o próximo item
                    aux1->proximo = P;          // O item anterior aponta para o novo item
                    if (P->proximo == NULL)
                    {
                        L->Ultimo = P; // Atualiza o último item se necessário
                    }
                }
            }
        }
    }
}

// Função para remover o produto no início da lista
void removerInicio(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o item a ser removido
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int resp;             // Variável para armazenar a resposta do usuário

    tela(); // Exibe a tela inicial
    gotoxy(40, 3);
    printf("REMOVER PRODUTO NO INICIO");
    telaProduto(); // Exibe a tela de remoção de produto

    if (L->Primeiro == NULL)
    {
        gotoxy(8, 29);
        printf("Lista Vazia");
        getch(); // Aguarda o usuário pressionar uma tecla
        gotoxy(8, 29);
        printf("           "); // Limpa a mensagem
    }
    else
    {
        P = L->Primeiro;                    // Aponta para o primeiro item
        L->Primeiro = L->Primeiro->proximo; // O próximo item se torna o primeiro

        reg_prod = P->conteudo; // Copia os dados do produto
        gotoxy(37, 8);
        printf("%s", reg_prod.nm_produto);
        gotoxy(37, 10);
        printf("%s", reg_prod.und_produto);
        gotoxy(37, 12);
        printf("%s", reg_prod.dt_validade);
        gotoxy(20, 21);
        printf("%.2f", reg_prod.qtd_produto);
        gotoxy(50, 21);
        printf("%.2f", reg_prod.vl_CustoMedio);
        gotoxy(60, 21);
        printf("%.2f", reg_prod.vl_total);
        free(P); // Libera a memória do item removido

        gotoxy(8, 29);
        printf("Confirma a exclusao do Produto (1-SIM; 2-NAO)..:");
        scanf("%d", &resp); // Lê a resposta do usuário
    }
}

// Função para remover o produto no final da lista
void removerFinal(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o item a ser removido
    TipoApontador aux1;   // Ponteiro auxiliar para percorrer a lista
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int resp;             // Variável para armazenar a resposta do usuário

    tela(); // Exibe a tela inicial
    gotoxy(40, 3);
    printf("REMOVER PRODUTO NO FINAL");
    telaProduto(); // Exibe a tela de remoção de produto

    if (L->Primeiro == NULL)
    {
        gotoxy(8, 29);
        printf("Lista Vazia");
        getch(); // Aguarda o usuário pressionar uma tecla
        gotoxy(8, 29);
        printf("           "); // Limpa a mensagem
    }
    else
    {
        P = L->Ultimo; // Aponta para o último item
        if (L->Primeiro == L->Ultimo)
        {
            L->Primeiro = NULL; // Lista fica vazia
            L->Ultimo = NULL;   // Lista fica vazia
        }
        else
        {
            aux1 = L->Primeiro;
            while (aux1->proximo != L->Ultimo)
            {
                aux1 = aux1->proximo; // Avança até o penúltimo item
            }
            L->Ultimo = aux1;          // Atualiza o último item
            L->Ultimo->proximo = NULL; // O último item não tem próximo
        }

        reg_prod = P->conteudo; // Copia os dados do produto
        gotoxy(37, 8);
        printf("%s", reg_prod.nm_produto);
        gotoxy(37, 10);
        printf("%s", reg_prod.und_produto);
        gotoxy(37, 12);
        printf("%s", reg_prod.dt_validade);
        gotoxy(20, 21);
        printf("%.2f", reg_prod.qtd_produto);
        gotoxy(50, 21);
        printf("%.2f", reg_prod.vl_CustoMedio);
        gotoxy(60, 21);
        printf("%.2f", reg_prod.vl_total);
        free(P); // Libera a memória do item removido

        gotoxy(8, 29);
        printf("Confirma a exclusao do Produto (1-SIM; 2-NAO)..:");
        scanf("%d", &resp); // Lê a resposta do usuário
    }
}

// Função para remover produto em uma posição específica da lista
void removerPosicao(TipoLista *L)
{
    TipoApontador P;      // Ponteiro para o item a ser removido
    TipoApontador aux1;   // Ponteiro auxiliar para percorrer a lista
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int resp;             // Variável para armazenar a resposta do usuário
    int posicao;          // Variável para armazenar a posição desejada

    tela(); // Exibe a tela inicial
    gotoxy(40, 3);
    printf("REMOVER PRODUTO EM UMA POSICAO");
    telaProduto(); // Exibe a tela de remoção de produto

    if (L->Primeiro == NULL) // Verifica se a lista está vazia
    {
        gotoxy(8, 29);
        printf("Lista Vazia");
        getch(); // Aguarda o usuário pressionar uma tecla
        gotoxy(8, 29);
        printf("           "); // Limpa a mensagem
    }
    else
    {
        P = L->Primeiro;              // Aponta para o primeiro item
        if (L->Primeiro == L->Ultimo) // Se houver apenas um item na lista
        {
            L->Primeiro = NULL; // Lista fica vazia
            L->Ultimo = NULL;   // Lista fica vazia
        }
        else
        {
            gotoxy(8, 29);
            printf("Informe a posicao..:");
            scanf("%d", &posicao); // Lê a posição desejada

            if (posicao == 1) // Se a posição for 1, remove o primeiro item
            {
                L->Primeiro = L->Primeiro->proximo; // O próximo item se torna o primeiro
                free(P);                            // Libera a memória do item removido
            }
            else
            {
                aux1 = L->Primeiro;
                for (int i = 1; i < posicao - 1; i++)
                {
                    aux1 = aux1->proximo; // Avança até a posição desejada
                }
                P = aux1->proximo;          // P aponta para o item a ser removido
                aux1->proximo = P->proximo; // O item anterior aponta para o próximo item

                // Exibe os dados do produto a ser removido
                reg_prod = P->conteudo;
                gotoxy(37, 8);
                printf("%s", reg_prod.nm_produto);
                gotoxy(37, 10);
                printf("%s", reg_prod.und_produto);
                gotoxy(37, 12);
                printf("%s", reg_prod.dt_validade);
                gotoxy(20, 21);
                printf("%.2f", reg_prod.qtd_produto);
                gotoxy(50, 21);
                printf("%.2f", reg_prod.vl_CustoMedio);
                gotoxy(60, 21);
                printf("%.2f", reg_prod.vl_total);
                free(P); // Libera a memória do item removido
            }
        }
    }

    // Pergunta se deseja remover
    gotoxy(8, 29);
    printf("Confirma a exclusao do Produto (1-SIM; 2-NAO)..:");
    scanf("%d", &resp);
}

// Função para alterar um produto
void alterarProduto(TipoLista *L)
{
    TipoApontador aux1;   // Ponteiro auxiliar para percorrer a lista
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int resp;             // Variável para armazenar a resposta do usuário

    do
    {
        telaProduto(); // Exibe a tela de produto
        gotoxy(40, 3);
        printf("ALTERAR PRODUTO");
        gotoxy(40, 7);
        scanf("%d", &reg_prod.cd_produto); // Lê o código do produto
        getchar();                         // Limpa o buffer de entrada

        // Pesquisa o produto na lista
        aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 == NULL)
        {
            gotoxy(30, 3);
            printf("Codigo nao Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(30, 3);
            printf("                   "); // Limpa a mensagem
        }
    } while (aux1 == NULL); // Continua até encontrar um produto cadastrado

    reg_prod = aux1->conteudo; // Copia os dados do produto
    gotoxy(40, 9);
    printf("%s", aux1->conteudo.nm_produto);
    gotoxy(40, 11);
    printf("%s", aux1->conteudo.und_produto);
    gotoxy(40, 13);
    printf("%s", aux1->conteudo.dt_validade);
    gotoxy(23, 21);
    printf("%.2f", aux1->conteudo.qtd_produto);
    gotoxy(44, 21);
    printf("%.2f", aux1->conteudo.vl_CustoMedio);
    gotoxy(66, 21);
    printf("%.2f", aux1->conteudo.vl_total);

    do
    {
        gotoxy(7, 29);
        printf("Qual campo deseja alterar (0 para terminar)? ");
        scanf("%d", &resp); // Lê a opção do usuário

        switch (resp)
        {
        case 0:
            break;
        case 1:
            strcpy(reg_prod.nm_produto, le_nm_produto()); // Lê e altera o nome do produto
            break;
        case 2:
            strcpy(reg_prod.und_produto, le_und_produto()); // Lê e altera a unidade do produto
            break;
        case 3:
            strcpy(reg_prod.dt_validade, le_dt_validade()); // Lê e altera a data de validade
            break;
        default:
            gotoxy(7, 29);
            printf("Opcao Invalida. Tente uma opcao valida");
            getch(); // Aguarda o usuário pressionar uma tecla
            break;
        }
    } while (resp != 0); // Continua até o usuário escolher 0

    gotoxy(7, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp); // Lê a confirmação do usuário
    if (resp == 1)
    {
        aux1->conteudo = reg_prod; // Atualiza os dados do produto
    }
}

// Função para consultar todos os produtos na lista
void consultarTodos(TipoLista *L)
{
    TipoApontador p;      // Ponteiro para percorrer a lista
    reg_produto reg_prod; // Estrutura para armazenar dados do produto
    int lin;              // Variável para controle de linhas na tela

    tela(); // Exibe a tela inicial
    gotoxy(40, 3);
    printf("CONSULTA DE PRODUTOS");
    telaProduto(); // Exibe a tela de produtos

    lin = 7;         // Inicializa a linha de início
    p = L->Primeiro; // Aponta para o primeiro item da lista

    if (p == NULL) // Verifica se a lista está vazia
    {
        gotoxy(8, 29);
        printf("LISTA DE PRODUTOS VAZIA");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
    else
    {
        while (p != NULL) // Percorre a lista até o final
        {
            lin += 2;               // Incrementa a linha
            reg_prod = p->conteudo; // Copia os dados do produto
            gotoxy(37, lin);
            printf("%d", reg_prod.cd_produto);
            gotoxy(37, lin);
            printf("%s", reg_prod.nm_produto);
            gotoxy(37, lin);
            printf("%s", reg_prod.und_produto);
            gotoxy(37, lin);
            printf("%s", reg_prod.dt_validade);
            gotoxy(23, lin);
            printf("%6.2f", reg_prod.qtd_produto);
            gotoxy(44, lin);
            printf("%6.2f", reg_prod.vl_CustoMedio);
            gotoxy(66, lin);
            printf("%6.2f", reg_prod.vl_total);
            p = p->proximo; // Avança para o próximo item
            lin++;
            if (lin > 27) // Se atingir o limite de linhas na tela
            {
                lin = 7; // Reinicia a contagem de linhas
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                gotoxy(2, 5);
                telaProduto();
            }
            gotoxy(8, 29);
            printf("Pressione uma tecla para continuar...");
            // getch();
        }
    }
}

// Função para consultar todos os produtos, um por tela
void consultarFichario(TipoLista *L)
{
    TipoApontador p;      // Ponteiro para percorrer a lista
    reg_produto reg_prod; // Estrutura para armazenar dados do produto

    tela(); // Exibe a tela inicial
    gotoxy(40, 3);
    printf("CONSULTA DE PRODUTOS");
    telaProduto(); // Exibe a tela de produtos

    p = L->Primeiro; // Aponta para o primeiro item da lista
    if (p == NULL)   // Verifica se a lista está vazia
    {
        gotoxy(8, 29);
        printf("LISTA DE PRODUTOS VAZIA");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
    else
    {
        while (p != NULL) // Percorre a lista até o final
        {
            telaProduto();          // Exibe a tela de produto
            reg_prod = p->conteudo; // Copia os dados do produto

            // Exibe os dados do produto
            gotoxy(40, 7);
            printf("%d", reg_prod.cd_produto);
            gotoxy(40, 9);
            printf("%s", reg_prod.nm_produto);
            gotoxy(40, 11);
            printf("%s", reg_prod.und_produto);
            gotoxy(40, 13);
            printf("%s", reg_prod.dt_validade);
            gotoxy(23, 21);
            printf("%6.2f", reg_prod.qtd_produto);
            gotoxy(44, 21);
            printf("%6.2f", reg_prod.vl_CustoMedio);
            gotoxy(66, 21);
            printf("%6.2f", reg_prod.vl_total);

            p = p->proximo; // Avança para o próximo item
            gotoxy(8, 29);
            printf("Pressione uma tecla para continuar...");
            getch(); // Aguarda o usuário pressionar uma tecla
        }
    }
}

// Função de comparação para ordenar produtos por código
int comparaCodigo(const void *a, const void *b)
{
    reg_produto *produtoA = (reg_produto *)a;
    reg_produto *produtoB = (reg_produto *)b;
    return produtoA->cd_produto - produtoB->cd_produto;
}

// Função para ordenar e consultar produtos por código
void ordenarCodigo(TipoLista *L)
{
    TipoApontador p;    // Ponteiro para percorrer a lista
    reg_produto *vetor; // Vetor para armazenar os produtos
    int lin;            // Variável para controle de linhas na tela
    int i;              // Índice para percorrer o vetor
    int n;              // Contador de itens na lista

    tela(); // Exibe a tela inicial
    gotoxy(30, 3);
    printf("CONSULTA DE PRODUTOS");
    telaconsulta(); // Exibe a tela de consulta de produtos

    lin = 7;         // Inicializa a linha de início
    p = L->Primeiro; // Aponta para o primeiro item da lista

    if (p == NULL) // Verifica se a lista está vazia
    {
        gotoxy(7, 23);
        printf("LISTA DE PRODUTOS VAZIA");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
    else
    {
        // Conta o número de itens na lista
        n = 0;
        while (p != NULL)
        {
            n++;
            p = p->proximo;
        }

        // Aloca memória para o vetor de produtos
        vetor = (reg_produto *)malloc(n * sizeof(reg_produto));
        p = L->Primeiro;
        i = 0;

        // Preenche o vetor com os produtos da lista
        while (p != NULL)
        {
            vetor[i] = p->conteudo;
            p = p->proximo;
            i++;
        }

        // Ordena o vetor por código de produto
        qsort(vetor, n, sizeof(reg_produto), comparaCodigo);

        // Exibe os produtos ordenados
        for (i = 0; i < n; i++)
        {
            gotoxy(2, lin);
            printf("%d", vetor[i].cd_produto);
            gotoxy(5, lin);
            printf("%s", vetor[i].nm_produto);
            gotoxy(36, lin);
            printf("%s", vetor[i].und_produto);
            gotoxy(40, lin);
            printf("%s", vetor[i].dt_validade);
            gotoxy(53, lin);
            printf("%6.2f", vetor[i].qtd_produto);
            gotoxy(63, lin);
            printf("%6.2f", vetor[i].vl_CustoMedio);
            gotoxy(73, lin);
            printf("%6.2f", vetor[i].vl_total);
            lin++;

            // Verifica se atingiu o limite de linhas na tela
            if (lin > 20)
            {
                lin = 7; // Reinicia a contagem de linhas
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                telaconsulta();
            }
        }

        free(vetor); // Libera a memória alocada para o vetor
        gotoxy(8, 29);
        printf("Pressione uma tecla para continuar...");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
}

// Função de comparação para ordenar produtos por nome
int comparaNome(const void *a, const void *b)
{
    reg_produto *produtoA = (reg_produto *)a;
    reg_produto *produtoB = (reg_produto *)b;
    return strcmp(produtoA->nm_produto, produtoB->nm_produto);
}

// Função para consultar e exibir produtos em ordem alfabética por nome
void consultarOrdemNome(TipoLista *L)
{
    TipoApontador p;    // Ponteiro para percorrer a lista
    reg_produto *vetor; // Vetor para armazenar os produtos
    int lin;            // Variável para controle de linhas na tela
    int i;              // Índice para percorrer o vetor
    int n;              // Contador de itens na lista

    tela(); // Exibe a tela inicial
    gotoxy(30, 3);
    printf("CONSULTA DE PRODUTOS");
    lin = 7;        // Define a linha inicial para exibição na tela
    telaconsulta(); // Exibe a tela de consulta

    p = L->Primeiro; // Aponta para o primeiro item da lista

    if (p == NULL) // Verifica se a lista está vazia
    {
        gotoxy(7, 23);
        printf("LISTA DE PRODUTOS VAZIA");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
    else
    {
        // Conta o número de itens na lista
        n = 0;
        while (p != NULL)
        {
            n++;
            p = p->proximo;
        }

        // Aloca memória para o vetor de produtos
        vetor = (reg_produto *)malloc(n * sizeof(reg_produto));
        p = L->Primeiro;
        i = 0;

        // Preenche o vetor com os produtos da lista
        while (p != NULL)
        {
            vetor[i] = p->conteudo;
            p = p->proximo;
            i++;
        }

        // Ordena o vetor por nome de produto
        qsort(vetor, n, sizeof(reg_produto), comparaNome);

        // Exibe os produtos ordenados por nome
        for (i = 0; i < n; i++)
        {
            gotoxy(2, lin);
            printf("%d", vetor[i].cd_produto);
            gotoxy(5, lin);
            printf("%s", vetor[i].nm_produto);
            gotoxy(36, lin);
            printf("%s", vetor[i].und_produto);
            gotoxy(40, lin);
            printf("%s", vetor[i].dt_validade);
            gotoxy(53, lin);
            printf("%6.2f", vetor[i].qtd_produto);
            gotoxy(63, lin);
            printf("%6.2f", vetor[i].vl_CustoMedio);
            gotoxy(73, lin);
            printf("%6.2f", vetor[i].vl_total);
            lin++;

            // Verifica se atingiu o limite de linhas na tela
            if (lin > 20)
            {
                lin = 7; // Reinicia a contagem de linhas
                gotoxy(25, 23);
                printf("CONSULTA DE PRODUTOS");
                telaconsulta(); // Redesenha a tela de consulta
            }
        }

        free(vetor); // Libera a memória alocada para o vetor
        gotoxy(8, 29);
        printf("Pressione uma tecla para continuar...");
        getch(); // Aguarda o usuário pressionar uma tecla
    }
}

// Função para consultar e exibir os detalhes de um produto específico pelo código
void consultaCodigo(TipoLista *L)
{
    TipoApontador aux1;   // Ponteiro auxiliar para encontrar o produto na lista
    reg_produto reg_prod; // Estrutura para armazenar os dados do produto

    do
    {
        telaProduto(); // Exibe a tela de produtos
        gotoxy(40, 3);
        printf("CONSULTA POR PRODUTO");
        gotoxy(40, 7);
        scanf("%d", &reg_prod.cd_produto);       // Lê o código do produto digitado pelo usuário
        getchar();                               // Limpa o buffer de entrada
        aux1 = pesquisa(L, reg_prod.cd_produto); // Busca o produto na lista

        // Verifica se o produto não foi encontrado
        if (aux1 == NULL)
        {
            gotoxy(30, 3);
            printf("                                  ");
            gotoxy(30, 3);
            printf("Codigo nao Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(30, 3);
            printf("                                  ");
        }
    } while (aux1 == NULL); // Repete enquanto o código não estiver cadastrado

    // Exibe os detalhes do produto encontrado
    reg_prod = aux1->conteudo;
    gotoxy(40, 9);
    printf("%s", aux1->conteudo.nm_produto);
    gotoxy(40, 11);
    printf("%s", aux1->conteudo.und_produto);
    gotoxy(40, 13);
    printf("%s", aux1->conteudo.dt_validade);
    gotoxy(23, 21);
    printf("%.2f", aux1->conteudo.qtd_produto);
    gotoxy(44, 21);
    printf("%.2f", aux1->conteudo.vl_CustoMedio);
    gotoxy(66, 21);
    printf("%.2f", aux1->conteudo.vl_total);

    gotoxy(8, 29);
    printf("Pressione uma tecla para continuar...");
    getch(); // Aguarda o usuário pressionar uma tecla
}

// Funcoes final

// Função para cadastrar movimentação de estoque
void cadastrarMov(TipoLista *L, TipoLista_mov *M)
{
    TipoApontador_mov P;      // Ponteiro para novo elemento na lista de movimentações
    TipoApontador aux1;       // Ponteiro auxiliar para pesquisa na lista de produtos
    reg_produto reg_prod;     // Estrutura para dados do produto
    reg_movimentacao reg_mov; // Estrutura para dados da movimentação
    int resp;                 // Variável para resposta do usuário

    do
    {
        tela();    // Limpa a tela e redefine os cabeçalhos
        TelaMov(); // Exibe a tela específica para movimentação de estoque
        gotoxy(40, 3);
        printf("CADASTRAR MOVIMENTAÇÃO");

        // Solicita e verifica se o código do produto existe na lista
        gotoxy(37, 6);
        printf("                                      ");
        gotoxy(37, 6);
        scanf("%d", &reg_prod.cd_produto);
        gotoxy(40, 6);
        printf("-");
        aux1 = pesquisa(L, reg_prod.cd_produto);
        if (aux1 == NULL)
        {
            gotoxy(8, 29);
            printf("               ");
            gotoxy(8, 29);
            printf("Produto não Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(8, 29);
            printf("               ");
        }
    } while (aux1 == NULL); // Repete enquanto o código do produto não estiver cadastrado

    // Leitura dos dados da movimentação
    reg_prod = aux1->conteudo;                 // Obtém os dados do produto encontrado
    reg_mov.cd_prod_mov = reg_prod.cd_produto; // Define o código do produto na movimentação
    gotoxy(42, 6);
    printf("%s", reg_prod.nm_produto);
    fflush(stdin);
    gotoxy(37, 8);
    fgets(reg_mov.dt_mov, 11, stdin); // Lê a data da movimentação
    fflush(stdin);
    gotoxy(37, 10);
    scanf("%s", reg_mov.tp_mov); // Lê o tipo de movimentação (E - entrada, S - saída)
    fflush(stdin);
    gotoxy(37, 12);
    scanf("%f", &reg_mov.qt_mov); // Lê a quantidade movimentada
    fflush(stdin);
    gotoxy(37, 14);
    scanf("%f", &reg_mov.vl_unit_mov); // Lê o valor unitário da movimentação

    // Calcula o valor total da movimentação
    reg_mov.vl_total_mov = reg_mov.qt_mov * reg_mov.vl_unit_mov;
    fflush(stdin);
    gotoxy(37, 16);
    printf("%.2f", reg_mov.vl_total_mov);

    // Atualiza a quantidade e valores do produto baseado no tipo de movimentação
    if (strcmp(reg_mov.tp_mov, "E") == 0) // Se for entrada
    {
        reg_prod.qtd_produto += reg_mov.qt_mov;                            // Atualiza a quantidade total
        reg_prod.vl_total += reg_mov.vl_total_mov;                         // Atualiza o valor total
        reg_prod.vl_CustoMedio = reg_prod.vl_total / reg_prod.qtd_produto; // Recalcula o custo médio
        reg_mov.customed_mov = reg_prod.vl_CustoMedio;                     // Define o custo médio na movimentação
        reg_mov.vl_final = reg_prod.vl_CustoMedio * reg_prod.qtd_produto;  // Calcula o valor final
        reg_mov.qtd_estoque = reg_prod.qtd_produto;                        // Define a quantidade atualizada no registro de movimentação
        aux1->conteudo = reg_prod;                                         // Atualiza os dados do produto na lista principal
    }
    else // Se for saída
    {
        reg_prod.qtd_produto -= reg_mov.qt_mov;                           // Atualiza a quantidade total
        reg_prod.vl_total -= reg_mov.vl_total_mov;                        // Atualiza o valor total
        reg_mov.customed_mov = reg_prod.vl_CustoMedio;                    // Define o custo médio na movimentação
        reg_mov.vl_final = reg_prod.vl_CustoMedio * reg_prod.qtd_produto; // Calcula o valor final
        reg_mov.qtd_estoque = reg_prod.qtd_produto;                       // Define a quantidade atualizada no registro de movimentação
        aux1->conteudo = reg_prod;                                        // Atualiza os dados do produto na lista principal
    }

    // Mostra a quantidade atualizada na tela
    fflush(stdin);
    gotoxy(22, 23);
    printf("%6.2f", reg_prod.qtd_produto);
    gotoxy(42, 23);
    printf("%6.2f", reg_prod.vl_CustoMedio);
    gotoxy(66, 23);
    printf("%6.2f", reg_prod.vl_total);

    // Pergunta ao usuário se deseja salvar os dados da movimentação
    gotoxy(8, 29);
    printf("Deseja gravar os dados (1-SIM; 2-NAO)..:");
    scanf("%d", &resp);
    if (resp == 1) // Se o usuário escolher SIM
    {
        P = (TipoApontador_mov)malloc(sizeof(TipoItem_mov)); // Aloca memória para o novo item de movimentação
        P->conteudo_mov = reg_mov;                           // Atribui os dados da movimentação ao novo item

        // Verifica se a lista de movimentações está vazia
        if (M->Primeiro_mov == NULL)
        {
            M->Primeiro_mov = P; // Define o novo item como o primeiro da lista
            M->Primeiro_mov->proximo_mov = NULL;
            M->Ultimo_mov = M->Primeiro_mov; // Define o novo item como o último da lista
        }
        else
        {
            P->proximo_mov = M->Primeiro_mov; // Insere o novo item no início da lista
            M->Primeiro_mov = P;              // Atualiza o primeiro item da lista para o novo item
        }
    }
}

// Função para consultar movimentações de estoque
// Declaração da função no início do arquivo
void telaConsMov();  /// chat gpt
void telaProduto();  /// chat gpt
void telaconsulta(); /// chat gpt

// Função para consulta de movimentação de estoque
void ConsultaMov(TipoLista *L, TipoLista_mov *M)
{
    TipoApontador_mov P;      // Ponteiro para percorrer a lista de movimentações
    TipoApontador aux1;       // Ponteiro auxiliar para pesquisa na lista de produtos
    reg_movimentacao reg_mov; // Estrutura para dados da movimentação
    reg_produto reg_prod;     // Estrutura para dados do produto
    int resp;                 // Variável para resposta do usuário
    int aux;                  // Variável auxiliar para controle do loop
    int lin;                  // Variável para controle da linha na tela

    do
    {
        tela(); // Limpa a tela e redefine os cabeçalhos
        gotoxy(40, 3);
        printf("CONSULTAR MOVIMENTAÇÃO");
        telaConsMov(); // Exibe a tela específica para consulta de movimentação
        lin = 7;
        gotoxy(10, 5);
        scanf("%d", &reg_prod.cd_produto);
        aux = 0;
        aux1 = pesquisa(L, reg_prod.cd_produto); // Busca o produto na lista principal
        if (aux1 == NULL)
        {
            gotoxy(8, 29);
            printf("               ");
            gotoxy(8, 29);
            printf("Produto não Cadastrado");
            getch(); // Aguarda o usuário pressionar uma tecla
            gotoxy(8, 29);
            printf("               ");
        }
        else
        {
            reg_prod = aux1->conteudo; // Obtém os dados do produto encontrado
            gotoxy(42, 6);
            printf("%s", reg_prod.nm_produto);
            aux = 1; // Define que o produto foi encontrado e pode sair do loop
        }
    } while (aux != 1); // Repete enquanto o produto não estiver cadastrado

    P = M->Primeiro_mov; // Inicia a partir do primeiro elemento da lista de movimentações
    while (P != NULL)
    {
        reg_mov = P->conteudo_mov;                      // Obtém os dados da movimentação
        if (reg_mov.cd_prod_mov == reg_prod.cd_produto) // Verifica se a movimentação é do produto consultado
        {
            lin = lin + 2; // Avança duas linhas para cada movimentação exibida
            gotoxy(2, lin);
            printf("%s", reg_mov.dt_mov); // Exibe a data da movimentação
            gotoxy(12, lin);
            printf("%s", reg_mov.tp_mov); // Exibe o tipo de movimentação (E - entrada, S - saída)
            gotoxy(21, lin);
            printf("%6.2f", reg_mov.qt_mov); // Exibe a quantidade movimentada
            gotoxy(31, lin);
            printf("%6.2f", reg_mov.vl_unit_mov); // Exibe o valor unitário da movimentação
            gotoxy(42, lin);
            printf("%6.2f", reg_mov.vl_total_mov); // Exibe o valor total da movimentação
            gotoxy(54, lin);
            printf("%6.2f", reg_mov.qtd_estoque); // Exibe a quantidade de estoque após a movimentação
            gotoxy(64, lin);
            printf("%6.2f", reg_mov.customed_mov); // Exibe o custo médio após a movimentação
            gotoxy(74, lin);
            printf("%6.2f", reg_mov.vl_final); // Exibe o valor final do estoque após a movimentação
        }
        P = P->proximo_mov; // Avança para o próximo elemento da lista de movimentações
    }

    // Pergunta ao usuário se deseja gravar os dados da consulta
    gotoxy(8, 29);
    printf("Deseja gravar os dados (1 - SIM; 2 - NAO)..: ");
    scanf("%d", &resp);
}

// Implementação da função telaConsMov
void telaConsMov()
{
    tela();
    gotoxy(30, 03);
    printf("Consultar Produto");
    gotoxy(01, 04);
    printf("+------------------------------------------------------------------------------+\n");
    gotoxy(02, 05);
    printf("Data | Tipo   | Quant | VL.Unit | VL.Total  | Quant.Estoque | Custo.Medio ");
    gotoxy(01, 06);
    printf("+--- ------------------------ ------ ------------ ------- --------- -----------+\n");
}

// Função para o menu de movimentação de estoque
void MovEstoque(TipoLista *L, TipoLista_mov *M)
{
    int opc; // Variável para armazenar a opção do usuário
    do
    {
        tela(); // Limpa a tela e redefine os cabeçalhos
        gotoxy(30, 03);
        printf("MENU MOVIMENTACAO DE ESTOQUE");
        gotoxy(20, 10);
        printf("1 - Cadastrar Movimentacao de Estoque");
        gotoxy(20, 12);
        printf("2 - Listar Movimentacao de Estoque");
        gotoxy(20, 14);
        printf("3 - Retornar ao Menu Principal");
        gotoxy(8, 23);
        printf("Digite sua opcao..:");
        scanf("%d", &opc); // Lê a opção do usuário

        // Executa a função correspondente à opção escolhida
        switch (opc)
        {
        case 1:
            cadastrarMov(L, M); // Chama a função para cadastrar movimentação de estoque
            break;

        case 2:
            ConsultaMov(L, M); // Chama a função para listar movimentação de estoque
            break;

        default:
            break; // Se a opção for inválida, não faz nada
        }
    } while (opc < 3); // Repete o loop enquanto a opção for menor que 3
    // A opção 3 retorna ao menu principal e sai do loop
}

// Função do Submenu para Consultar Produto
void menu_consultar(TipoLista *L)
{
    int opc; // Variável para armazenar a opção do usuário

    do
    {
        tela(); // Limpa a tela e redefine os cabeçalhos
        gotoxy(40, 3);
        printf("CONSULTAR PRODUTO");
        gotoxy(20, 8);
        printf("1 - Consultar Fichário do Produto Geral"); // Opção 1: Consulta geral do fichário
        gotoxy(20, 9);
        printf("2 - Consultar em Ordem de Código"); // Opção 2: Consulta ordenada por código
        gotoxy(20, 10);
        printf("3 - Consultar em Ordem Alfabética"); // Opção 3: Consulta ordenada alfabeticamente
        gotoxy(20, 11);
        printf("4 - Consultar Código Específico"); // Opção 4: Consulta por código específico
        gotoxy(20, 12);
        printf("5 - Retornar ao Menu Principal"); // Opção 5: Retorna ao menu principal
        gotoxy(8, 23);
        printf("Digite sua opção..:"); // Solicita ao usuário que insira a opção
        scanf("%d", &opc);             // Lê a opção do usuário

        switch (opc)
        {
        case 1:
            consultarFichario(L); // Chama a função para consultar o fichário geral
            break;

        case 2:
            ordenarCodigo(L); // Chama a função para consultar produtos em ordem de código
            break;

        case 3:
            consultarOrdemNome(L); // Chama a função para consultar produtos em ordem alfabética
            break;

        case 4:
            consultaCodigo(L); // Chama a função para consultar um produto específico pelo código
            break;

        default:
            break; // Se a opção for 5 ou outra fora do escopo, sai do switch
        }
    } while (opc < 5); // Repete o loop enquanto a opção for menor que 5
}

// Menu de Produto
void MenuProduto(TipoLista *L)
{
    int opc; // Variável para armazenar a opção do usuário

    do
    {
        tela(); // Limpa a tela e redefine os cabeçalhos
        gotoxy(30, 3);
        printf("MENU PRODUTO");
        gotoxy(20, 8);
        printf("1 - Cadastrar Produto no Início da Lista"); // Opção 1: Cadastrar produto no início da lista
        gotoxy(20, 9);
        printf("2 - Cadastrar Produto no Final da Lista"); // Opção 2: Cadastrar produto no final da lista
        gotoxy(20, 10);
        printf("3 - Cadastrar Produto em uma Posição da Lista"); // Opção 3: Cadastrar produto em uma posição específica
        gotoxy(20, 11);
        printf("4 - Remover Produto no Início da Lista"); // Opção 4: Remover produto do início da lista
        gotoxy(20, 12);
        printf("5 - Remover Produto no Final da Lista"); // Opção 5: Remover produto do final da lista
        gotoxy(20, 13);
        printf("6 - Remover Produto na Posição da Lista"); // Opção 6: Remover produto de uma posição específica
        gotoxy(20, 14);
        printf("7 - Consultar todos os Produtos"); // Opção 7: Consultar todos os produtos
        gotoxy(20, 15);
        printf("8 - Alterar dados do Produto"); // Opção 8: Alterar dados de um produto
        gotoxy(20, 16);
        printf("9 - Retornar ao Menu Principal"); // Opção 9: Retornar ao menu principal
        gotoxy(8, 23);
        printf("Digite sua opção..:"); // Solicita ao usuário que insira a opção
        scanf("%d", &opc);             // Lê a opção do usuário

        switch (opc)
        {
        case 1:
            cadastrarInicio(L); // Chama a função para cadastrar produto no início da lista
            break;

        case 2:
            cadastrarFinal(L); // Chama a função para cadastrar produto no final da lista
            break;

        case 3:
            cadastrarPosicao(L); // Chama a função para cadastrar produto em uma posição específica
            break;

        case 4:
            removerInicio(L); // Chama a função para remover produto do início da lista
            break;

        case 5:
            removerFinal(L); // Chama a função para remover produto do final da lista
            break;

        case 6:
            removerPosicao(L); // Chama a função para remover produto de uma posição específica
            break;

        case 7:
            menu_consultar(L); // Chama o submenu para consultar produtos
            break;

        case 8:
            alterarProduto(L); // Chama a função para alterar os dados de um produto
            break;

        default:
            break; // Se a opção for 9 ou outra fora do escopo, sai do switch
        }
    } while (opc < 9); // Repete o loop enquanto a opção for menor que 9
}

// Tela Cadastra Produto
void CadastrarProduto()
{

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
}

// Consultar Tela
void Consultar()
{

    tela();
    gotoxy(30, 03);
    printf("Consultar Produto");
    gotoxy(01, 04);
    printf("+------------------------------------------------------------------------------+\n");
    gotoxy(02, 05);
    printf("ID | Descricao do Produto   | Uind | Data Valid | Qtde  | VL.Unit | VL Total");
    gotoxy(01, 06);
    printf("+--- ------------------------ ------ ------------ ------- --------- -----------+\n");
}

// Consultar Movimentacao Tela

// Tela de movimentacao
void MovmentacaoTela()
{

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
}

// Função Principal
int main()
{
    int opc;         // Variável para armazenar a opção do usuário
    TipoLista L;     // Lista de produtos
    TipoLista_mov M; // Lista de movimentações de estoque

    // Inicializa a lista de produtos
    L.Primeiro = NULL;
    L.Ultimo = NULL;

    // Inicializa a lista de movimentações de estoque
    M.Primeiro_mov = NULL;
    M.Ultimo_mov = NULL;

    // Define o local para o português brasileiro
    setlocale(LC_ALL, "portuguese-brazilian");

    // Leitura de arquivo (comentado)
    // le_arquivo(&L);

    // Loop para exibição do menu principal até o usuário escolher finalizar
    do
    {
        tela(); // Limpa a tela e redefine os cabeçalhos
        gotoxy(42, 03);
        printf("MENU PRINCIPAL");
        gotoxy(20, 10);
        printf("1 - Menu Cadastro de Produto"); // Opção 1: Menu de Cadastro de Produto
        gotoxy(20, 12);
        printf("2 - Menu Movimentação de Estoque"); // Opção 2: Menu de Movimentação de Estoque
        gotoxy(20, 14);
        printf("3 - Finalizar o Programa"); // Opção 3: Finalizar o Programa
        gotoxy(8, 23);
        printf("Digite sua opção..:"); // Solicita ao usuário que insira a opção
        scanf("%d", &opc);             // Lê a opção do usuário

        // Executa a função correspondente à opção escolhida pelo usuário
        switch (opc)
        {
        case 1:
            MenuProduto(&L); // Chama o menu de cadastro de produto
            break;

        case 2:
            MovEstoque(&L, &M); // Chama o menu de movimentação de estoque
            break;

        default:
            break; // Se a opção for 3 ou outra fora do escopo, sai do switch
        }

    } while (opc < 3); // Repete o loop enquanto a opção for menor que 3 (diferente de "Finalizar o Programa")

    // Grava os dados no arquivo (comentado)
    // gravar(&L);

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}