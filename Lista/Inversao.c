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

void list_reverse(list_t *l)
{

    list_node_t *prev = NULL;
    list_node_t *current = l->head;
    list_node_t *next = NULL;

    l->tail = l->head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l->head = prev;
}