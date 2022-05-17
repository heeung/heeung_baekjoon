#include <stdio.h>

int     click(int a)
{
        if (a == 0)
                return (1);
        if (a == 1)
                return (0);
}

int main(void)
{
        int N, i, cnt;
        int arr1[1000002] = {0};
        int     arr2[1000002] = {0};

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr1[i]);
        cnt = 0;
        for (i = 0 ; i < N ; i++)
        {
                if (arr1[i] != arr2[i])
                {
                        arr2[i] = click(arr2[i]);
                        arr2[i + 1] = click(arr2[i + 1]);
                        arr2[i + 2] = click(arr2[i + 2]);
                        cnt++;
                }
        }
        printf("%d\n", cnt);
}
