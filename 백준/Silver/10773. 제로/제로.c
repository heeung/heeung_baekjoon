#include <stdio.h>

int stack[1000005] = {0, };
int pos;

void pop()
{
        stack[pos - 1] = 0;
        pos--;
}

int main(void)
{
        int K, num;

        scanf("%d", &K);
        for (int i = 0 ; i < K ; i++)
        {
                scanf("%d", &num);
                if (num == 0)
                        pop();
                else
                        stack[pos++] = num;
        }
        int res = 0;
        for (int j = 0 ; j < pos ; j++)
                res = res + stack[j];
        printf("%d\n", res);
}
