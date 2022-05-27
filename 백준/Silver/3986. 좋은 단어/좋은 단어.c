#include <stdio.h>

char dat[1000005];
int pos = 0;

void pop(){
        pos--;
}

void push(char x){
        dat[pos++] = x;
}

int main(void)
{
        int N, i, cnt;

        scanf("%d", &N);
        cnt = 0;
        while (N--)
        {
                pos = 0;
                char str[100001];
                scanf("%s", str);
                for (int j = 0 ; str[j] ; j++)
                {
                        if (pos > 0 && dat[pos - 1] == str[j])
                        {
                                pop();
                                continue ;
                        }
                        push(str[j]);
                }
                if (pos == 0)
                        cnt++;
        }
        printf("%d\n", cnt);
}