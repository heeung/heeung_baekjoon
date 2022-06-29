#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
        int N;
        int arr[11];

        scanf("%d", &N);
        while (N--)
        {
                for (int i = 0 ; i < 10 ; i++)
                        scanf("%d", &arr[i]);
                sort(arr, arr + 10);
                printf("%d\n", arr[7]);
        }
}