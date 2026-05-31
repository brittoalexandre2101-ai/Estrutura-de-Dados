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
    list_node_t *newnode = (list_node_t *)malloc(sizeof(list_node_t));

    if (newnode == NULL)
    {
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void list_insert(list_t *l, int data, size_t i)
{
    if (i == 0)
    {
        list_node_t *newnode = createnode(data);

        newnode->next = l->head;
        l->head = newnode;

        if (l->size == 0)
        {
            l->tail = newnode;
        }

        l->size++;
        return;
    }
    else if (i == l->size)
    {
        list_node_t *newnode = createnode(data);

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
        return;
    }

    list_node_t *newnode = createnode(data);
    list_node_t *current = l->head;

    for (size_t j = 0; j < i - 1; j++)
    {
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;

    l->size++;
}