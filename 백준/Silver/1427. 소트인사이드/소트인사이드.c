#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main(void)
{
    int N, i, num, cnt;
    int *arr;
    
    scanf("%d", &N);
    cnt = 0;
    num = N;
    while (num > 0)
    {
        num = num / 10;
        cnt++;
    }
    arr = (int *)malloc(sizeof(int) * cnt);
    i = cnt - 1;
    num = N;
    while (num > 0)
    {
        arr[i] = num % 10;
        num = num / 10;
        i--;
    }
    qsort(arr, cnt, sizeof(int), cmp);
    for (i = 0 ; i < cnt ; i++)
        printf("%d", arr[i]);
    free(arr);
    return (0);
}