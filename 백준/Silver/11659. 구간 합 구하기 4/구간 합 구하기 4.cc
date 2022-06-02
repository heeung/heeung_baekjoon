#include <iostream>

int main()
{
        int N, M, i, a, b, num;
        int arr[100001] = {0, };
        int dp[100001] = {0, };

        scanf("%d %d", &N, &M);
        for (i = 1 ; i <= N ; i++) {
                scanf("%d", &num);
                arr[i] = num;
                dp[i] = num + dp[i - 1];
        }
        while (M--)
        {
                scanf("%d %d", &a, &b);
                printf("%d\n", dp[b] - dp[a - 1]);
        }
}