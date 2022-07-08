#include <stdio.h>

int main()
{
        int point = 0;
        for (int i = 0 ; i < 5 ; i++)
        {
                int num;
                scanf("%d", &num);
                point += num;
        }
        printf("%d\n", point);
}