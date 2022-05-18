#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
        if (*(long long *)a > *(long long *)b)
                return (1);
        else if (*(long long *)a < *(long long *)b)
                return (-1);
        else
                return (0);
}

int main(void)
{
        int N, i, j, cntn, max_idx;
        long long max;
        long long nb[100001] = {0};
        long long nb_c[100001] = {0};
        int cnt[100001] = {0};

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%lld", &nb[i]);
        qsort(nb, N, sizeof(long long), cmp);
        //for (i = 0 ; i < N ; i++)
        //      printf("%lld ", nb[i]);
        j = 0;
        cntn = 1;
        long long sum = nb[0];
        int res = 0;
        for (i = 0 ; i < N - 1 ; i++)
        {
                if (nb[i] == nb[i + 1])
                {
                        cntn++;
                        if (cntn > res)
                        {
                                res = cntn;
                                sum = nb[i];
                        }
                        continue;
                }
                cntn = 1;
        }
        /*max = 0;
        max_idx = 0;
        for (i = 0 ; i < N ; i++)
        {
                if (max < cnt[i])
                {
                        max = cnt[i];
                        max_idx = i;
                }
        }*/
        printf("%lld\n", sum);
        return (0);
}
