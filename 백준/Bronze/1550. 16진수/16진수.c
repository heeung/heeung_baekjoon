#include <stdio.h>

int base_to_dec(char str, char *base)
{
        int i = 0;

        while (base[i])
        {
                if (base[i] == str)
                        return (i);
                i++;
        }
        return (-1);
}

int main()
{
        char str[7];
        int num = 0;
        scanf("%s", str);

        for (int i = 0 ; str[i] ; i++)
                num = num * 16 + base_to_dec(str[i], "0123456789ABCDEF");
        printf("%d\n", num);
}