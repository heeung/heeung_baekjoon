#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool is_used[10];

void backtracking(int num)
{
        if (num == M)
        {
                for (int i = 0 ; i < M ; i++)
                        printf("%d ", arr[i]);
                printf("\n");
                return ;
        }
        for (int i = 1 ; i <= N ; i++)
        {
                if (!is_used[i])
                {
                        arr[num] = i;
                        is_used[i] = true;
                        backtracking(num + 1);
                        is_used[i] = false;
                }
        }
}

int main()
{
        scanf("%d %d", &N, &M);
        backtracking(0);
}