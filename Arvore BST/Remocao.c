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

bst_node_t *antecessor(bst_node_t *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

bst_node_t *remocao(bst_node_t *x, int data)
{
    if (data < x->data)
    {
        x->left = remocao(x->left, data);
    }
    else if (data > x->data)
    {
        x->right = remocao(x->right, data);
    }
    else
    {
        if (x->left == NULL && x->right == NULL)
            return NULL;
        if (x->left == NULL && x->right != NULL)
            return x->right;
        if (x->left != NULL && x->right == NULL)
            return x->left;
        if (x->left != NULL && x->right != NULL)
        {
            bst_node_t *anterior = antecessor(x->left);
            int aux = x->data;
            x->data = anterior->data;
            anterior->data = aux;
            x->left = remocao(x->left, anterior->data);
        }
    }

    return x;
}

void bst_remove(bst_t *t, int data)
{
    t->root = remocao(t->root, data);
    t->size--;
}