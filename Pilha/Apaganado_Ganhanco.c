#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100005

int main()
{
    int n, d;
    char numero[max];
    char resultado[max];
    int topo;

    while (scanf("%d %d", &n, &d) == 2 && (n != 0 || d != 0))
    {
        scanf("%s", numero);
        topo = -1;
        for (int i = 0; i < n; i++)
        {
            char atual = numero[i];
            while (topo != -1 && atual > resultado[topo] && d > 0)
            {
                topo--;
                d--;
            }
            resultado[++topo] = atual;
        }
        while (d > 0)
        {
            topo--;
            d--;
        }
        resultado[topo + 1] = '\0';
        printf("%s\n", resultado);
    }
    return 0;
}