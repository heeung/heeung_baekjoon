#include <stdio.h>

int stack[1000005] = {0, };
int pos = 0;
char prt[2000010];
int prt_idx = 0;

void push(int x){
        stack[pos++] = x;
        prt[prt_idx++] = '+';
}

void pop(){
        pos--;
        prt[prt_idx++] = '-';
}

int main(void)
{
        int n, i, j, err = 0, cnt = 0, arr[100005] = {0, };
        scanf("%d", &n);
        for (i = 0 ; i < n ; i++)
                scanf("%d", &arr[i]);
        i = 1;
        j = 0;
        while (cnt < n)
        {
                if (arr[j] == stack[pos - 1] && pos > 0)
                {
                        pop();
                        cnt++;
                        j++;
                        continue ;
                }
                if (i > n)
                {
                        err = 1;
                        break ;
                }
                push(i);
                i++;
        }
        if (err == 0)
                for (i = 0 ; prt[i] ; i++)
                        printf("%c\n", prt[i]);
        else
                printf("NO\n");
}