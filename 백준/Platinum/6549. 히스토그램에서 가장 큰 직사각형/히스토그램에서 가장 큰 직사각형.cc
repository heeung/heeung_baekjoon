#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
        int i;
        while (1)
        {
                int n;
                scanf("%d", &n);
                if (n == 0)
                        break;
                stack<pair<long long, long long>> dat;
                long long ans = 0;
                for (i = 0 ; i < n ; i++)
                {
                        int num, idx = i;
                        scanf("%d", &num);
                        while (!dat.empty() && dat.top().first >= num)
                        {
                                ans = max(ans, (i - dat.top().second) * dat.top().first);
                                idx = dat.top().second;
                                dat.pop();
                        }
                        dat.push({num, idx});
                }
                while (!dat.empty())
                {
                        ans = max(ans, (n - dat.top().second) * dat.top().first)       ;
                        dat.pop();
                }
                printf("%lld\n", ans);
        }
}