#include <stdio.h>

int stack[6][1000005] = {0, };
int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0;

void push(int jul, int x){
        if (jul == 1)
                stack[0][pos1++] = x;
        if (jul == 2)
                stack[1][pos2++] = x;
        if (jul == 3)
                stack[2][pos3++] = x;
        if (jul == 4)
                stack[3][pos4++] = x;
        if (jul == 5)
                stack[4][pos5++] = x;
        if (jul == 6)
                stack[5][pos6++] = x;

}

void pop(int jul){
        if (jul == 1)
                pos1--;
        if (jul == 2)
                pos2--;
        if (jul == 3)
                pos3--;
        if (jul == 4)
                pos4--;
        if (jul == 5)
                pos5--;
        if (jul == 6)
                pos6--;

}

int pos_num(int jul){
        if (jul == 1)
                return (pos1);
        if (jul == 2)
                return (pos2);
        if (jul == 3)
                return (pos3);
        if (jul == 4)
                return (pos4);
        if (jul == 5)
                return (pos5);
        if (jul == 6)
                return (pos6);
}

int main(void)
{
        int N, P, i, jul, num, cnt = 0;

        scanf("%d %d", &N, &P);
        for (i = 0 ; i < N ; i++)
        {
                scanf("%d %d", &jul, &num);
                while (stack[jul - 1][pos_num(jul) - 1] > num && pos_num(jul) > 0)
                {
                        pop(jul);
                        cnt++;
                }
                if (stack[jul - 1][pos_num(jul) - 1] == num && pos_num(jul) > 0)
                        continue ;
                push(jul, num);
                cnt++;
        }
        printf("%d\n", cnt);
}