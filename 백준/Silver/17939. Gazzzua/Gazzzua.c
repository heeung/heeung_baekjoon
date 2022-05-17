#include <stdio.h>

int     ret_max_idx(int *arr, int f, int l)
{
        int max = 0, max_idx = 0;
        for (int i = f ; i <= l ; i++)
        {
                if (max < arr[i])
                {
                        max = arr[i];
                        max_idx = i;
                }
        }
        return (max_idx);
}

int main(void)
{
        int     N, i, flag, set, result;
        int     arr[100001] = {0};
        int     max_idx = 0;

        scanf("%d", &N);
        flag = 0;
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        set = 0;
        result = 0;
        i = 0;
        while (i < N)
        {
                max_idx = ret_max_idx(arr, set, N - 1);
                for (int j = set ; j < max_idx ; j++)
                        result = result + (arr[max_idx] - arr[j]);
                set = max_idx + 1;
                i = set;
        }
        printf("%d\n", result);
}