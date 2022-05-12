#include <stdio.h>

int not_self(int n)
{
        int result;

        result = n;
        while (n != 0)
        {
                result = result + (n % 10);
                n = n / 10;
        }
        return (result);
}

int     main(void)
{
        int     arr[100000] = {0};
        int     i, notself;

        i = 1;
        while (i <= 10000)
        {
                notself = not_self(i);
                arr[notself] = 1;
                i++;
        }
        i = 1;
        while (i <= 10000)
        {
                if (arr[i] == 0)
                        printf("%d\n", i);
                i++;
        }
        return (0);
}
