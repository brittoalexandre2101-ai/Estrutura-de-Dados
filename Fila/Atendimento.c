#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int tempo;
    int cor; // agora cor é um inteiro (0 = verde, 1 = laranja)
    struct No *prox;
    int ayla; // flag para identificar se é o processo Ayla
} no;

typedef struct Fila
{
    no *frente;
    no *traz;
    int tamanho;
} Fila;

Fila *iniciar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->frente = NULL;
    f->traz = NULL;
    f->tamanho = 0;
    return f;
}

void inserir_na_fila(Fila *f, no *novo)
{
    novo->prox = NULL;
    if (f->frente == NULL)
    {
        f->frente = novo;
        f->traz = novo;
        f->tamanho++;
        return;
    }

    if (novo->tempo < f->frente->tempo)
    {
        novo->prox = f->frente;
        f->frente = novo;
        f->tamanho++;
        return;
    }

    no *atual = f->frente;
    while (atual->prox != NULL && atual->prox->tempo <= novo->tempo)
        atual = atual->prox;
    novo->prox = atual->prox;
    atual->prox = novo;
    if (novo->prox == NULL)
        f->traz = novo;
    f->tamanho++;
}

no *remover_fila(Fila *f)
{
    no *remover = NULL;
    if (f->frente)
    {
        remover = f->frente;
        f->frente = remover->prox;
        if (f->frente == NULL)
            f->traz = NULL;
        f->tamanho--;
    }
    return remover;
}

int main()
{
    int n;
    scanf("%d", &n);
    Fila *verde = iniciar_fila();
    Fila *laranja = iniciar_fila();

    for (int i = 0; i < n; i++)
    {
        no *averno = malloc(sizeof(no));
        scanf("%d %d", &averno->cor, &averno->tempo);
        averno->ayla = 0; // não é Ayla
        if (averno->cor == 0)
            inserir_na_fila(verde, averno);
        else
            inserir_na_fila(laranja, averno);
    }

    no *Ayla = malloc(sizeof(no));
    scanf("%d %d", &Ayla->cor, &Ayla->tempo);
    Ayla->ayla = 1; // marcar como Ayla

    if (Ayla->cor == 0)
        inserir_na_fila(verde, Ayla);
    else
        inserir_na_fila(laranja, Ayla);

    no *atual = NULL;
    int tempo = 0, tempo_atual = 0;

    while (tempo < 100 && (verde->frente != NULL || laranja->frente != NULL))
    {
        if (verde->frente != NULL && (laranja->frente == NULL || verde->frente->tempo < laranja->frente->tempo))
        {
            tempo_atual = verde->frente->tempo;
            atual = remover_fila(verde);
        }
        else
        {
            tempo_atual = laranja->frente->tempo;
            atual = remover_fila(laranja);
        }
        tempo += tempo_atual;
    }

    while (atual != NULL && (verde->frente != NULL || laranja->frente != NULL))
    {
        if (verde->frente != NULL && (laranja->frente == NULL || verde->frente->tempo < laranja->frente->tempo))
        {
            tempo_atual = verde->frente->tempo;
            atual = remover_fila(verde);
        }
        else
        {
            tempo_atual = laranja->frente->tempo;
            atual = remover_fila(laranja);
        }
        tempo += tempo_atual;
    }

    if (atual != NULL && atual->ayla == 1)
    {
        printf("Ayla: %d\n", tempo_atual - Ayla->tempo);
    }

    free(Ayla);
    return 0;
}
