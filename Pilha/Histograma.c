#include <stdio.h>
#include <stdint.h>

#define MAX 100000

void read_input(int *n, int *v)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void compute_prev(int *v, int *prev, int n)
{
    int stack[n];
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        while (sz > 0 && v[stack[sz - 1]] >= v[i])
        {
            sz--;
        }
        prev[i] = (sz == 0) ? -1 : stack[sz - 1];
        stack[sz++] = i;
    }
}

void compute_next(int *v, int *next, int n)
{
    int stack[n];
    int sz = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (sz > 0 && v[stack[sz - 1]] >= v[i])
        {
            sz--;
        }
        next[i] = (sz == 0) ? n : stack[sz - 1];
        stack[sz++] = i;
    }
}

void solve(int *v, int n)
{
    int prev[n];
    int next[n];
    compute_prev(v, prev, n);
    compute_next(v, next, n);
    int64_t area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = prev[i];
        int r = next[i];
        int64_t area_atual = (int64_t)v[i] * (r - l - 1);
        if (area_atual > area)
        {
            area = area_atual;
        }
    }
    printf("%ld\n", area);
}

int main()
{
    int n;
    int v[MAX];
    while (1)
    {
        read_input(&n, v);
        if (n == 0)
            break;
        solve(v, n);
    }
    return 0;
}