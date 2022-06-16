#include <iostream>
using namespace std;

int main()
{
        int N, K, cnt = 0;
        int stu[2][7] = {0, };

        scanf("%d %d", &N, &K);
        for (int i = 0 ; i < N ; i++)
        {
                int a, b;
                scanf("%d %d", &a, &b);
                stu[a][b]++;
        }
        for (int i = 0 ; i < 2 ; i++)
        {
                for (int j = 1 ; j < 7 ; j++)
                {
                        cnt += stu[i][j] / K;
                        if (stu[i][j] % K)
                                cnt++;
                }
        }
        printf("%d", cnt);
}