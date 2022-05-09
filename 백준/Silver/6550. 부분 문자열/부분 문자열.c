#include <stdio.h>

int     len(char *a)
{
        int     i;

        i = 0;
        while (a[i])
                i++;
        return (i);
}

int main(void)
{
        int             i, j;
        char    s[100000];
        char    t[100000];

        while (scanf("%s %s", s, t) == 2)
        {
                if (len(s) == 0 || len(t) == 0)
                        return (0);
                i = 0;
                j = 0;
                while (t[j])
                {
                        if (s[i] == t[j])
                                i++;
                        j++;
                }
                if (s[i] == '\0')
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return (0);
}
