#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct tree_node_t
{
    int data;
    struct tree_node_t *left;
    struct tree_node_t *right;
} tree_node_t;

typedef struct tree_t
{
    tree_node_t *root;
    size_t size;
} tree_t;

int aux(tree_node_t *no, int min, int max)
{
    if (no == NULL)
        return 1;
    if (no->data <= min || no->data >= max)
        return 0;
    return aux(no->left, min, no->data) && aux(no->right, no->data, max);
}

bool is_bst(tree_t *t)
{
    return aux(t->root, INT_MIN, INT_MAX);
}