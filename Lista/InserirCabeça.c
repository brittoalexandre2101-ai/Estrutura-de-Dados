#include <stdio.h>
#include <stdlib.h>
// #include "grader.h"

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
    list_node_t *newnode = (list_node_t *)malloc(sizeof(list_node_t));

    if (newnode == NULL)
    {
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void list_prepend(list_t *l, int data)
{
    list_node_t *newnode = createnode(data);

    newnode->next = l->head;
    l->head = newnode;
    l->size++;
}