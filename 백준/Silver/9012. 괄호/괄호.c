#include <stdio.h>

int stack[10000] = {0, };
int pos = 0;

void push(char x){
        if (x == '(')
                stack[pos++] = 1;
        else
                stack[pos++] = -1;
}

int main(void)
{
        int T, i, res;
        char str[51];

        scanf("%d", &T);
        while (T)
        {
                res = 0;
                scanf("%s", str);
                for (i = 0 ; str[i] ; i++)
                {
                        push(str[i]);
                        res += stack[pos - 1];
                        if (res < 0)
                        {
                                printf("NO\n");
                                break ;
                        }
                }
                if (res > 0)
                        printf("NO\n");
                else if (res == 0)
                        printf("YES\n");
                T--;
        }

}