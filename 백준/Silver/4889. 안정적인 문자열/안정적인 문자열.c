#include <stdio.h>
#include <stdlib.h>

int     len(char *arr)
{
        int     i;

        i = 0;
        while (arr[i] != '\0')
                i++;
        return (i);
}

void reset(char *arr)
{
        for (int i=0 ; arr[i] ; i++)
                arr[i] = '\0';
}

int     main(void)
{
        char arr[2000];
        int     cnt, temp;
        int     num = 1;
        int     flag = 0;

        while (1)
        {
                cnt = 0;
                temp = 0;
                int i;
                scanf("%s", arr);
                for (i=0 ; arr[i] ; i++)
                {
                        if (arr[i] == '-')
                                return (0);
                }
                for (i = 0 ; i < len(arr) ; i++)
                {
                        if (arr[i] == '{')
                                temp++;
                        if (arr[i] == '}')
                                temp--;
                        if (temp < 0)
                        {
                                cnt++;
                                temp = -temp;
                        }
                }
                cnt = cnt + (temp / 2);
                printf("%d. %d\n", num, cnt);
                num++;
                reset(arr);
        }
        return (0);
}
