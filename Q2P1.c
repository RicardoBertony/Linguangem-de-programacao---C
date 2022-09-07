/**********************************************************************************************************************************************************************
______________________________________________________________________________________________________________________________________________________________________
UNIVERSIDADE FEDERAL DO MARANHAO
CENTRO DE CIENCIAS EXATAS E TECNOLOGIAs
LINGUAGEM DE PROGRAMACAO C
PROFESSOR: Aristofanes Correa
Autor: Ricardo Bertony              09/06/2022              v1.2
Descrição: o programa ordena uma string de acordo com a ordem: numeros pares, impares, caracteres minusculos e, por fim, maiusculos. A tabela ASCII eh considerada.
______________________________________________________________________________________________________________________________________________________________________
***********************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char palavraALL[50]; //armazena todos os caracteres
    char palavraONLY[50]; //armazena somente os validos em ordem estabelecida
    char palavraNUMpar[50];//armazena caracteres que representam numeros PARES
    char palavraNUMimpar[50];//armazena caracteres que representam numeros IMPARES
    char palavraLETup[50]; //armazena caracteres alfabeticos maiusculos
    char palavraLETlow[50];//armazena caracteres alfabeticos minusculos
    int i, j = 0, k = 0, w = 0, v = 0, contador = 0, contaIMPAR = 0, contaPAR = 0, contaUP = 0, contaLOW = 0, contaALL;

    //FAZENDO A LEITURA DA PALAVRA
    printf("Digite uma string: ");
    gets(palavraALL);

    //CONTAGEM DOS CARACTERES DA STRING - LIMITE EM '\0'
    i = 0;
    while(palavraALL[i]!='\0')
    {
        contador++;
        i++;
    }

    //ARMAZENANDO OS CARACTERES QUE CORRESPONDEM A NUMEROS
    for(i = 0; i <= contador; i++)
    {
        if(48 <= palavraALL[i] &&  palavraALL[i]<= 57) //entao o caractere estah na faixa de caracteres numericos inteiros da tabela ASCII
        {
            if(palavraALL[i] % 2 == 0)// eh par
            {
                palavraNUMpar[j] = palavraALL[i];
                contaPAR++;
                j++;
            }
            else
            {
                palavraNUMimpar[k] = palavraALL[i];
                contaIMPAR++;
                k++;
            }
        }
    }

    //ARMAZENDO OS CARACTERES QUE CORRESPONDEM A LETRAS
    for(i = 0; i <= contador; i++)
    {
        if(65 <= palavraALL[i] && palavraALL[i] <= 90)//eh letra maiuscula
        {
            palavraLETup[w] = palavraALL[i];
            contaUP++;
            w++;
        }
        else if(97 <= palavraALL[i] &&  palavraALL[i] <= 122) //eh minuscula
        {
            palavraLETlow[v] = palavraALL[i];
            contaLOW++;
            v++;
        }
    }
    j = 0;
    k = 0;
    v = 0;
    w = 0;
    contaALL = contaPAR + contaIMPAR + contaUP + contaLOW; //a armazenara o limite do vetor palavraONLY

    //ORDENANDO O VETOR PALAVRAONLY
    for(i = 0; i <= contaALL;)
    {
        if(contaPAR != 0)//caso existam, armazena os pares no começo do vetor
        {
            while(contaPAR > 0)
            {
                palavraONLY[i] = palavraNUMpar[j];
                i++;
                j++;
                contaPAR--;
            }
        }
        else if(contaIMPAR != 0)//caso existam, armazena os impares sucedendo os pares do vetor
        {
            while(contaIMPAR > 0)
            {
                palavraONLY[i] = palavraNUMimpar[k];
                i++;
                k++;
                contaIMPAR--;
            }
        }
        else if(contaLOW != 0)//caso existam, armazena os caracteres minusculos sucedendo os numeros impares
        {
            while(contaLOW > 0)
            {
                palavraONLY[i] = palavraLETlow[v];
                i++;
                v++;
                contaLOW--;
            }
        }
        else if(contaUP != 0)//caso existam, armazena os caracteres maiusculos sucedendo os minusculos
        {
            while(contaUP > 0)
            {
                palavraONLY[i] = palavraLETup[w];
                i++;
                w++;
                contaUP--;
            }
        }
        else //palavraONLY[i] recebe o caractere 'vazio' caso o caractere digitado esteja fora do escopo de variaveis consideradas
        {
            palavraONLY[i] = 0;
            i++;
        }
    }
    printf("\nA palavra na ordem desejada eh:\n");
    printf("\n%s\n", palavraONLY);


    return 0;

}
