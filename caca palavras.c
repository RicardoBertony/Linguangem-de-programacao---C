/*************************************************************************************************************************************************************************************************
UNIVERSIDADE FEDERAL DO MARANHAO
CENTRO DE CIENCIAS EXATAS E TECNOLOGIAS
LINGUAGEM DE PROGRAMACAO C
PROFESSOR: ARISTOFANES CORREA

Descricao: o programa deve encontrar uma palavra qualquer, dada pelo usuario, em uma matriz de caracteres, tambem dada pelo usuario.
Autor: Ricardo Bertony                      08/06/2022         v1.3

**************************************************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHA 50
#define COLUNA 50

int main()
{
    char matriz[LINHA][COLUNA];
    char palavra[50];
    char comparador[50]; // variavel que armazenarah temporiamente os caracteres das linhas da matriz
    int i, j, k = 0, x, v = 0, controle = 1,  w, linhas, colunas, contacaractere, contapalavra;

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

    do
    {
        //LEITURA DA PALAVRA CANDIDATA
        printf("\nDigite uma palavra: ");
        gets(palavra);

        //VERIFICANDO QUANTAS VEZES A PALAVRA ESTAH EM CADA LINHA DA MATRIZ
        printf("\nNas linhas:\n");
        for(i = 0; i < linhas;)
        {
            contacaractere = 0;
            contapalavra = 0;
            v = 0;
            w = 0;
            k = 0; //comeco da string de comparacao
            while(k < colunas) //armazenarah os caracteres da linhas da matriz em um vetor
            {
                comparador[k] = matriz[i][k];
                k++;
            }
            comparador[k] = '\0'; //limite para o fim da palavra
            while(comparador[w] != '\0')//comparador eh uma string
            {
                x = w;
                while(palavra[v] != '\0')
                {
                    if(palavra[v] == comparador[x])
                    {
                        v++;
                        x++;
                        contacaractere++;
                        if( contacaractere == strlen(palavra)) //verifica se a quantidade de caracteres identicos e consecultivos é do tamanho da palavra
                        {
                            contapalavra++; //incrementa esse contador caso a condição anterior seja satisfeita
                            contacaractere = 0;
                            v = 0;
                            w ++;
                            break;
                        }
                    }
                    else
                    {
                        contacaractere = 0; // se não...zera o contacaractere. A comparação retorna ao while mais externo partindo do proximo indice da frase
                        w++;
                        v = 0;
                        break;  // interompe a iteração do while mais interno. A comparação retorna ao primeiro indice da palavra
                    }
                }

            }
            i++; //passa para a prohxima linha
            printf("\nA palavra '%s' estah %dx na linha %d", palavra, contapalavra, i); //imprime a quantidade de 'palavra' encontrada na string
            contapalavra = 0;
            contacaractere = 0; //zera e passa para a proxima linha
        }
        printf("\n");

        //ANALISANDO AS COLUNAS DA MATRIZ - procedendo tal como fora feito nas linhas
        //VERIFICANDO QUANTAS VEZES A PALAVRA ESTAH EM CADA COLUNA DA MATRIZ
        printf("\nNas colunas:\n");
        for(j= 0; j < colunas;)
        {
            contacaractere = 0;
            contapalavra = 0;
            v = 0;
            w = 0;
            k = 0; //comeco da string de comparacao
            while(k < linhas) //armazenarah os caracteres das colunas da matriz em um vetor
            {
                comparador[k] = matriz[k][j];
                k++;
            }
            comparador[k] = '\0'; //limite para o fim da palavra
            while(comparador[w] != '\0')//comparador eh uma string
            {
                x = w;
                while(palavra[v] != '\0')
                {
                    if(palavra[v] == comparador[x])
                    {
                        v++;
                        x++;
                        contacaractere++;
                        if( contacaractere == strlen(palavra)) //verifica se a quantidade de caracteres identicos e consecultivos é do tamanho da palavra
                        {
                            contapalavra++; //incrementa esse contador caso a condição anterior seja satisfeita
                            contacaractere = 0;
                            v = 0;
                            w ++;
                            break;
                        }
                    }
                    else
                    {
                        contacaractere = 0; // se não...zera o contacaractere. A comparação retorna ao while mais externo partindo do proximo indice da frase
                        w++;
                        v = 0;
                        break;  // interompe a iteração do while mais interno. A comparação retorna ao primeiro indice da palavra
                    }
                }

            }
            j++; //passa para a prohxima coluna
            printf("\nA palavra '%s' estah %dx na coluna %d", palavra, contapalavra, j); //imprime a quantidade de 'palavra' encontrada na string
            contapalavra = 0;
            contacaractere = 0; //zera e passa para a proxima coluna
        }
        printf("\n\nDigite '0' para sair ou '1' para inserir outra palavra:  ");
        scanf("%d", &controle);
        fflush(stdin);
    }
    while(controle != 0);
    printf("\n");
    return 0;
}
