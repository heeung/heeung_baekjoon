#include <stdio.h>

int main(void)
{
        int N, i, cnt;
        int arr[1000001] = {0};

        scanf("%d", &N);
        cnt = 0;
        for (i = 0 ; i < N ; i++)
        {
                int in;
                scanf("%d", &in);
                if (arr[in + 1] == 0)
                {
                        arr[in]++;
                        cnt++;
                        continue ;
                }
                arr[in + 1]--;
                arr[in]++;
        }
        printf("%d\n", cnt);
}
