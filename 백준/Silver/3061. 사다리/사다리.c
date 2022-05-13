#include <stdio.h>

int solve(int *arr, int N)
{
    int i, j, swp, cnt;
    
    i = 0;
    cnt = 0;
    while (i < N - 1)
    {
        j = 0;
        while (j < N - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swp;
                cnt++;
            }
            j++;
        }
        i++;
    }
    return (cnt);
}

int main(void)
{
    int T, N, i;
    
    scanf("%d", &T);
    while (T)
    {
        i = 0;
        scanf("%d", &N);
        int arr[1000] = {0};
        while (i < N)
        {
            scanf("%d", &arr[i]);   
            i++;
        }
        printf("%d\n", solve(arr, N));
        T--;
    }
    return (0);
}