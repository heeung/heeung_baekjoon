#include <stdio.h>

int main(void)
{
        int n, i, max, res, max_idx;
        int arr[100001] = {0};

        scanf("%d", &n);
        max = 0;
        max_idx = 0;
        for (i = 0 ; i < n ; i++)
        {
                scanf("%d", &arr[i]);
                if (max < arr[i])
                {
                        max = arr[i];
                        max_idx = i;
                }
        }
        res = 0;
        for (i = 0 ; i < n ; i++)
        {
                if (max_idx == i)
                        continue ;
                res = res + (max + arr[i]);
        }
        printf("%d\n", res);
}
