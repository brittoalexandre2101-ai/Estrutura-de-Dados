#include <stdio.h>
#include <stdlib.h>
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

int aux(tree_node_t *no, int lado)
{
    if (no == NULL)
        return 1;
    if (no->left == NULL && no->right == NULL)
        return 1;
    if (no->left != NULL && no->right != NULL)
        return 0;
    if (no->left != NULL && no->right == NULL)
    {
        if (lado != -1 && lado != 1)
        {
            return 0;
        }
        return aux(no->left, 0);
    }
    if (no->right != NULL && no->left == NULL)
    {
        if (lado != -1 && lado != 0)
        {
            return 0;
        }
        return aux(no->right, 1);
    }
}

bool is_zigzag(tree_t *t)
{
    return aux(t->root, -1);
}