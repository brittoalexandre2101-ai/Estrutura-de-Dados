#include <stdio.h>
#include <stdlib.h>

// Max-heap (metade menor)
void siftdown_max(int *v, int i, int tam)
{
    int maior = i;
    while (1)
    {
        int esq = i * 2 + 1;
        int dir = i * 2 + 2;
        if (esq < tam && v[esq] > v[maior])
            maior = esq;
        if (dir < tam && v[dir] > v[maior])
            maior = dir;
        if (i == maior)
            break;
        int troca = v[i];
        v[i] = v[maior];
        v[maior] = troca;
        i = maior;
    }
}

void siftup_max(int *v, int i)
{
    while (i > 0)
    {
        int pai = (i - 1) / 2;
        if (v[i] > v[pai])
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

// Min-heap (metade maior)
void siftdown_min(int *v, int i, int tam)
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

void siftup_min(int *v, int i)
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

void inserir_max(int *v, int *tam, int valor)
{
    v[*tam] = valor;
    siftup_max(v, *tam);
    (*tam)++;
}

void inserir_min(int *v, int *tam, int valor)
{
    v[*tam] = valor;
    siftup_min(v, *tam);
    (*tam)++;
}

int remover_max(int *v, int *tam)
{
    int topo = v[0];
    v[0] = v[*tam - 1];
    (*tam)--;
    siftdown_max(v, 0, *tam);
    return topo;
}

int remover_min(int *v, int *tam)
{
    int topo = v[0];
    v[0] = v[*tam - 1];
    (*tam)--;
    siftdown_min(v, 0, *tam);
    return topo;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *max_heap = malloc(sizeof(int) * n);
    int *min_heap = malloc(sizeof(int) * n);
    int tam_max = 0, tam_min = 0;

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);

        if (tam_max == 0 || val <= max_heap[0])
            inserir_max(max_heap, &tam_max, val);
        else
            inserir_min(min_heap, &tam_min, val);

        if (tam_max > tam_min + 1)
        {
            int topo = remover_max(max_heap, &tam_max);
            inserir_min(min_heap, &tam_min, topo);
        }
        if (tam_min > tam_max)
        {
            int topo = remover_min(min_heap, &tam_min);
            inserir_max(max_heap, &tam_max, topo);
        }

        printf("%d\n", max_heap[0]);
    }

    free(max_heap);
    free(min_heap);
    return 0;
}