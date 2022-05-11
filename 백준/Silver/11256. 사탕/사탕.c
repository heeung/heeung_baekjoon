#include <stdio.h>

void    bubble_sort(int *arr, int N)
{
        int     i, j, swp;

        i = 0;
        while (i < N - 1)
        {
                j = 0;
                while (j < N - 1)
                {
                        if (arr[j] < arr[j + 1])
                        {
                                swp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = swp;
                        }
                        j++;
                }
                i++;
        }
}

int     main(void)
{
        int     T = 0, J = 0, N = 0;
        int     C , R;
        int arr[1000] = {0};
        int i, cnt;

        scanf("%d", &T);
        while (T)
        {
                cnt = 0;
                scanf("%d %d", &J, &N);
                i = 0;
                while (i < N)
                {
                        C = 0;
                        R = 0;
                        scanf("%d %d", &C, &R);
                        arr[i] = C * R;
                        i++;
                }
                bubble_sort(arr, N);
                i = 0;
                cnt = 0;
                while (i < N)
                {
                        J = J - arr[i];
                        cnt++;
                        if (J <= 0)
                        {
                                printf("%d\n", cnt);
                                break ;
                        }
                        i++;
                }
                T--;
        }
        return (0);
}
