#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

void SubPalavra(char [], char[], char []);
void isPalindromo(char [], char[]);

int main()
{
    char palavra[TAM], temporario[TAM], temporarioInvertido[TAM];

    printf("Digite uma palavra: ");
    gets(palavra);

    SubPalavra(palavra, temporario, temporarioInvertido);

    return 0;
}

void SubPalavra(char palavra[], char temporario[], char temporarioInvertido[])
{
   int i, limite, x;

    printf("\nPalindromos encontrados: \n");

    for(i = 0; i < strlen(palavra) - 2; i++)//fixa o inicio da string criada a partir de 'i'. Naturalmente, 'i' comeca em 0 - pelo inicio da palavra.
    {
        limite = i + 2; //considera uma palavra de, pelo menos, 3 caracteres: 0, 1, 2 - um caractere por indice

        while(limite < strlen(palavra))
        {
            //construindo a string da iesima iteracao do for mais externo
            for(x = 0; (x+i) <= limite; x++)
            {
                temporario[x] = palavra[x+i];
            }
            temporario[x] = '\0';

            isPalindromo(temporario, temporarioInvertido); // a funcao recebe a palavra contida em temporario da iesima iteracao de FOR
            limite++;
        }
    }
}

void isPalindromo(char temporario[], char temporarioInvertido[])
{
    int tam  = strlen(temporario) - 1, w;

    for( w = 0; tam >= 0; tam--) //construindo a string invertida de temporario
    {
        temporarioInvertido[w] = temporario[tam];
        w++;
    }
    temporarioInvertido[w] = '\0';

    if(strcmp(temporario, temporarioInvertido) == 0) //verifica se eh palindromo
    {
        printf("%s\n", temporario);
    }
}
