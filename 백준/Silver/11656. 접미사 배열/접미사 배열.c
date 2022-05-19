#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
        return (strcmp(*(char **)a, *(char **)b));
}

int main(void)
{
        int i;
        char str[1001];
        char **str_s;

        scanf("%s", str);
        str_s = (char **)malloc(sizeof(char *) * (strlen(str) + 1));
        for (i = 0 ; i < strlen(str) ; i++)
                str_s[i] = strdup(&str[i]);
        qsort(str_s, strlen(str), sizeof(char *), cmp);
        for (i = 0 ; i < strlen(str) ; i++)
                printf("%s\n", str_s[i]);
        free(str_s);
}