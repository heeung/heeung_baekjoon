#include <stdio.h>

int stack[500002][2];
int sp;
int N;

void push(int h, int i)
{
        stack[sp][0] = h;
        stack[sp][1] = i;
        sp++;
}

int main(void)
{
        int i, H, res;

        scanf("%d", &N);
        for (i = 0 ; i < N ; i++)
        {
                res = 0;
                scanf("%d", &H);
                while (sp && stack[sp-1][0] < H)
                        sp--;
                if (sp == 0)
                {
                        push(H, i);
                        printf("0 ");
                }
                else if (stack[sp - 1][0] >= H)
                {
                        printf ("%d ", stack[sp - 1][1] + 1);
                        push (H, i);
                }
        }
}