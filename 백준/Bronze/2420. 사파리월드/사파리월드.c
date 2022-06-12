#include <stdio.h>
#include <stdlib.h>

long long do_abs(long long N, long long M)
{
    long long num;
    num = N - M;
    if (num < 0)
        return (-num);
    else
        return (num);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%lld\n", do_abs(N, M));
}