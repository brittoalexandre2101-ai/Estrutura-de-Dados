#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    size_t frente, traz, tamanho, capacidade;
    int *fila;
} fila;

void iniciar(fila **f)
{
    (*f) = malloc(sizeof(fila));
    (*f)->frente = (*f)->traz = (*f)->tamanho = 0;
    (*f)->capacidade = 1000000;
    (*f)->fila = malloc(sizeof(int) * 1000000);
}

void empurrarFila(fila *f, int dado)
{
    if (f->tamanho == f->capacidade)
        return;
    f->fila[f->traz] = dado;
    f->traz++;
    if (f->traz == f->capacidade)
        f->traz = 0;
    f->tamanho++;
}

int puxarFila(fila *f)
{
    int aux = f->fila[f->frente];
    f->frente++;
    f->tamanho--;
    if (f->frente == f->capacidade)
        f->frente = 0;
    return aux;
}

int main()
{
    int n;
    scanf("%d", &n);
    int esquerda[n + 1];
    int direita[n + 1];
    for (int i = 0; i < n; i++)
    {
        int b, e, d;
        scanf("%d %d %d", &b, &e, &d);
        esquerda[b] = e;
        direita[b] = d;
    }

    fila *f;
    iniciar(&f);
    empurrarFila(f, 1);

    int familia[n + 1];
    int djerry[n + 1];
    int v = 0;

    while (f->tamanho > 0)
    {
        int tamanho_nivel = f->tamanho;
        int no;
        for (int i = 0; i < tamanho_nivel; i++)
        {
            no = puxarFila(f);
            if (esquerda[no] != 0)
                empurrarFila(f, esquerda[no]);
            if (direita[no] != 0)
                empurrarFila(f, direita[no]);
            if (i == 0)
            {
                familia[v] = no;
            }
            if (i == tamanho_nivel - 1)
            {
                djerry[v] = no;
            }
        }
        v++;
    }

    printf("%d\n", v);
    for (int i = 0; i < v; i++)
        printf("%d ", familia[i]);
    printf("\n");
    for (int i = 0; i < v; i++)
        printf("%d ", djerry[i]);
    printf("\n");
    return 0;
}