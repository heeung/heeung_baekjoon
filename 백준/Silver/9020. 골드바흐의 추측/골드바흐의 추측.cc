#include <iostream>
#include <cmath>

int is_prime(int n)
{
        int a;
        a = sqrt(n);
        if (a == 1 && n != 1)
                return (1);
        if (n % 2)
        {
                for (int i = 2 ; i <= a ; i++)
                {
                        if (!(n % i))
                                return (0);
                        if (i == a)
                                return (1);
                }
        }
}

int main(void)
{
        int T;

        scanf("%d", &T);
        for (int i = 0 ; i < T ; i++)
        {
                int n;
                scanf("%d", &n);
                for (int j = n / 2 ; j >= 2 ; j--)
                {
                        if (is_prime(j) == 1 && is_prime(n - j) == 1)
                        {
                                printf("%d %d\n", j, n - j);
                                break;
                        }
                }
        }
}