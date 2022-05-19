#include <stdio.h>
#include <stdlib.h>

int sort_up(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b);
}

int sort_dn(const void *a, const void *b)
{
        return (*(int *)b - *(int *)a);
}


int main(void)
{
        int N, i;
        int arr1[51] = {0};
        int arr2[51] = {0};

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr1[i]);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr2[i]);
        qsort(arr1, N, sizeof(int), sort_up);
        qsort(arr2, N, sizeof(int), sort_dn);
        int res = 0;
        for (i = 0 ; i < N ; i++)
                res = res + (arr1[i] * arr2[i]);
        printf("%d\n", res);
}
