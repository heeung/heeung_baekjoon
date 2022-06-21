#include <iostream>
using namespace std;

int main()
{
        int n, i;
        int arr[31] = {0, };

        for (i = 0 ; i < 28 ; i++)
        {
                scanf("%d", &n);
                arr[n] = 1;
        }
        for (i = 1 ; i <= 30 ; i++)
        {
                if (arr[i] == 0)
                        printf("%d\n", i);
        }
}