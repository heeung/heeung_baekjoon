#include <iostream>
using namespace std;

int main()
{
        int K, N, M;

        scanf("%d %d %d", &K, &N, &M);
        if (K * N > M)
                printf("%d\n", K * N - M);
        else if (K * N <= M)
                printf("0\n");
}