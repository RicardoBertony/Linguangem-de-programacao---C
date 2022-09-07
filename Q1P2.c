/*************************************************************************************************************************************************************************************************
UNIVERSIDADE FEDERAL DO MARANHAO
CENTRO DE CIENCIAS EXATAS E TECNOLOGIAS
LINGUAGEM DE PROGRAMACAO C
PROFESSOR: ARISTOFANES CORREA

Descricao: verifica maximos globais de uma matriz, no minimo 3x3, dada pelo usuario
Autor: Ricardo Bertony                      07/07/2022         v1.9

**************************************************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define LINHA 100
#define COLUNA 100

void submatriz(int[LINHA][COLUNA], int[LINHA], int[LINHA], int[LINHA], int[LINHA],  int, int);

void maximo(int [LINHA], int [LINHA][COLUNA], int[LINHA], int[LINHA], int[LINHA], int, int);

void Supremo(int[LINHA], int[LINHA]);


int main()
{
    int matriz[LINHA][COLUNA];
    int maximo_local[LINHA];
    int maximoglobal[LINHA];
    int endereco[LINHA];
    int contamax[LINHA];
    int linhas, colunas;

    printf("Dimensoes da matriz:\n");
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    fflush(stdin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    fflush(stdin);

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("Digite o elemtento [%d, %d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            fflush(stdin);
        }
    }

    printf("\nA matriz digitada:\n");
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    submatriz(matriz, maximo_local, maximoglobal, endereco, contamax, linhas, colunas);

    if (linhas >= 3 && colunas >=3)
    {
        Supremo(maximoglobal, contamax);
    }
    else
    {
        printf("\nAs dimensoes inseridas nao comportam maximos!\n");
    }

    return 0;
}

//FUNCAO QUE GERA SUBMATRIZES DA MATRIZ PRINCIPAL
void submatriz(int matrix[LINHA][COLUNA], int max[LINHA], int maximoglobal[LINHA],int endereco[LINHA], int contamax[LINHA], int linhas, int colunas)
{
    int i, j, c, r, limite_linha, limite_coluna, aux_linha, aux_coluna;

    for(i = 0; i < linhas - 2; i++)
    {
        for(j = 0; j < colunas - 2; j++)
        {
            limite_linha = i + 2;

            limite_coluna = j + 2;

            c = 0;
            r = 0;

            for(aux_linha = i; aux_linha <= limite_linha; aux_linha++)
            {
                for(aux_coluna = j; aux_coluna <= limite_coluna; aux_coluna++)
                {
                    max[c] = matrix[aux_linha][aux_coluna];
                    if(c == 4)
                    {
                        endereco[r] = aux_linha;
                        r++;
                        endereco[r] = aux_coluna;
                    }
                    c++;
                }
            }
            maximo(max, matrix, maximoglobal, endereco, contamax, linhas, colunas);
        }
    }
}
//FUNCAO QUE ANALISA O PRETENSO MAXIMO LOCAL
void maximo(int maximo_local[LINHA], int matriz[LINHA][COLUNA], int maximo_global[LINHA], int endereco[LINHA], int contamax[LINHA], int linhas, int colunas)
{
    int i, j, candidato, contagem = 0;
    static int contamaximos = 0;
    static int iteracao = 0;
    static int q = 0;

    candidato = maximo_local[4]; //posicao do pretenso maximo

    for(int i = 0; i < 9;)
    {
        if(i == 4)
        {
            i++;
        }
        if(candidato > maximo_local[i])
        {
            contagem++;
            i++;
        }
        else
        {
            break;
        }
    }

    if(contagem == 8)//candidato eh maximo local
    {
       if(iteracao == 0)
       {
            iteracao++;
            printf("%d (%d, %d) ", candidato, endereco[0]+1, endereco[1]+1);
            maximo_global[q] = candidato;
            q++;
            contamaximos++;
       }
       else
       {
            printf("- %d (%d, %d) ", candidato, endereco[0]+1, endereco[1]+1);
            maximo_global[q] = candidato;
            q++;
            contamaximos++;
       }
    }
    contamax[0] = contamaximos;//armazena a quantidade de maximos
}
//ANALISANDO O MAXIMOS LOCAIS
void Supremo(int maximo_global[LINHA], int contamaximos[LINHA])
{
 int supremo, limite;

 limite = contamaximos[0];

 supremo = maximo_global[0];

 for(int p = 0; p <= limite; p++)
 {
    if(supremo < maximo_global[p])
    {
       supremo = maximo_global[p];
    }
 }

 printf("\nMaximo global: %d\n", supremo);

}







