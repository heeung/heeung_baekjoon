#include <stdio.h>

int max(int a, int b){
        if (a > b)
                return a;
        else if (a < b)
                return b;
}

int main(void)
{
        int N, i, num, res = 0;
        int arr[1000005] = {0, };

        scanf("%d", &N);
        for (i = 1 ; i <= N ; i++)
        {
                scanf("%d", &num);
                arr[num] = arr[num - 1] + 1;
                res = max(res, arr[num]);
        }
        printf("%d\n", N - res);
}