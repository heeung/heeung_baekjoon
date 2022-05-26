#include <stdio.h>

const int MX = 1000005;
int dat[2000011];
int head = MX, tail = MX, res = 0;;

void push_back(int x){
        dat[tail++] = x;
}

void pop_front(){
        head++;
}

void go_back(){
        dat[tail++] = dat[head++];
        res++;
}

void go_front(){
        dat[--head] = dat[--tail];
        res++;
}

int main(void)
{
        int N, M, i;
        int arr[100] = {0, };

        scanf("%d %d", &N, &M);
        for (i = 1 ; i <= N ; i++)
                push_back(i);
        for (i = 0 ; i < M ; i++)
                scanf("%d", &arr[i]);
        i = 0;
        while (i < M)
        {
                int cnt1 = 0, cnt2;
                int a = head;
                while (arr[i] != dat[a])
                {
                        cnt1++;
                        a++;
                }
                cnt2 = tail - head - cnt1 - 1;
                while (arr[i] != dat[head])
                {
                        if (cnt2 < cnt1)
                                go_front();
                        else
                                go_back();
                }
                pop_front();
                i++;
        }
        printf("%d\n", res);
}