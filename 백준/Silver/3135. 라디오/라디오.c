#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int A = 0, B = 0, N = 0;
        int arr[6] = {0};
        int     i;
        int     best;
        int     cnt = 0;

        if (scanf("%d %d", &A, &B) != 2)
                return (0);
        if (scanf("%d", &N) != 1)
                return (0);
        i = 0;
        while (i < N)
        {
                scanf("%d", &arr[i]);
                i++;
        }
        i = 0;
        best = A;
        while (i < N)
        {
                if (abs(arr[i] - B) < abs(best - B))
                        best = arr[i];
                i++;
        }
        if (best != A)
                cnt++;
        if (best > B)
        {
                while (best > B)
                {
                        cnt++;
                        best--;
                }
        }
        else if (best < B)
        {
                while (best < B)
                {
                        cnt++;
                        best++;
                }
        }
        printf("%d\n", cnt);
        return (0);
}
