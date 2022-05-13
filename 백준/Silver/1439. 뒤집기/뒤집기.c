#include <stdio.h>

int     len(char *a)
{
        int     i;

        i = 0;
        while (a[i] != '\0')
                i++;
        return (i);
}

int     choose(char *arr, int i)
{
        int     count_zero = 0;
        int     count_one = 0;
        int     flag = -1;
        int j = 0;

        while (j < i)
        {
                if (arr[j] == '0' && flag != 0)
                {
                        count_zero++;
                        flag = 0;
                }
                if (arr[j] == '1' && flag != 1)
                {
                        count_one++;
                        flag = 1;
                }
                j++;
        }
        if (flag == -1)
                return (0);
        if (count_zero > count_one)
                return (count_one);
        else
                return (count_zero);
}

int     main(void)
{
        char    arr[1000000];
        int             i;

        scanf("%s", arr);
        i = len(arr);
        printf("%d\n", choose(arr, i));
}
