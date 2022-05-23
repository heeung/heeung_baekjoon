#include <stdio.h>

int stack[1000005] = {0, };
int pos = 0;

void push(int x){
        stack[pos++] = x;
}

void pop(){
        pos--;
}

int main(void)
{
        int N, i, num;
        long long int cnt;

        scanf("%d", &N);
        cnt = 0;
        while (N--)
        {
                scanf("%d", &num);
                while (num >= stack[pos - 1] && pos > 0)
                        pop();
                push(num);
                cnt = cnt + (long long)pos - 1;
        }
        printf("%lld\n", cnt);
}