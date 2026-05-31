#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef struct fila
{
    no *frente; // de onde sai
    no *tras;   // de onde entra
    int tamanho;
} Fila;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    fila->tamanho = 0;

    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        no *novo = (no *)malloc(sizeof(no));
        scanf("%d", &novo->valor);
        novo->proximo = NULL;

        if (fila->frente == NULL)
        {
            fila->frente = novo;
            fila->tras = novo;
        }
        else
        {
            fila->tras->proximo = novo;
            fila->tras = novo;
        }

        soma += novo->valor;
        fila->tamanho++;

        if (fila->tamanho > k)
        {
            no *remover = fila->frente;
            soma -= remover->valor;
            fila->frente = remover->proximo;
            free(remover);
            fila->tamanho--;
        }

        float media = ((float)soma / fila->tamanho);
        printf("%.4f\n", media);
    }

    return 0;
}
