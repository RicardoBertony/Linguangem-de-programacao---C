#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char palavra[20];
    char frase[500];
    char fraseAuxiliar[500];
    int a, i = 0, k = 0, contapalavra = 0, contacaractere = 0, asteriscos, tam;

    printf("digite uma palavra: ");
    gets(palavra);
    printf("digite uma frase: ");
    gets(frase);
    strcpy(fraseAuxiliar, frase);

    while(frase[i] != '\0') //percorre a frase
    {
        a = i;                  // vari�vel auxilar para o valor de i
        while(palavra [k] != '\0') //percorre a palavra avan�ando o indice somente se houver igualdade
        {
            if(palavra [k] == frase[a])
            {
                contacaractere++;
                a++;
                k++;
                if( contacaractere == strlen(palavra)) //verifica se a quantidade de caracteres identicos e consecultivos � do tamanho da palavra
                {
                    contapalavra++; //incrementa esse contador caso a condi��o anterior seja satisfeita
                    contacaractere = 0;
                    k = 0;
                    i ++;
                    asteriscos = a - 1;
                    tam = strlen(palavra);
                    for (; tam > 0; tam--) //coloca asteriscos na frase reserva
                    {
                        fraseAuxiliar[asteriscos] ='*';
                        asteriscos--;
                    }
                    break;
                }
            }
            else
            {
                contacaractere = 0; // se n�o...zera o contacaractere. A compara��o retorna ao while mais externo partindo do proximo indice da frase
                i++;
                k = 0;
                break;  // interompe a itera��o do while mais interno. A compara��o retorna ao primeiro indice da palavra
            }
        }
    }
    printf("\n");
    printf("a palavra '%s' estah %dx na frase '%s'", palavra, contapalavra, frase); //imprime a quantidade de 'palavra' encontrada na string
    printf("\n");
    printf("A frase com asteriscos: %s", fraseAuxiliar);
    printf("\n");
    return 0;
}
