#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *serial(char *str_s)
{
        int i = 0;
        char *arr;

        arr = (char *)malloc(sizeof(char) * strlen(str_s) + 1);
        for (i = 0 ; i < strlen(str_s) ; i++)
                arr[i] = str_s[i];
        arr[i] = '\0';
        return (arr);
}

int cmp(const void *a, const void *b)
{
        return (strcmp(*(char **)a, *(char **)b));
}

int sum_nbs(char *a)
{
        int     i = 0;
        int sum = 0;
        while (a[i])
        {
                if ('0' <= a[i] && a[i] <= '9')
                        sum = sum + a[i] - '0';
                i++;
        }
        return (sum);
}

int main(void)
{
        int N, i, j;
        char **str;
        char str_s[51];
        char *swp;

        scanf("%d", &N);
        str = (char **)malloc(sizeof(char *) * (N + 1));
        for (i = 0 ; i < N ; i++)
        {
                scanf("%s", str_s);
                str[i] = serial(str_s);
        }
        qsort(str, N, sizeof(char *), cmp);
        for (i = 0 ; i < N - 1 ; i++)
        {
                for (j = 0 ; j < N - 1 ; j++)
                {
                        if (strlen(str[j]) > strlen(str[j + 1]))
                        {
                                swp = str[j];
                                str[j] = str[j + 1];
                                str[j + 1] = swp;
                        }
                        else if (strlen(str[j]) == strlen(str[j + 1]))
                        {
                                if (sum_nbs(str[j]) > sum_nbs(str[j + 1]))
                                {
                                        swp = str[j];
                                        str[j] = str[j + 1];
                                        str[j + 1] = swp;
                                }
                        }
                }
        }
        for (i = 0 ; i < N ; i++)
                printf("%s\n", str[i]);
        free(str);
        return (0);
}
