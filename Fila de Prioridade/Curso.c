#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int g;
    int v;
} Curso;

void siftdown(Curso *v, int i, int tam)
{
    int maior = i;
    while (1)
    {
        int esq = i * 2 + 1;
        int dir = i * 2 + 2;
        if (esq < tam && v[esq].v > v[maior].v)
            maior = esq;
        if (dir < tam && v[dir].v > v[maior].v)
            maior = dir;
        if (i == maior)
            break;
        Curso troca = v[i];
        v[i] = v[maior];
        v[maior] = troca;
        i = maior;
    }
}

void siftup(Curso *v, int i)
{
    while (i > 0)
    {
        int pai = (i - 1) / 2;
        if (v[i].v > v[pai].v)
        {
            Curso troca = v[i];
            v[i] = v[pai];
            v[pai] = troca;
            i = pai;
        }
        else
            break;
    }
}

void inserir(Curso *v, int *tam, Curso curso)
{
    v[*tam] = curso;
    siftup(v, *tam);
    (*tam)++;
}

Curso extrair(Curso *v, int *tam)
{
    Curso topo = v[0];
    v[0] = v[*tam - 1];
    (*tam)--;
    siftdown(v, 0, *tam);
    return topo;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Curso *heap = malloc(sizeof(Curso) * n);
    int tam = 0;

    for (int i = 0; i < n; i++)
    {
        Curso c;
        scanf("%d %d", &c.g, &c.v);
        inserir(heap, &tam, c);
    }

    int *ocupado = calloc(m + 1, sizeof(int));
    int soma = 0;

    while (tam > 0)
    {
        Curso c = extrair(heap, &tam);
        int semana = c.g > m ? m : c.g;
        while (semana > 0 && ocupado[semana])
            semana--;
        if (semana > 0)
        {
            ocupado[semana] = 1;
            soma += c.v;
        }
    }

    printf("%d\n", soma);

    free(heap);
    free(ocupado);
    return 0;
}