#include <iostream>
using namespace std;

int recur(int n, int cnt)
{
        if (cnt == 0)
                return (1);
        return (n * recur(n, cnt - 1));
}

int main()
{
        int num, res = 0;
        scanf("%d", &num);

        while (num != 0)
        {
                res += recur(num % 10, 5);
                num = num / 10;
        }
        printf("%d\n", res);
}