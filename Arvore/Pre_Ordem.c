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

void aux(tree_node_t *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%d\n", no->data);
    aux(no->left);
    aux(no->right);
}
void dfs_pre(tree_t *t)
{
    aux(t->root);
}