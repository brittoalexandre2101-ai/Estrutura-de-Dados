#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char nome[31];
    struct No *proximo;
} no;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    no *cabeca = NULL, *cauda = NULL;
    for (int i = 0; i < n; i++)
    {
        no *novono = (no *)malloc(sizeof(no));
        scanf("%s", novono->nome);
        novono->proximo = NULL;
        if (cabeca == NULL)
            cabeca = novono;
        else
            cauda->proximo = novono;
        cauda = novono;
    }
    cauda->proximo = cabeca;
    no *atual = cabeca, *anterior = cauda;
    while (atual != atual->proximo)
    {
        for (int i = 0; i < x - 1; i++)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = atual->proximo;
        no *aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    printf("%s\n", atual->nome);
    return 0;
}