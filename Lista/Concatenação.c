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

void list_concat(list_t *l1, list_t *l2)
{
    if (list_empty(l2))
        return;
    if (list_empty(l1))
    {
        l1->head = l2->head;
        l1->tail = l2->tail;
        l1->size = l2->size;
    }
    else
    {
        l1->tail->next = l2->head;
        l1->tail = l2->tail;
        l1->size += l2->size;
    }
}