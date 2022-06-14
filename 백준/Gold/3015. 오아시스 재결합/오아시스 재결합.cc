#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
        stack<pair<int, int>> dat;
        int N;
        long long ans = 0;

        scanf("%d", &N);
        while (N--)
        {
                int num;
                int cnt = 1;
                scanf("%d", &num);
                while (!dat.empty() && dat.top().first <= num)
                {
                        ans += dat.top().second;
                        if (dat.top().first == num)
                                cnt += dat.top().second;
                        dat.pop();
                }
                if (!dat.empty())
                        ans++;
                dat.push({num, cnt});
        }
        printf("%lld\n", ans);
}