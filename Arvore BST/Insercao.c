#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node_t
{
    int data;
    struct bst_node_t *left;
    struct bst_node_t *right;
} bst_node_t;

typedef struct bst_t
{
    bst_node_t *root;
    size_t size;
} bst_t;

bst_node_t *no(int data)
{
    bst_node_t *aux = malloc(sizeof(bst_node_t));
    aux->left = NULL;
    aux->right = NULL;
    aux->data = data;
    return aux;
}

bst_node_t *insercao(bst_node_t *x, int data)
{
    if (x == NULL)
        return no(data);
    if (data < x->data)
        x->left = insercao(x->left, data);
    else
        x->right = insercao(x->right, data);
    return x;
}

void bst_insert(bst_t *t, int data)
{
    t->root = insercao(t->root, data);
    t->size++;
}