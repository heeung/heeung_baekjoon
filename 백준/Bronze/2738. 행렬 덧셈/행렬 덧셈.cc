#include <iostream>
using namespace std;

int arr1[10000] = {0, };
int arr2[10000] = {0, };

int main()
{
        int N, M, cnt = 0;

        scanf("%d %d", &N, &M);
        for (int i = 0 ; i < N * M ; i++)
                scanf("%d", &arr1[i]);
        for (int i = 0 ; i < N * M ; i++)
                scanf("%d", &arr2[i]);
        for (int i = 0 ; i < N * M ; i++)
        {
                printf("%d ", arr1[i] + arr2[i]);
                cnt++;
                if (cnt == M)
                {
                        printf("\n");
                        cnt = 0;
                }
        }
}