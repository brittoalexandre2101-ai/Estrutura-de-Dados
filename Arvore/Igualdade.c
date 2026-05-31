#include <stdio.h>
#include <stdbool.h>

typedef struct tree_node_t
{
    int data;
    struct tree_node_t *left;
    struct tree_node_t *right;
} tree_node_t;

typedef struct tree_t
{
    tree_node_t *root;
} tree_t;

int aux(tree_node_t *a, tree_node_t *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    if (a->data != b->data)
        return 0;
    else
        return aux(a->left, b->left) && aux(a->right, b->right);
}

bool is_equal(tree_t *t1, tree_t *t2)
{
    return aux(t1->root, t2->root);
}