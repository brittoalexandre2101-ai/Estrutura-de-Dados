#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t
{
    int data;                 /*Dado da lista*/
    struct list_node_t *next; /*ponteiro para o próximo elemento*/
} list_node_t;

typedef struct list_t
{
    list_node_t *head; /*Cabeça da Lista*/
    list_node_t *tail; /*Cauda da Lista*/
    size_t size;       /*tamanho da lista*/
} list_t;

void list_remove(list_t *l, size_t i)
{
    if (l == NULL)
    {
        return;
    }

    // REMOVER CABEÇA
    if (i == 0)
    {
        list_node_t *aux = l->head;
        l->head = l->head->next;

        if (l->head == NULL)
        {
            l->tail = NULL;
        }

        l->size--;
        free(aux);
        return;
    }

    // REMOÇÃO CAUDA
    if (i == l->size - 1)
    {
        list_node_t *old_tail = l->tail; // Guarda para liberar depois

        if (l->size == 1)
        {
            l->head = NULL;
            l->tail = NULL;
        }
        else
        {
            list_node_t *current = l->head;

            while (current->next != l->tail)
            {
                current = current->next;
            }

            l->tail = current;
            l->tail->next = NULL;
        }

        free(old_tail); // Importante!
        l->size--;
        return;
    }

    // REMOÇÃO POSIÇÃO ARBITRÁRIA
    list_node_t *aux = l->head;

    for (size_t j = 0; j < i - 1; j++)
    {
        aux = aux->next;
    }

    list_node_t *remove = aux->next;
    aux->next = remove->next;

    free(remove);
    l->size--;
}