#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int main()
{
    char frase[TAM];
    char fraseA_Z[TAM];
    int indice[TAM];
    int i, j, limite = 0, aux;

    printf("Digite uma frase com letras minusculas:\n");
    gets(frase);

    i = 0;
    limite = 0;

    while (frase[i]) //frase != 0 dá TRUE
    {
        indice[i] = frase[i]; //atribui ao vetor indice cada inteiro correspondente ao caractere da tabela ASC
        i++;
        limite++; //conta a quantidade de caracteres da frase
    }

    //colocando o vetor de inteiros, indice, em ordem crescente
    for (i = 0; i < limite; i++ )
    {
        for(j = i + 1; j < limite; j++)
        {
            if( indice[i] > indice[j])  //SE ( I ) > ( J ) - EM TERMOS DE INDICE - ( I ) PASSA A SER O SUCESSOR E ( J ) O ANTECESSOR
            {
                aux = indice[i]; //VARIÁVEL AUXILIAR PARA NÃO PERDER O VALOR DE INDICE[I]
                indice[i] = indice[j];
                indice[j] = aux;
            }
        }
    }
    for (i = 0; i < limite; i++)
    {
        fraseA_Z[i] = indice[i]; //atribui ao vetor fraseA_Z o caractere que corresponde ao inteiro da tabela ASC
    }
    printf("\n");
    printf("\n");

    for (i = 0; i < limite; i++)
    {
        if( fraseA_Z[i] != ' ')
        {
            printf("%c", fraseA_Z[i]);
        }
        else
        {
            printf("*");
        }

    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");


    return 0;
}
