#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int     T, N, max, cnt, k;
        int     arr1[10000] = {0}, arr2[10000] = {0};
        int     max_idx;

        scanf("%d", &T);
        while (T)
        {
                scanf("%d", &N);
                for (int i = 0 ; i < N ; i++)
                        scanf("%d", &arr1[i]);
                cnt = N;
                k = 0;
                while (cnt)
                {
                        max = 0;
                        max_idx = 0;
                        for (int j = 0 ; j < N ; j++)
                        {
                                if (arr1[j] > max)
                                {
                                        max = arr1[j];
                                        max_idx = j;
                                }
                        }
                        if (k == 0)
                        {
                                arr2[N / 2] = max;
                                k++;
                                cnt--;
                                arr1[max_idx] = 0;
                                continue ;
                        }
                        if (cnt % 2 == 1)
                        {
                                arr2[N / 2 - k] = max;
                                cnt--;
                                if (N % 2 == 1)
                                        k++;
                        }
                        else
                        {
                                arr2[N / 2 + k] = max;
                                cnt--;
                                if (N % 2 == 0)
                                        k++;
                        }
                        arr1[max_idx] = 0;
                }
                max = abs(arr2[0] - arr2[N - 1]);
                for (int a = 0 ; a < N - 1 ; a++)
                {
                        if (abs(arr2[a] - arr2[a + 1]) > max)
                                max = abs(arr2[a] - arr2[a + 1]);
                }
                printf("%d\n", max);
                T--;
        }
}
