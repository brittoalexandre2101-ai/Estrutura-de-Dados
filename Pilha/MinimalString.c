#include <stdio.h>
#define max 1000005

void resolver(char s[], char t[], char u[])
{
    int freq[26] = {0};
    int top = 0, tam_u = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        t[top++] = s[i];
        freq[s[i] - 'a']--;
        while (top > 0)
        {
            char topo = t[top - 1];
            int existe_menor = 0;
            for (int j = 0; j < topo - 'a'; j++)
            {
                if (freq[j] > 0)
                {
                    existe_menor = 1;
                    break;
                }
            }
            if (existe_menor)
                break;
            u[tam_u++] = t[--top];
        }
    }
    while (top > 0)
    {
        u[tam_u++] = t[--top];
    }
    u[tam_u] = '\0';
}

int main()
{
    char s[max], t[max], u[max];
    scanf("%s", s);
    resolver(s, t, u);
    printf("%s\n", u);
    return 0;
}