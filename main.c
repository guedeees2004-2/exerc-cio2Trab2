#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** criaSenhas (char** vetorStrings, int qtdElementos)
{
    char** senhas = (char**) malloc(sizeof(char*) * qtdElementos);
    if (senhas == NULL)
    {
        printf("Erro: Memoria insuficiente!\n");
        return 0;
    }

    for (int i = 0; i < qtdElementos; i++)
    {
        if (vetorStrings[i] != NULL)
        {
            senhas[i] = (char*) malloc(sizeof(char) * (strlen(vetorStrings[i]) + 1));
            if (senhas[i] == NULL)
            {
                printf("Erro: Memoria insuficiente!\n");
                return 0;
            }
            strcpy(senhas[i], vetorStrings[i]);
        }
    }
    return senhas;
}

int main(void)
{
    char* vetorSenhas[] =  {"an5a",NULL,"puc","9casa"};
    int tamanho = sizeof(vetorSenhas) / sizeof(char*);
    char** senhas = criaSenhas(vetorSenhas, tamanho);
    
    printf("Suas senhas sao:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", senhas[i]);
    }

    return 0;
}