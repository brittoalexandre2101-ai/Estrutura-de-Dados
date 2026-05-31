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

void list_remove_tail(list_t *l)
{
    if (l == NULL || l->size == 0)
    {
        return;
    }
    if (l->size == 1)
    {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
        return;
    }
    list_node_t *current = l->head;
    while (current->next != l->tail)
    {
        current = current->next;
    }
    free(l->tail);
    l->tail = current;
    l->tail->next = NULL;

    l->size--;
}