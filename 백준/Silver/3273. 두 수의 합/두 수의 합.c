#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b);
}

int main(void)
{
        int n, i, x, cnt = 0;
        int arr[100001] = {0};

        scanf("%d", &n);
        for (i  = 0 ; i < n ; i++)
                scanf("%d", &arr[i]);
        scanf("%d", &x);
        qsort(arr, n, sizeof(int), cmp);
        int left = 0, right = n - 1;

        while (left < right)
        {
                if (arr[left] + arr[right] == x)
                {
                        cnt++;
                        left++;
                }
                else if (arr[left] + arr[right] > x)
                        right--;
                else
                        left++;
        }
        printf("%d\n", cnt);
}
