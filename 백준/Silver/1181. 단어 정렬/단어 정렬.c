#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len_sort(const void *a, const void *b)
{
    return (strlen(*(char **)a) - strlen(*(char **)b));
}

int cmp(const void *a, const void *b)
{
    return (strcmp((*(char **)a), (*(char **)b)));
}

int main(void)
{
    int N, i, flag, cnt;
    char str_s[51];
    char **str;
    
    scanf("%d", &N);
    str = (char **)malloc(sizeof(char *) * (N + 1));
    i = 0;
    cnt = 0;
    while (cnt < N)
    {
        flag = 0;
        scanf("%s", str_s);
        for (int j = 0 ; j < i ; j++)
        {
            if (strcmp(str_s, str[j]) == 0)
            {
                cnt++;
                flag = 1;
                break ;
            }
        }
        if (flag == 1)
            continue ;
        str[i] = strdup(str_s);
        cnt++;
        i++;
    }
    qsort(str, i, sizeof(char *), cmp);
    qsort(str, i, sizeof(char *), len_sort);
    for (int j = 0 ; j < i ; j++)
        printf("%s\n", str[j]);
}