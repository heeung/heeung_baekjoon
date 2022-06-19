#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int dat[1000005];
    int n;
    
    scanf("%d", &n);
    dat[1] = 0;
    for (int i = 2 ; i <= n ; i++)
    {
        dat[i] = dat[i - 1] + 1;
        if (i % 2 == 0)
           dat[i] = min(dat[i], dat[i / 2] + 1);
        if (i % 3 == 0)
           dat[i] = min(dat[i], dat[i / 3] + 1);
    }
    printf("%d", dat[n]);
}