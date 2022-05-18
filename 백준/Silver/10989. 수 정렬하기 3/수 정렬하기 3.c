#include <stdio.h>

int     main(void)
{
        int N, num;
        int     cnt[10002] = {0};

        scanf("%d", &N);
        for (int i = 0 ; i < N ; i++)
        {
                scanf("%d", &num);
                cnt[num]++;
        }
        for (int i = 0 ; i <= 10001 ; i++)
        {
                if (cnt[i] == 0)
                        continue;
                for (int j = 0 ; j < cnt[i] ; j++)
                        printf("%d\n", i);
        }
        return (0);
}
