#include <stdio.h>
#include <stdlib.h>

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

void help(tree_node_t *no)
{
    if (no == NULL)
    {
        return;
    }
    help(no->left);
    help(no->right);
    printf("%d\n", no->data);
}
void dfs_in(tree_t *t)
{
    help(t->root);
}