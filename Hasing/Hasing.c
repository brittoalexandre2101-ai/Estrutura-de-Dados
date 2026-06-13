#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura para os dados (Chave e Valor)
typedef struct No
{
    char chave[50];
    int valor;
    struct No *proximo;
} No;

// A Tabela Hash é um vetor de ponteiros para nós
No *tabela[TAMANHO_TABELA];

// Espalhamento
int funcao_hash(char *chave)
{
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
    {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

// Tratamento de Colisão por Encadeamento
void inserir(char *chave, int valor)
{
    int indice = funcao_hash(chave);

    // Criar novo nó
    No *novo_no = (No *)malloc(sizeof(No));
    strcpy(novo_no->chave, chave);
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    // Inserir no início da lista (encadeamento)
    if (tabela[indice] == NULL)
    {
        tabela[indice] = novo_no;
    }
    else
    {
        novo_no->proximo = tabela[indice];
        tabela[indice] = novo_no;
    }
}

// Buscando Elemento
int buscar(char *chave)
{
    int indice = funcao_hash(chave);
    No *atual = tabela[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
        {
            return atual->valor; // Chave encontrada
        }
        atual = atual->proximo;
    }
    return -1; // Chave não encontrada
}
