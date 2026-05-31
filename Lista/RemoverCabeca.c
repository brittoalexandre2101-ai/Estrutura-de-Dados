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

void list_remove_head(list_t *l)
{
    if (l == NULL)
        return;

    list_node_t *aux = l->head;
    l->head = l->head->next;
    if (l->head == NULL)
        l->tail = NULL;
    l->size--;
    free(aux);
    return;
}