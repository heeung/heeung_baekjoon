#include <stdio.h>

int main(void)
{
        char S[101];
        char al[27] = "abcdefghijklmnopqrstuvwxyz";
        int al_n[26] = {0};

        scanf("%s", S);
        for (int i = 0 ; al[i] ; i++)
        {
                for (int j = 0 ; S[j] ; j++)
                {
                        if (al[i] == S[j])
                                al_n[i]++;
                }
        }
        for (int i = 0 ; i < 26 ; i++)
                printf("%d ", al_n[i]);
}
