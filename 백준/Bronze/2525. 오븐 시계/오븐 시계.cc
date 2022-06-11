#include <iostream>

int main(void)
{
        int A, B, C;

        scanf("%d %d", &A, &B);
        scanf("%d", &C);
        B = B + C;
        if (B >= 60)
        {
                int n = B / 60;
                B = B % 60;
                A = A + n;
                if (A >= 24)
                        A = A - 24;
        }
        printf("%d %d", A, B);
}