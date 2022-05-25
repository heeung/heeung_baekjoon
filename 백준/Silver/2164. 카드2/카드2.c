#include <stdio.h>

int dat[1000005], head = 0, tail = 0;

void push(int x){
        dat[tail++] = x;
}

void pop(){
        head++;
}

void move(){
        dat[tail++] = dat[head++];
}


int main(void)
{
        int N, i;

        scanf("%d", &N);
        for (i = 1 ; i <= N ; i++)
                push(i);
        while (N > 1 && (tail - head) > 1)
        {
                pop();
                move();
                N--;
        }
        printf("%d\n", dat[head]);
}