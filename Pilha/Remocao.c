#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
    int *stack;
    size_t capacity;
    size_t size;
} stack_t;

void stack_pop(stack_t *s)
{
    if (s->size == 0)
        return;
    if (s->size == s->capacity / 4 && s->capacity > 4)
    {
        s->capacity /= 2;
        int *temp = realloc(s->stack, sizeof(int) * s->capacity);
        if (temp != NULL)
            s->stack = temp;
    }
    s->size--;
}