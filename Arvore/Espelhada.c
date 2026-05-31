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
    return aux(a->left, b->right) && aux(a->right, b->left);
}

bool is_mirrored(tree_t *t)
{
    if (t->root == NULL)
        return 1;
    return aux(t->root->left, t->root->right);
}