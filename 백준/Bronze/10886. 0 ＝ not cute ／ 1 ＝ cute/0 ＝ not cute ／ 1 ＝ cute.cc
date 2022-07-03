#include <iostream>
using namespace std;

int main()
{
    int N, ct = 0, nct = 0, a;
    scanf("%d", &N);
    
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &a);
        if (a == 0)
            nct++;
        else if (a == 1)
            ct++;
    }
    if (ct > nct)
        printf("Junhee is cute!\n");
    else
        printf("Junhee is not cute!\n");
}