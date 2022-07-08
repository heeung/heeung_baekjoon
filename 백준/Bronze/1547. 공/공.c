#include <stdio.h>

int main()
{
        int M;
        scanf("%d", &M);
        int arr[4] = {0, 1, 0, 0};
        for (int i = 0 ; i < M ; i++)
        {
                int a, b;
                scanf("%d %d", &a, &b);
                if (arr[a] == 0 && arr[b] == 0)
                        continue ;
                else
                {
                        int swp = arr[a];
                        arr[a] = arr[b];
                        arr[b] = swp;
                }
        }
        for (int i = 0 ; i < 4 ; i++)
        {
                if (arr[i] == 1)
                {
                        printf("%d\n", i);
                        return (0);
                }
        }
}