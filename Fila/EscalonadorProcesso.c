#include <stdio.h>
#include <stdlib.h>
#define max 100000

typedef struct
{
    char nome[3];
    int pid;
    int time;
} Processo;

typedef struct
{
    Processo data[max];
    int frente;
    int traz;
    int tamanho;
} fila;

void inicio_fila(fila *q)
{
    q->frente = 0;
    q->traz = 0;
    q->tamanho = 0;
}

int vazia(fila *q) { return q->tamanho == 0; }
int cheia(fila *q) { return q->tamanho == max; }

void enfileirar(fila *q, Processo p)
{
    if (cheia(q))
        return;
    q->traz = (q->traz + 1) % max;
    q->data[q->traz] = p;
    q->tamanho++;
}

Processo desenfileirar(fila *q)
{
    Processo p = q->data[q->frente];
    q->frente = (q->frente + 1) % max;
    q->tamanho--;
    return p;
}

int main()
{
    int n, quantum;
    scanf("%d %d", &n, &quantum);

    fila q;
    inicio_fila(&q);

    for (int i = 0; i < n; i++)
    {
        Processo p;
        scanf("%s %d %d", p.nome, &p.pid, &p.time);
        enfileirar(&q, p);
    }

    int atual = 0;
    while (!vazia(&q))
    {
        Processo p = desenfileirar(&q);

        int tempo;
        if (p.time < quantum)
            tempo = p.time;
        else
            tempo = quantum;

        atual += tempo;
        p.time -= tempo;

        if (p.time > 0)
        {
            enfileirar(&q, p);
        }
        else
        {
            printf("%s %d %d ms\n", p.nome, p.pid, atual);
        }
    }

    return 0;
}