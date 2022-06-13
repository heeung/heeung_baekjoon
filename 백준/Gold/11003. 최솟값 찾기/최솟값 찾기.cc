#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main(void)
{
        int n, m, i;
        deque<pair<int, int>> dat;

        scanf("%d %d", &n, &m);
        for (i = 1 ; i <= n ; i++)
        {
                int num;
                scanf("%d", &num);
                while (!dat.empty() && dat.back().second >= num)
                        dat.pop_back();
                dat.push_back({i, num});
                if (dat.front().first <= i - m)
                        dat.pop_front();
                printf("%d ", dat.front().second);
        }
}