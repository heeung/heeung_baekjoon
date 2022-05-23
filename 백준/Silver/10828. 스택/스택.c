#include <stdio.h>
#include <string.h>

int stack[1000005] = {0, };
int pos = 0;

void push(int x)
{
        stack[pos] = x;
        pos++;
}

void pop()
{
        if (pos > 0)
        {
                printf("%d\n", stack[pos - 1]);
                stack[pos - 1] = 0;
                pos--;
                return ;
        }
        printf("-1\n");
}

void top()
{
        if (pos > 0)
                printf("%d\n", stack[pos - 1]);
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
                if (strcmp(str, "push") ==  0)
                {
                        scanf("%d", &num);
                        push(num);
                }
                else if (strcmp(str, "pop") == 0)
                        pop();
                else if (strcmp(str, "size") == 0)
                        printf("%d\n", pos);
                else if (strcmp(str, "empty") == 0)
                {
                        if (pos != 0)
                                printf("0\n");
                        else
                                printf("1\n");
                }
                else if (strcmp(str, "top") == 0)
                        top();
        }
}
