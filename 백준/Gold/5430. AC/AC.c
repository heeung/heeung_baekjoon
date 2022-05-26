#include <stdio.h>
#include <stdlib.h>

int dat[2000011], head, tail, cnt_R;

void push(int x){
        dat[tail++] = x;
}

void reverse(){
        cnt_R++;
}

void pop(){
        if (cnt_R % 2 == 0)
                head++;
        else
                tail--;
}

void mk_int(char *str)
{
        int num = 0;
        int i = 0;

        while ('0' <= str[i] && str[i] <= '9')
        {
                num = num * 10 + str[i] - '0';
                i++;
        }
        push(num);
}

void print_dat(){
        if (tail - head == 0)
        {
                printf("[]\n");
                return ;
        }
        if (cnt_R % 2 == 0)
        {
                int num = head;
                while (tail - head)
                {
                        if (num == head)
                                printf("[");
                        printf("%d", dat[head]);
                        if (head != tail - 1)
                                printf(",");
                        else
                                printf("]");
                        head++;
                }
        }
        else
        {
                int num = tail - 1;
                while (tail - head)
                {
                        if (num == tail - 1)
                                printf("[");
                        printf("%d", dat[tail - 1]);
                        if (head != tail - 1)
                                printf(",");
                        else
                                printf("]");
                        tail--;
                }
        }
        printf("\n");
}

int main(void)
{
        int T, n, i, idx, flag;
        char p[100001], x[1500000];

        scanf("%d", &T);
        while (T--)
        {
                flag = 0;
                scanf("%s", p);
                scanf("%d", &n);
                scanf("%s", x);
                cnt_R = 0;
                head = 1000005;
                tail = 1000005;
                i = 0;
                while (x[i])
                {
                        while ((x[i] == '[' || x[i] == ',') && x[i] != '\0')
                                i++;
                        if ('0' <= x[i] && x[i] <= '9' && x[i] != '\0')
                                mk_int(&x[i]);
                        while ('0' <= x[i] && x[i] <= '9' && x[i] != '\0')
                                i++;
                        if (x[i] == ']')
                                i++;
                }
                for (i = 0 ; p[i] ; i++)
                {
                        if (p[i] == 'R')
                        {
                                        reverse();
                        }
                        else if (p[i] == 'D')
                        {
                                if (tail - head > 0)
                                        pop();
                                else
                                {
                                        printf("error\n");
                                        flag = 1;
                                        break ;
                                }
                        }
                }
                if (flag == 0)
                        print_dat();
        }
}