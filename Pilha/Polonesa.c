#include <stdio.h>
#include <stdlib.h>
#define max 100005

char pilha[max];
int topo = -1;

void empilha(char c)
{
    pilha[++topo] = c;
}

char desempilha()
{
    return pilha[topo--];
}

char peek()
{
    return pilha[topo];
}

int vazia()
{
    return topo == -1;
}

int precedencia(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    char op[max];
    fgets(op, max, stdin);

    int primeiro = 1;

    for (int i = 0; op[i] != '\0'; i++)
    {
        char c = op[i];
        if (isspace(c))
            continue;
        else if (isdigit(c))
        {
            if (!primeiro)
                printf(" ");
            primeiro = 0;
            while (isdigit(op[i]))
            {
                printf("%c", op[i]);
                i++;
            }
            i--;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!vazia() && precedencia(peek()) >= precedencia(c))
            {
                if (!primeiro)
                    printf(" ");
                primeiro = 0;
                printf("%c", desempilha());
            }
            empilha(c);
        }
        else if (c == '(')
        {
            empilha(c);
        }
        else if (c == ')')
        {
            while (peek() != '(')
            {
                if (!primeiro)
                    printf(" ");
                primeiro = 0;
                printf("%c", desempilha());
            }
            desempilha();
        }
    }
    while (!vazia())
    {
        if (!primeiro)
            printf(" ");
        printf("%c", desempilha());
    }
    printf("\n");
    return 0;
}