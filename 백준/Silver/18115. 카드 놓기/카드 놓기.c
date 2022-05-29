#include <stdio.h>

int dat[2000011], head = 1000005, tail = 1000005;

void push(int x){
        dat[tail++] = x;
}

void push_front(int x){
        dat[--head] = x;
}

void pop_back(){
        tail--;
}

void pop_front(){
        head++;
}

int main(void)
{
        int N, i;
        int arr[1000000];
        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
                scanf("%d", &arr[i]);

        int card = 1;
        for (i = N - 1 ; i >= 0 ; i--)
        {
                if (arr[i] == 1)
                        push(card);
                else if (arr[i] == 2)
                {
                        int tmp = dat[tail - 1];
                        pop_back();
                        push(card);
                        push(tmp);
                }
                else if (arr[i] == 3)
                        push_front(card);
                card++;
        }
        for (i = N - 1 ; i >= 0 ; i--)
                printf("%d ", dat[--tail]);
}