#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct bst_no
{
    int dado;
    struct bst_no *esquerda;
    struct bst_no *direita;
} bst_no;

typedef struct ArvoreBST
{
    bst_no *raiz;
    size_t tamanho;
} ArvoreBST;

static bool bst_encontrar_ajuda(bst_no *x, int dado);
bst_no *inserir_ajuda(bst_no *x, int dado);
static bst_no *remover_ajuda(bst_no *x, int dado);
static void deletar_ajuda(bst_no *x);

void iniciar(ArvoreBST **t)
{
    (*t) = malloc(sizeof(ArvoreBST));
    (*t)->tamanho = 0;
    (*t)->raiz = NULL;
}

// Cria um novo nó
static bst_no *novo_no(int dado)
{
    bst_no *ptr = malloc(sizeof(bst_no));
    ptr->esquerda = NULL;
    ptr->direita = NULL;
    ptr->dado = dado;
    return ptr;
}

// Deleta um nó
static void deletar_no(bst_no *no)
{
    free(no);
}

// Obtém o tamanho(número de nós) da árvore
size_t bst_tamanho(ArvoreBST *t)
{
    return t->tamanho;
}

// Devolve o nó mais a direita em uma subárvore com raiz em v
static bst_no *encontrar_maiorDireita(bst_no *v)
{

    if (v == NULL || v->direita == NULL)
    {
        return v;
    }
    else
    {
        return encontrar_maiorDireita(v->direita);
    }
}

// Devolve verdadeiro se e somente se o nó com a chave estipulada encontra-se na árvore
bool bst_encontrar(ArvoreBST *t, int dado)
{
    return bst_encontrar_ajuda(t->raiz, dado);
}

static bool bst_encontrar_ajuda(bst_no *x, int dado)
{
    if (x == NULL)
        return false;
    if (dado == x->dado)
        return true;
    if (dado < x->dado)
        return bst_encontrar_ajuda(x->esquerda, dado);
    return bst_encontrar_ajuda(x->direita, dado);
}

// Insere um nó
void inserir_bst(ArvoreBST *t, int dado)
{
    t->raiz = inserir_ajuda(t->raiz, dado);
    t->tamanho++;
}

bst_no *inserir_ajuda(bst_no *x, int dado)
{
    if (x == NULL)
        return novo_no(dado);
    assert(x->dado != dado);
    if (dado < x->dado)
    {
        x->esquerda = inserir_ajuda(x->esquerda, dado);
    }
    else
    {
        x->direita = inserir_ajuda(x->direita, dado);
    }
    return x;
}

void remover_bst(ArvoreBST *t, int dado)
{
    t->raiz = remover_ajuda(t->raiz, dado);
    t->tamanho--;
}

static bst_no *remover_ajuda(bst_no *x, int dado)
{
    assert(x != NULL);
    if (dado < x->dado)
    {
        x->esquerda = remover_ajuda(x->esquerda, dado);
    }
    else if (dado > x->dado)
    {
        x->direita = remover_ajuda(x->direita, dado);
    }
    else
    { // Remoção do nó
        if (x->esquerda == NULL)
        {
            bst_no *y = x->direita;
            deletar_no(x);
            x = y;
        }
        else if (x->direita == NULL)
        {
            bst_no *y = x->esquerda;
            deletar_no(x);
            x = y;
        }
        else
        {
            bst_no *anterior = encontrar_maiorDireita(x->esquerda);
            int aux = x->dado;
            x->dado = anterior->dado;
            anterior->dado = aux;
            x->esquerda = remover_ajuda(x->esquerda, anterior->dado);
        }
    }
    return x;
}

void deletar_bst(ArvoreBST **t)
{
    deletar_ajuda((*t)->raiz);
    free(*t);
    (*t) = NULL;
}

static void deletar_ajuda(bst_no *x)
{
    if (x != NULL)
    {
        deletar_ajuda(x->esquerda);
        deletar_ajuda(x->direita);
        deletar_no(x);
    }
}