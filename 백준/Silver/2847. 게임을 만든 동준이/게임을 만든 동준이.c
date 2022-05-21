#include <stdio.h>

int main(void)
{
        int N, i, flag, max;
        int arr[101] = {0,};
        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        flag = 0;
        max = arr[N - 1];
        int res = 0;
        for (i = N - 2 ; i >= 0 ; i--)
        {
                if (arr[i] >= max)
                {
                        res = res + (arr[i] - (max - 1));
                        arr[i] = max - 1;
                        max = arr[i];
                }
                else
                        max = arr[i];
        }
        printf("%d\n", res);
}
