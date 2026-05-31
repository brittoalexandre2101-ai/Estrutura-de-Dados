#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_raiz
{
    int dado;
    struct no_raiz *esq;
    struct no_raiz *dir;
} no_raiz;

typedef struct raiz
{
    no_raiz *raiz;
} raiz;

typedef struct fila
{
    size_t frente;
    size_t traz;
    size_t tamanho;
    size_t capacidade;
    no_raiz **fila;
} fila;

void iniciar(fila **f)
{
    (*f) = malloc(sizeof(fila));
    (*f)->frente = 0;
    (*f)->traz = 0;
    (*f)->tamanho = 0;
    (*f)->capacidade = 1000000;
    (*f)->fila = malloc(sizeof(no_raiz *) * 1000000);
}

void empurrarFila(fila *f, no_raiz *dado)
{
    if (f->tamanho == f->capacidade)
        return;
    f->fila[f->traz] = dado;
    f->traz++;
    if (f->traz == f->capacidade)
        f->traz = 0;
    f->tamanho++;
}

no_raiz *puxarFila(fila *f)
{
    no_raiz *aux = f->fila[f->frente];
    f->frente++;
    f->tamanho--;
    if (f->frente == f->capacidade)
        f->frente = 0;
    return aux;
}

void em_largura(no_raiz *raiz)
{
    if (raiz == NULL)
        return;
    fila *f;
    iniciar(&f);
    empurrarFila(f, raiz);
    int primeiro = 1;
    while (f->tamanho > 0)
    {
        no_raiz *no = puxarFila(f);
        if (!primeiro)
            printf(" ");
        printf("%d", no->dado);
        primeiro = 0;
        if (no->esq != NULL)
            empurrarFila(f, no->esq);
        if (no->dir != NULL)
            empurrarFila(f, no->dir);
    }
    printf("\n");
}

no_raiz *construir(char *str, int *pos, int *val, int *v)
{
    if (str[*pos] == '.')
    {
        (*pos)++;
        return NULL;
    }
    (*pos)++;
    no_raiz *no = malloc(sizeof(no_raiz));
    no->dado = val[(*v)++];
    no->esq = construir(str, pos, val, v);
    no->dir = construir(str, pos, val, v);
    (*pos)++;
    return no;
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[300001];
    scanf("%s", str);
    int val[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    int pos = 0, v = 0;
    no_raiz *arvore = construir(str, &pos, val, &v);
    em_largura(arvore);
    return 0;
}