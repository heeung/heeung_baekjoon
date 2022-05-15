#include <stdio.h>

void    bubble_sort(int *arr, int N)
{
        int     swp;
        for (int i = 0 ; i < N - 1 ; i++)
        {
                for(int j = 0 ; j < N - 1 ; j++)
                {
                        if (arr[j] > arr[j + 1])
                        {
                                swp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = swp;
                        }
                }
        }
}

int     main(void)
{
        int     N, L, len, cnt, flag;
        int arr[1000] = {0};

        scanf("%d %d", &N, &L);
        for (int i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        bubble_sort(arr, N);
        len = L;
        cnt = 1;
        flag = 1;
        if (L == 1)
        {
                printf("%d\n", N);
                return (0);
        }
        for (int i = 0 ; i < N - 1 ; i++)
        {
                if (len <= 0 || flag == 0)
                {
                        cnt++;
                        len = L;
                }
                if (arr[i + 1] - arr[i] < len)
                {
                        len = len - (arr[i + 1] - arr[i]);
                        flag = 1;
                        continue ;
                }
                flag = 0;
        }
        if (flag == 0)
                cnt++;
        printf("%d\n", cnt);
}
