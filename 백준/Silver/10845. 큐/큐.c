#include <stdio.h>
#include <string.h>

int dat[2000010], head = 0, tail = 0;

void push(int x){
        dat[tail++] = x;
}

void pop(){
        if (tail - head > 0)
                printf("%d\n", dat[head++]);
        else
                printf("-1\n");
}

void front(){
        if (tail - head > 0)
                printf("%d\n", dat[head]);
        else
                printf("-1\n");
}

void back(){
        if (tail - head > 0)
                printf("%d\n", dat[tail - 1]);
        else
                printf("-1\n");
}

int main(void)
{
        int N, i, num;
        char str[6];

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
        {
                scanf("%s", str);
                if (strcmp(str, "push") == 0)
                {
                        scanf("%d", &num);
                        push(num);
                }
                else if (strcmp(str, "pop") == 0)
                        pop();
                else if (strcmp(str, "size") == 0)
                        printf("%d\n", (tail - head));
                else if (strcmp(str, "empty") == 0)
                {
                        if ((tail - head) > 0)
                                printf("0\n");
                        else
                                printf("1\n");
                }
                else if (strcmp(str, "front") == 0)
                        front();
                else if (strcmp(str, "back") == 0)
                        back();
        }
}