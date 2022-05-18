#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
        return (*(int *)b - *(int *)a);
}

int main(void)
{
        int N, i;
        int arr[1000001] = {0};

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        qsort(arr, N, sizeof(int), cmp);
        for (i = 0 ; i < N ; i++)
                printf("%d\n", arr[i]);
}
