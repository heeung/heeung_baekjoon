#include <stdio.h>
#include <string.h>

int dat[2000011], head = 1000005, tail = 1000005;

void push_front(int x){
        dat[--head] = x;
}

void push_back(int x){
        dat[tail++] = x;
}

void pop_front(){
        if (tail - head <= 0)
                printf("-1\n");
        else
                printf("%d\n", dat[head++]);
}

void pop_back(){
        if (tail - head <= 0)
                printf("-1\n");
        else
                printf("%d\n", dat[--tail]);
}

void front(){
        if (tail - head <= 0)
                printf("-1\n");
        else
                printf("%d\n", dat[head]);
}

void back(){
        if (tail - head <= 0)
                printf("-1\n");
        else
                printf("%d\n", dat[tail - 1]);
}

int main(void)
{
        int N, i, num;
        char str[20];

        scanf("%d", &N);
        while (N)
        {
                scanf("%s", str);
                if (strcmp(str, "push_front") == 0)
                {
                        scanf("%d", &num);
                        push_front(num);
                }
                else if (strcmp(str, "push_back") == 0)
                {
                        scanf("%d", &num);
                        push_back(num);
                }
                else if (strcmp(str, "pop_front") == 0)
                        pop_front();
                else if (strcmp(str, "pop_back") == 0)
                        pop_back();
                else if (strcmp(str, "size") == 0)
                        printf("%d\n", tail - head);
                else if (strcmp(str, "empty") == 0)
                {
                        if (tail - head > 0)
                                printf("0\n");
                        else
                                printf("1\n");
                }
                else if (strcmp(str, "front") == 0)
                        front();
                else if (strcmp(str, "back") == 0)
                        back();
                N--;
        }
}