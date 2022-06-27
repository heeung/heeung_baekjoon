#include <iostream>
using namespace std;

int main()
{
    long long S, tot = 0;
    int cnt = 0;
    scanf("%lld", &S);
    int i = 1;
    while (1)
    {
        tot += i;
        cnt++;
        if (tot > S)
        {
            cnt--;
            break ;
        }
        i++;
    }
    printf("%d\n", cnt);
}