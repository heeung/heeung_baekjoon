#include <stdio.h>
#include <stdlib.h>

int      cmp(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b);
}

int main(void)
{
        int     N, i;
        int arr[1000000] = {0};

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        qsort(arr, N, sizeof(int), cmp);
        for (i = 0 ; i < N ; i++)
                printf("%d\n", arr[i]);
}