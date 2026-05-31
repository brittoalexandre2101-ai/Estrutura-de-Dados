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

int aux(tree_node_t *no)
{
    if (no == NULL)
        return 1;
    if (no->left == NULL && no->right == NULL)
        return 1;
    if (no->left != NULL && no->right == NULL || no->left == NULL && no->right != NULL)
        return 0;
    if (no->left != NULL && no->right != NULL)
        return aux(no->left) && aux(no->right);
}
bool is_full(tree_t *t)
{
    return aux(t->root);
}