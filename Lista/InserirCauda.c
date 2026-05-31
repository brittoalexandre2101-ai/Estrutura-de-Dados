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

struct list_node_t *createnode(int data)
{
    struct list_node_t *newnode = (list_node_t *)malloc(sizeof(list_node_t));

    if (newnode == NULL)
    {
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void list_append(list_t *l, int data)
{
    struct list_node_t *newnode = createnode(data);

    if (l->size == 0)
    {
        l->head = newnode;
        l->tail = newnode;
    }
    else
    {
        l->tail->next = newnode;
        l->tail = newnode;
    }

    l->size++;
}