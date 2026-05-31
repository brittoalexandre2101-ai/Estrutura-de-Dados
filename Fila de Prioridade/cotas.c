#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main()
{
    int n;
    ll q;
    scanf("%d %lld", &n, &q);

    ll *c = malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++)
        scanf("%lld", &c[i]);

    ll baixo = 0, alto = 1e18, volta = 0;
    while (baixo <= alto)
    {
        ll meio = baixo + (alto - baixo) / 2;
        ll soma = 0;
        for (int i = 0; i < n; i++)
        {
            if (c[i] < meio)
                soma += c[i];
            else
                soma += meio;
            if (soma > q)
                break;
        }
        if (soma <= q)
        {
            volta = meio;
            baixo = meio + 1;
        }
        else
            alto = meio - 1;
    }

    ll distribuido = 0;
    ll *resultado = malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++)
    {
        if (c[i] < volta)
            resultado[i] = c[i];
        else
            resultado[i] = volta;
        distribuido += resultado[i];
    }

    ll resto = q - distribuido;
    for (int i = 0; i < n && resto > 0; i++)
    {
        if (c[i] > volta)
        {
            resultado[i]++;
            resto--;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld%c", resultado[i], i == n - 1 ? '\n' : ' ');

    free(c);
    free(resultado);
    return 0;
}