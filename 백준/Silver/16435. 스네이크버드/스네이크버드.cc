#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, L, arr[10001];
    
    scanf("%d %d", &N, &L);
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    for (int i = 0 ; i < N ; i++)
    {
        if (arr[i] <= L)
            L++;
        else
            break ;
    }
    printf("%d\n", L);
}