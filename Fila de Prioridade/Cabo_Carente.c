#include <stdio.h>
#include <stdlib.h>

void siftdown(int *v, int i, int tam)
{
    int menor = i;
    while (1)
    {
        int esq = i * 2 + 1;
        int dir = i * 2 + 2;
        if (esq < tam && v[esq] < v[menor])
            menor = esq;
        if (dir < tam && v[dir] < v[menor])
            menor = dir;
        if (i == menor)
            break;
        int troca = v[i];
        v[i] = v[menor];
        v[menor] = troca;
        i = menor;
    }
}

void siftup(int *v, int i)
{
    while (i > 0)
    {
        int pai = (i - 1) / 2;
        if (v[i] < v[pai])
        {
            int troca = v[i];
            v[i] = v[pai];
            v[pai] = troca;
            i = pai;
        }
        else
            break;
    }
}

void inserir(int *v, int *tam, int valor)
{
    v[*tam] = valor;
    siftup(v, *tam);
    (*tam)++;
}

int remover(int *v, int *tam)
{
    int topo = v[0];
    v[0] = v[*tam - 1];
    (*tam)--;
    siftdown(v, 0, *tam);
    return topo;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *heap = malloc(n * sizeof(int));
    int tam = 0;

    for (int i = 0; i < n; i++)
    {
        int c;
        scanf("%d", &c);
        inserir(heap, &tam, c);
    }

    long long custo = 0;
    while (tam > 1)
    {
        int a = remover(heap, &tam);
        int b = remover(heap, &tam);
        int novo = a + b;
        custo += b; // custo é o maior dos dois, b é sempre >= a pois min-heap
        inserir(heap, &tam, novo);
    }

    printf("%lld\n", custo);

    free(heap);
    return 0;
}