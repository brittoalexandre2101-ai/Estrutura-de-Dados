#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct arvore_no
{
    int dado;
    struct arvore_no *esquerda;
    struct arvore_no *direita;
} arvore_no;

typedef struct arvore
{
    arvore_no *raiz;
} arvore;

typedef struct fila
{
    size_t frente, traz, tamanho, capacidade;
    arvore_no **fila;
} fila;

void iniciar(fila **f)
{
    (*f) = malloc(sizeof(fila));
    (*f)->frente = (*f)->traz = (*f)->tamanho = 0;
    (*f)->capacidade = 1000000;
    (*f)->fila = malloc(sizeof(arvore_no *) * 1000000);
}

void empurrarFila(fila *f, arvore_no *dado)
{
    if (f->tamanho == f->capacidade)
        return;
    f->fila[f->traz] = dado;
    f->traz++;
    if (f->traz == f->capacidade)
        f->traz = 0;
    f->tamanho++;
}

arvore_no *puxarFila(fila *f)
{
    arvore_no *aux = f->fila[f->frente];
    f->frente++;
    f->tamanho--;
    if (f->frente == f->capacidade)
        f->frente = 0;
    return aux;
}

typedef struct pilha
{
    size_t topo, tamanho, capacidade;
    arvore_no **pilha;
} pilha;

void iniciar_pilha(pilha **p)
{
    (*p) = malloc(sizeof(pilha));
    (*p)->topo = (*p)->tamanho = 0;
    (*p)->capacidade = 1000000;
    (*p)->pilha = malloc(sizeof(arvore_no *) * 1000000);
}

void empurrar_pilha(pilha *p, arvore_no *dado)
{
    if (p->tamanho == p->capacidade)
        return;
    p->pilha[p->tamanho] = dado;
    p->tamanho++;
}

arvore_no *topo_pilha(pilha *p)
{
    if (p->tamanho == 0)
        return NULL;
    return p->pilha[p->tamanho - 1];
}

arvore_no *puxar_pilha(pilha *p)
{
    if (p->tamanho == 0)
        return NULL;
    p->tamanho--;
    return p->pilha[p->tamanho];
}

void busca_largura(arvore *t)
{
    if (t->raiz == NULL)
        return;
    fila *f;
    iniciar(&f);
    empurrarFila(f, t->raiz);
    while (f->tamanho > 0)
    {
        arvore_no *no = puxarFila(f);
        printf("%d\n", no->dado);
        if (no->esquerda != NULL)
            empurrarFila(f, no->esquerda);
        if (no->direita != NULL)
            empurrarFila(f, no->direita);
    }
}

void busca_profundidade(arvore *t)
{
    if (t->raiz == NULL)
        return;
    pilha *p;
    iniciar_pilha(&p);
    empurrar_pilha(p, t->raiz);
    while (p->tamanho > 0)
    {
        arvore_no *no = puxar_pilha(p);
        printf("%d\n", no->dado);
        if (no->direita != NULL)
            empurrar_pilha(p, no->direita);
        if (no->esquerda != NULL)
            empurrar_pilha(p, no->esquerda);
    }
}

void busca_Pre_Ordem(arvore_no *raiz)
{
    if (raiz != NULL)
    {
        process(raiz);
        busca_Pre_Ordem(raiz->esquerda);
        busca_Pre_Ordem(raiz->direita);
    }
}

void busca_Em_Ordem(arvore_no *raiz)
{
    if (raiz != NULL)
    {
        busca_Em_Ordem(raiz->esquerda);
        process(raiz);
        busca_Em_Ordem(raiz->direita);
    }
}

void busca_Pos_Ordem(arvore_no *raiz)
{
    if (raiz != NULL)
    {
        busca_Pos_Ordem(raiz->esquerda);
        busca_Pos_Ordem(raiz->direita);
        process(raiz);
    }
}