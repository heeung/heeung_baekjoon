#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
        int N, arr[100001], ans = 0;

        scanf("%d", &N);
        for (int i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr + N);
        for (int i = 0 ; i < N ; i++)
                ans = max(ans, (N - i) * arr[i]);
        printf("%d", ans);
}