#include <iostream>
#include <cstdlib>

int is_tied = 0;

int cmp_desc(const void *a, const void *b) {
        return (*(int *)b - *(int *)a);
}

int cmp_asc(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
}

int main()
{
        int N, num, i, res = 0;
        int idx_p = 0, idx_m = 0;
        int arr_p[51] = {0, };
        int arr_m[51] = {0, };

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
        {
                scanf("%d", &num);
                if (num > 0)
                        arr_p[idx_p++] = num;
                else
                        arr_m[idx_m++] = num;
        }
        qsort(arr_p, idx_p, sizeof(int), cmp_desc);
        qsort(arr_m, idx_m, sizeof(int), cmp_asc);

        // plus result
        i = 0;
        while (i < idx_p)
        {
                if (arr_p[i + 1] == 1 || arr_p[i] == 1)
                {
                        res = res + arr_p[i];
                        i++;
                        continue ;
                }
                if (i + 1 == idx_p)
                        res = res + arr_p[i];
                else
                        res = res + arr_p[i] * arr_p[i + 1];
                i += 2;
        }
        // minus result
        i = 0;
        while (i < idx_m)
        {
                if (i + 1 == idx_m)
                        res = res + arr_m[i];
                else
                        res = res + arr_m[i] * arr_m[i + 1];
                i += 2;
        }
        printf("%d\n", res);
}