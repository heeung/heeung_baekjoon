#include <stdio.h>

int dat[1000005], head = 0, tail = 0, ans[1000005], idx = 0;

void push(int x){
        dat[tail++] = x;
}

void go_back(){
        dat[tail++] = dat[head++];
}

void pop(){
        ans[idx++] = dat[head++];
}

int main(void)
{
        int N, K, i, cnt;

        scanf("%d %d", &N, &K);
        for (i = 1 ; i <= N ; i++)
                push(i);
        while ((tail - head) > 0)
        {
                cnt = K;
                while (cnt - 1)
                {
                        go_back();
                        cnt--;
                }
                pop();
        }
        for (i = 0 ; i < N ; i++)
        {
                if (i == 0)
                        printf("<");
                printf("%d", ans[i]);
                if (i != N - 1)
                        printf(", ");
                if (i == N - 1)
                        printf(">\n");
        }
}