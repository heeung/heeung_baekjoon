#include <stdio.h>
#include <stdlib.h>

int     brute_force(int *arr, int N, int M)
{
        int     i, j, k;
        int     sum = 0;
        int     best = 0;

        i = 0;
        while (i < N - 2)
        {
                j = i + 1;
                while (j < N - 1)
                {
                        k = j + 1;
                        while (k < N)
                        {
                                sum = arr[i] + arr[j] + arr[k];
                                if (abs(sum - M) <= abs(best - M) && sum <= M)
                                        best = sum;
                                k++;
                        }
                        j++;
                }
                i++;
        }
        return (best);
}

int     main(void)
{
        int     N, M;
        int     arr[100] = {0};

        scanf("%d %d", &N, &M);
        for (int i=0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        printf("%d\n", brute_force(arr, N, M));
}
