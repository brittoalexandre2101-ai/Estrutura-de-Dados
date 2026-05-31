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

typedef struct fila
{
    size_t frente, traz, tamanho, capacidade;
    tree_node_t **fila;
} fila;

void iniciar(fila **f)
{
    (*f) = malloc(sizeof(fila));
    (*f)->frente = (*f)->traz = (*f)->tamanho = 0;
    (*f)->capacidade = 1000000;
    (*f)->fila = malloc(sizeof(tree_node_t *) * 1000000);
}

void empurrarFila(fila *f, tree_node_t *dado)
{
    if (f->tamanho == f->capacidade)
        return;
    f->fila[f->traz] = dado;
    f->traz++;
    if (f->traz == f->capacidade)
        f->traz = 0;
    f->tamanho++;
}

tree_node_t *puxarFila(fila *f)
{
    tree_node_t *aux = f->fila[f->frente];
    f->frente++;
    f->tamanho--;
    if (f->frente == f->capacidade)
        f->frente = 0;
    return aux;
}

void bfs(tree_t *t)
{
    if (t->root == NULL)
        return;
    fila *f;
    iniciar(&f);
    empurrarFila(f, t->root);
    while (f->tamanho > 0)
    {
        tree_node_t *no = puxarFila(f);
        printf("%d\n", no->data);
        if (no->left != NULL)
            empurrarFila(f, no->left);
        if (no->right != NULL)
            empurrarFila(f, no->right);
    }
}
