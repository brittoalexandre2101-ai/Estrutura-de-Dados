#include <stdio.h>
#define max 200005

int main()
{
    int n;
    scanf("%d", &n);

    int valor[max];
    int pos[max];
    int topo = -1;

    for (int i = 0; i < n; i++)
    {
        int atual;
        scanf("%d", atual);

        while (topo >= 0 && valor[topo] >= atual)
        {
            topo--;
        }
        if (topo == -1)
            printf("0 ");
        else
            printf("%d", pos[atual]);
        topo++;
        valor[topo] = atual;
        pos[topo] = i;
    }
    printf("\n");
    return 0;
}