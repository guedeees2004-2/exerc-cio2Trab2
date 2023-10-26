#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** criaSenhas (char** vetorStrings, int qtdElementos)
{
    char** senhas = (char**) malloc(sizeof(char*) * qtdElementos);
    if (senhas == NULL)
    {
        printf("Errona alocacao de memoria!\n");
        return 0;
    }

    // todos elementos são NULL de "Senhas"
    for (int i = 0; i < qtdElementos; i++)
    {
        senhas[i] = NULL;
    }

    // copia os elementos não nulos de "vetorStrings" para "senhas"
    for (int i = 0; i < qtdElementos; i++)
    {
        if (vetorStrings[i] != NULL)
        {
            senhas[i] = (char*) malloc(sizeof(char) * (strlen(vetorStrings[i]) + 1));
            strcpy(senhas[i], vetorStrings[i]);
        }
    }
    return senhas;
}

char* valida(char** vetor, int tamanho, int usuario)
{
    int qtdNum = 0;
    for (int i = 0; i < strlen(vetor[usuario]); i++)
    {
        if (isdigit(vetor[usuario][i]))
            qtdNum++;
    }
    if (qtdNum == 0)
        return ("Senha invalida");
    else
        return ("Senha valida");
}

void eliminaSenha(char** vetor, int usuario)
{
    free(vetor[usuario]);
    vetor[usuario] = NULL;
}

void eliminaTodos(char** vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        eliminaSenha(vetor, i);
    }
}

void printVetor(char** vetor, int qtdElementos)
{
    for (int i = 0; i < qtdElementos; i++)
    {
        if (vetor[i] == NULL)
            printf("NULL, ");
        else
            printf("\"%s\", ", vetor[i]);
    }
}

int main(void)
{
    char* vetorSenhas[] =  {"an5a",NULL,"puc","9casa"};
    int tamanho = sizeof(vetorSenhas) / sizeof(vetorSenhas[0]);
    char** senhas = criaSenhas(vetorSenhas, tamanho);
    
    printf("Suas senhas sao:\n");
    printVetor(senhas, tamanho);
    printf("\n");
    printf("%s", valida(vetorSenhas, tamanho, 2));

    printf("\n");
    eliminaTodos(senhas, tamanho);
    printVetor(senhas, tamanho);
    return 0;
}