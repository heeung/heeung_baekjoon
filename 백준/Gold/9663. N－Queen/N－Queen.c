#include <stdio.h>
#include <stdlib.h>

int is_possible(int n, int *chess, int j)
{
        chess[n] = j;
        for (int i = 0 ; i < n ; i++)
        {
                if (chess[n] == chess[i] || abs(chess[n] - chess[i]) == abs(n - i))
                        return (0);
        }
        return (1);
}

void    recursive_queen(int space, int *chess, int *cnt, int N)
{
        int     i;

        if (space == N)
                *cnt += 1;
        i = -1;
        while (++i < N)
        {
                if (is_possible(space, chess, i) == 1)
                {
                        chess[space] = i;
                        recursive_queen(space + 1, chess, cnt, N);
                }
        }
}

int main(void)
{
        int     chess[15];
        int cnt, N;

        cnt = 0;
        scanf("%d", &N);
        recursive_queen(0, chess, &cnt, N);
        printf("%d\n", cnt);
}