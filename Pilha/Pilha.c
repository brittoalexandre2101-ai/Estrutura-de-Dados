#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
    A pilha é um TAD no qual os elementos são mantidos em uma ordem especifíca.
    Esta ordem é a LIFO(Last-in First-Out)
    Que signigica, que o último a entrar é o primeiro a sair, igual a uma pilha de pratos.
*/

typedef struct Pilha
{
    int *pilha;
    size_t capacidade;
    size_t tamanho;
} Pilha;

// Último a entrar
void empurra_pilha(Pilha *s, int valor)
{
    if (s->tamanho == s->capacidade)
    {
        if (s->capacidade == 0)
        {
            s->capacidade = 1;
        }
        s->capacidade *= 2;
        // s->pilha = realloc(s->pilha, sizeof(int) * s->capacidade);
        int *temp = realloc(s->pilha, sizeof(int) * s->capacidade);
        if (temp == NULL)
        {
            exit(1);
        }
        s->pilha = temp;
    }
    s->pilha[s->tamanho] = valor;
    s->tamanho++;
}
// Primeiro a sair

void puxar_pilha(Pilha *s)
{
    if (s->tamanho == 0)
        return;
    if (s->tamanho == s->capacidade / 4 && s->capacidade > 4)
    {
        s->capacidade /= 2;
        s->pilha = realloc(s->pilha, sizeof(int) * s->capacidade);
    }
    int *temp = realloc(s->pilha, sizeof(int) * s->capacidade);
    if (temp != NULL)
        s->pilha = temp;
    s->tamanho--;
}