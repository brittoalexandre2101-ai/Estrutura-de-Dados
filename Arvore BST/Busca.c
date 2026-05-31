#include <stdio.h>
#include <stdbool.h>
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

int aux(bst_node_t *x, int data)
{
    if (x == NULL)
        return false;
    if (data == x->data)
        return true;
    if (data < x->data)
        return aux(x->left, data);
    return aux(x->right, data);
}

bool bst_find(bst_t *t, int data)
{
    return aux(t->root, data);
}