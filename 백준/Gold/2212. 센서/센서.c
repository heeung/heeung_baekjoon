#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b);
}

int main(void)
{
        int N, K, i, res = 0;
        int arr1[10001] = {0};
        int arr2[10001] = {0};

        scanf("%d", &N);
        scanf("%d", &K);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr1[i]);
        qsort(arr1, N, sizeof(int), cmp);
        for (i = 0 ; i < N - 1 ; i++)
                arr2[i] = arr1[i + 1] - arr1[i];
        qsort(arr2, N - 1, sizeof(int), cmp);
        for (i = 0 ; i < (N - 1) - (K - 1) ; i++)
                res = res + arr2[i];
        printf("%d\n", res);
        return (0);
}