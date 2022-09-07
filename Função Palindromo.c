//Verifica se uma palavra constitui palindromo.
#include <stdio.h>
#include <stdlib.h>
#define TAM 100
int isPalindromo(char [TAM], char [TAM]);


int main()
{
    char  palavra[TAM];
    char palavraINVERTIDA[TAM];

    printf("Digite uma palavra: ");
    gets(palavra);

     if(isPalindromo(palavra, palavraINVERTIDA)) //passa, por referencia, os vetores contidos no argumento
    {
        printf("'%s' eh palindromo!", palavra);//Palindromica retorna 1 caso seja palindromo. Senao, 0
    }
    else
    {
        printf("'%s' nao eh palindromo!", palavra);
    }

    return 0;
}

//A FUNCAO QUE ANALISA A PALAVRA
int isPalindromo(char palavra[], char palavraINVERTIDA[]) //a funcao recebe os vetores por referencia ao endereco do primeiro indice
{
    int aux, tam, i = 0, igualdades = 0;

    while(palavra[i] != '\0') //contando os caracteres da palavra
    {
        tam++;
        i++;
    }
     aux = tam;

    for(i = 0;  tam > 0;)//invertendo a palavra
    {
        palavraINVERTIDA[i] = palavra[tam-1];
        tam--;
        i++;
    }

    for(i = 0; i < aux; i++) //verificando se todos os caracteres das palavras sao identicos
    {
        if(palavra[i] == palavraINVERTIDA[i])
        {
            igualdades++;
        }
    }

    if(igualdades == aux) //verificando se a quantidade de igualdades tem o tamanho da palavra
    {
       return 1;
    }
    else
    {
        return 0;
    }
}
