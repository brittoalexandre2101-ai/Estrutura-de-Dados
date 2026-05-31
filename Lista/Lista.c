#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//   REVISÃO DE LISTA ENCADEADA
/*
    Primeiro, lista encadeada é uma sequência de 'nós', onde cada nó aponta para o próximo.
    Ela tem possui uma cabeça(que é o primeiro nó da nossa lista) e uma cauda(que é o último nó da nossa lista).
*/

typedef struct No
{
    int valor;       // Valor que representa o elemento da lista.
    struct No *prox; // Função que que faz o nó apontar pro proximo, atraves do ponteiro '*prox'.
} no;

typedef struct Lista
{
    no *cabeca;  // Representa o início da lista.
    no *cauda;   // Representa o final da lista.
    int tamanho; // Representa o tamanho da lista.
} Lista;

struct No *criarNo(int valor) // Função para criar um novo nó
{
    struct No *novoNo = (struct No *)malloc(sizeof(struct No));
    if (novoNo == NULL)
    { // Se o nó for igual a vazio apenas retorna.
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

/*
    Numa lista podemos inserir e remover tanto nao cabeça, quanto na cauda,
    quanto em posição arbitrária. Irei inserir e remover em posição arbitrária,
    pois podemos ver como funcionaria uma inserção e remoção em todas as áreas.
*/

void inserirEmPosicao(struct Lista *lista, int valor, int posicao)
{
    struct No *novoNo = criarNo(valor);
    // Posição que não existe na nossa lista
    if (posicao < 0 || posicao > lista->tamanho)
    {
        printf("Posição inválida. Não é possível inserir %d na posição %d.\n", valor, posicao);
        return;
    }

    // Se a o tamanho da lista for 0, equivale a uma INSERÇÃO na cabeça
    if (posicao == 0)
    {
        // Lista de tamanho 0.
        if (lista->tamanho == 0)
        {
            lista->cabeca = novoNo;
            lista->cauda = novoNo;
        }
        // Atualiza a cabeça com o novo nó
        else
        {
            novoNo->prox = lista->cabeca;
            lista->cabeca = novoNo;
        }
        lista->tamanho++; // Incrementa a lista
        return;
    }
    // Se a posição for igual ao tamanho da lista, equivale a uma INSERÇÃO na cauda
    if (posicao == lista->tamanho)
    {
        // Lista de tamanho 0.
        if (lista->tamanho == 0)
        {
            lista->cabeca = novoNo;
            lista->cauda = novoNo;
        }
        // Atualiza a cauda com o novo nó.
        else
        {
            lista->cauda->prox = novoNo;
            lista->cauda = novoNo;
        }
        lista->tamanho++; // Incrementa a lista
        return;
    }
    struct No *atual = lista->cabeca;
    // Procura a posição que queremos inserir
    for (int i = 0; i < posicao; i++)
    {
        atual = atual->prox;
    }

    novoNo->prox = atual->prox;
    atual->prox = novoNo;
    lista->tamanho++;
}

void removerEmPosicao(struct Lista *lista, int posicao)
{
    // Tentando remover em posição que não existe
    if (lista == NULL)
    {
        return;
    }
    // Se a o tamanho da lista for 0, equivale a uma REMOÇÃO na cabeça
    if (posicao == 0)
    {
        struct No *temp = lista->cabeca;
        lista->cabeca = lista->cabeca->prox;
        if (lista->cabeca == NULL)
        { // Se a lista ficou vazia após a remoção
            lista->cauda = NULL;
        }
        lista->tamanho--;
        free(temp);
        return;
    }
    // Se a posição for igual ao tamanho da lista, equivale a uma REMOÇÃO na cauda
    if (posicao == lista->tamanho - 1)
    {
        no *antiga_cauda = lista->cauda; // Guarda pra liberar depois
        // Se o tamanho da lista for igual a 1, equivale a uma remoção na cabeça
        if (lista->tamanho == 1)
        {
            lista->cabeca = NULL;
            lista->cauda = NULL;
        }
        else
        {
            no *atual = lista->cabeca;
            while (atual->prox != lista->cauda)
            {
                atual = atual->prox;
            }
            lista->cauda = atual;
            lista->cauda->prox = NULL;
        }
        free(antiga_cauda);
        lista->tamanho--;
        return;
    }

    // Remoção em posição arbitrária
    no *aux = lista->cabeca;
    for (int j = 0; j < posicao - 1; j++)
    {
        aux = aux->prox;
    }
    no *remove = aux->prox;
    aux->prox = remove->prox;
    free(remove);
    lista->tamanho--;
}