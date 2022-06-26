#include <iostream>
using namespace std;

int sigma(int n, int *arr)
{
    int ret = 0;
    for (int i = 0 ; i < n ; i++)
        ret += arr[i];
    return (ret);
}

int main()
{
    int A, B, n = 1, cnt = 0;
    int arr[1001];
    
    scanf("%d %d", &A, &B);
    for (int i = 0 ; i < B ; i++)
    {
        arr[i] = n;
        cnt++;
        if (cnt == n)
        {
            n++;
            cnt = 0;
        }
    }
    printf("%d", (sigma(B, arr) - sigma(A - 1, arr)));
}