
/*************************************************************************************************************************************************************************************************
UNIVERSIDADE FEDERAL DO MARANHAO
CENTRO DE CIENCIAS EXATAS E TECNOLOGIAS
LINGUAGEM DE PROGRAMACAO C
PROFESSOR: ARISTOFANES CORREA

Descricao: encontra palindromos nas colunas de uma matriz. Astericos são colocados nas colunas onde não há ocorrência de palindromo
Autor: Ricardo Bertony                      09/06/2022

**************************************************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHA 50
#define COLUNA 50

int main()
{
    char matriz[LINHA][COLUNA];
    char matrizAUX[LINHA][COLUNA];
    char palavra[50];
    char comparador[50]; // variavel que armazenarah temporiamente os caracteres das COLUNAS da matriz
    char comparadorREVERSO[50];
    int i, j, k = 0, v = 0, x, linhas, colunas, tam;

    printf("Dimensoes da matriz\n");
    printf("Quantidade de linhas: ");
    scanf(" %d", &linhas);
    fflush(stdin);
    printf("Quantidade de colunas: ");
    scanf(" %d", &colunas);
    fflush(stdin);
    printf("\n");

    // LEITURA DOS CARACTERES DA MATRIZ
    for(i = 0; i < linhas; i++)
    {
        printf("Linha %d:\n", i+1);
        for(j = 0; j < colunas; j++)
        {
            printf("Digite o caractere [%d, %d]: ", i+1, j+1);
            scanf(" %c", &matriz[i][j]);
            fflush(stdin);
        }
    }
    printf("\n");

    //IMPRESSAO DA MATRIZ
    printf("A matriz digitada: \n");
     for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    //ANALISANDO AS COLUNAS DA MATRIZ EM BUSCA DE PALINDROMOS DE ATE 3 CARACTERES
    for(j= 0; j < colunas;j++)
    {
        v = 0;
        x = 0;
        k = 0; //comeco da string de comparacao
        while(k < linhas) //armazenarah os caracteres das colunas da matriz em um vetor
        {
            comparador[k] = matriz[k][j];
            k++;
        }
        comparador[k] = '\0'; //limite para o fim da palavra
        tam = strlen(comparador) - 1;

        while(v < linhas)//armazerah um vetor espelhado do comparador - de tras para frente
        {
            comparadorREVERSO[v] = comparador[tam];
            v++;
            tam--;
        }
        comparadorREVERSO[v] = '\0'; //limite para o fim da palavra inversa

        if(strcmp(comparador,comparadorREVERSO) == 0)//eh palindromo
          {
            do
            {
            matrizAUX[x][j] = comparador[x];
            x++;
            }while(x < linhas);
          }
          else //nao eh palindromo - coloca asteriscos
          {
            do
            {
            matrizAUX[x][j]= '*';
            x++;
            }while(x < linhas);
          }
    }
    //impressao da matriz apos analise
    printf("\nA matriz analisada:\n");
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
           {
             printf("%c ", matrizAUX[i][j]);
           }
        printf("\n");
    }

    return 0;
}
