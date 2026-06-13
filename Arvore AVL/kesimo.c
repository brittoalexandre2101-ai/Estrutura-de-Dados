#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Avl_No
{
    int dado;
    size_t altura;
    // size_t tamanho;
    struct Avl_No *esquerda;
    struct Avl_No *direita;
} Avl_No;

typedef struct ArvoreAVL
{
    struct Avl_No *raiz;
    size_t tamanho;
} ArvoreAVL;

Avl_No *inserir_ajuda(Avl_No *v, int dado);
Avl_No *remover_ajuda(Avl_No *v, int dado);
static Avl_No *encontrar_direita(Avl_No *v);

void Avl_Inicializacao(ArvoreAVL **t)
{
    (*t) = malloc(sizeof(ArvoreAVL));
    (*t)->raiz = NULL;
    (*t)->tamanho = 0;
}

Avl_No *novo_no(int dado)
{
    Avl_No *novo_no = malloc(sizeof(Avl_No));
    novo_no->altura = 1;
    // novo_no->tamanho = 1;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    novo_no->dado = dado;
    return novo_no;
}

// Deletar um nó
void deletar_no(Avl_No *t)
{
    free(t);
}

// Retornar a altura da árvore com raiz em V
size_t altura_arvore(Avl_No *v)
{
    if (v == NULL)
        return 0;
    return v->altura;
}

// Calcular a altura de uma árvore com raiz em v a partir dos seus filhos
size_t calcular_altura(Avl_No *v)
{
    size_t altura_esquerda, altura_direita;
    if (v == NULL)
        return 0;
    altura_esquerda = altura_arvore(v->esquerda);
    altura_direita = altura_arvore(v->direita);
    if (altura_esquerda > altura_direita)
    {
        return altura_esquerda + 1;
    }
    else
        return altura_direita + 1;
}
/*
size_t calcular_tamanho(Avl_No *v)
{
    size_t esq = (v->esquerda != NULL) ? v->esquerda->tamanho : 0;
    size_t dir = (v->direita != NULL) ? v->direita->tamanho : 0;
    return 1 + esq + dir;
}
*/
// Fator de equilibrio da árvore
int equilibrio(Avl_No *v)
{
    if (v == NULL)
        return 0;
    return ((int)altura_arvore(v->esquerda) - altura_arvore(v->direita));
}

// Realiza a rotação para esquerda da arvore com raiz em x, e devolve a nova raiz
static Avl_No *rotacao_esquerda(Avl_No *x)
{
    Avl_No *y = x->direita;
    x->direita = y->esquerda;
    y->esquerda = x;
    x->altura = calcular_altura(x);
    // x->tamanho = calcular_tamanho(x);
    y->altura = calcular_altura(y);
    // x->tamanho = calcular_tamanho(y);
    return y;
}

// Realiza a rotação para direita da arvore com raiz em y, e devolve a nova raiz
static Avl_No *rotacao_direita(Avl_No *y)
{
    Avl_No *x = y->esquerda;
    y->esquerda = x->direita;
    x->direita = y;
    y->altura = calcular_altura(y);
    // x->tamanho = calcular_tamanho(y);
    x->altura = calcular_altura(x);
    // x->tamanho = calcular_tamanho(x);
    return x;
}

// Balancear uma árvore com raiz em v
static Avl_No *balanco(Avl_No *v)
{
    int balanco = equilibrio(v);
    if (balanco > 1 && equilibrio(v->esquerda) >= 0)
        v = rotacao_direita(v);
    else if (balanco < -1 && equilibrio(v->direita) <= 0)
        v = rotacao_esquerda(v);
    else if (balanco > 1 && equilibrio(v->esquerda) < 0)
    {
        v->esquerda = rotacao_esquerda(v->esquerda);
        v = rotacao_direita(v);
    }
    else if (balanco < -1 && equilibrio(v->direita) > 0)
    {
        v->direita = rotacao_direita(v->direita);
        v = rotacao_esquerda(v);
    }
    return v;
}

void inserir(ArvoreAVL *t, int dado)
{
    t->raiz = inserir_ajuda(t->raiz, dado);
    t->tamanho++;
}

Avl_No *inserir_ajuda(Avl_No *v, int dado)
{
    if (v == NULL)
    {
        v = novo_no(dado);
        v->altura = calcular_altura(v);
        return v;
    }
    assert(v->dado != dado);
    if (dado < v->dado)
    {
        v->esquerda = inserir_ajuda(v->esquerda, dado);
    }
    else
    {
        v->direita = inserir_ajuda(v->direita, dado);
    }
    v->altura = calcular_altura(v);
    // v->tamanho = calcular_tamanho(v);
    v = balanco(v);
    return v;
}

void remover(ArvoreAVL *t, int dado)
{
    t->raiz = remover_ajuda(t->raiz, dado);
    t->tamanho--;
}

Avl_No *remover_ajuda(Avl_No *v, int dado)
{
    assert(v != NULL);
    if (dado < v->dado)
        v->esquerda = remover_ajuda(v->esquerda, dado);
    else if (dado > v->dado)
        v->direita = remover_ajuda(v->direita, dado);
    else
    { // Remoção do nó
        if (v->esquerda == NULL)
        {
            Avl_No *aux = v->direita;
            deletar_no(v);
            return aux;
        }
        else if (v->direita == NULL)
        {
            Avl_No *aux = v->esquerda;
            deletar_no(v);
            return aux;
        }
        else
        {
            Avl_No *anterior = encontrar_direita(v->esquerda);
            int aux = v->dado;
            v->dado = anterior->dado;
            anterior->dado = aux;
            v->esquerda = remover_ajuda(v->esquerda, anterior->dado);
        }
    }
    if (v != NULL)
    {
        v->altura = calcular_altura(v);
        // v->tamanho = calcular_tamanho(v);
        v = balanco(v);
    }
    return v;
}

static Avl_No *encontrar_direita(Avl_No *v)
{
    if (v == NULL || v->direita == NULL)
        return v;
    else
        return encontrar_direita(v->direita);
}

int k_esimo(Avl_No *no, int *k)
{
    if (no == NULL)
        return -1;
    int achou;
    achou = k_esimo(no->esquerda, k);
    if (achou != -1)
        return achou;
    (*k)--;
    if (*k == 0)
        return no->dado;
    achou = k_esimo(no->direita, k);
    if (achou != -1)
        return achou;

    /*while (no != NULL)
    {
        int tamanho_esq;
        if (no->esquerda != NULL)
            tamanho_esq = (int)no->esquerda->tamanho;
        else
            tamanho_esq = 0;
        if (k <= tamanho_esq)
            no = no->esquerda;
        else if (k == tamanho_esq + 1)
            return no->dado;
        else
        {
            k = k - tamanho_esq - 1;
            no = no->direita;
        }
    }
    return -1;*/
}

int main()
{
    int q;
    scanf("%d", &q);

    ArvoreAVL *t;
    Avl_Inicializacao(&t);

    for (int i = 0; i < q; i++)
    {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1)
            inserir(t, x);
        else if (op == 2)
            remover(t, x);
        else
            printf("%d\n", k_esimo(t->raiz, &x));
    }
    return 0;
}