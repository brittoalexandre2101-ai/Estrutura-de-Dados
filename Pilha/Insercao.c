#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
    int *stack;
    size_t capacity;
    size_t size;
} stack_t;

void stack_push(stack_t *s, int data)
{
    if (s->size == s->capacity)
    {
        if (s->capacity == 0)
        {
            s->capacity = 1;
        }
        s->capacity *= 2;

        int *temp = realloc(s->stack, sizeof(int) * s->capacity);
        if (temp == NULL)
            exit(1);
        s->stack = temp;
    }
    s->stack[s->size] = data;
    s->size++;
}