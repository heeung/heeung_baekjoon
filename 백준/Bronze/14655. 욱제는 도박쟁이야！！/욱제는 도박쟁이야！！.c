#include <stdio.h>
#include <stdlib.h>


int main(void)
{
        int     N, i, result;
        int arr[10000] = {0};

        result = 0;
        scanf("%d", &N);
        i = 0;
        while (i < N)
        {
                scanf("%d", &arr[i]);
                i++;
        }
        i = 0;
        while (i < N)
        {
                arr[i] = abs(arr[i]);
                result = result + arr[i];
                i++;
        }
        i = 0;
        while (i < N)
        {
                scanf("%d", &arr[i]);
                i++;
        }
        i = 0;
        while (i < N)
        {
                arr[i] = abs(arr[i]);
                result = result + arr[i];
                i++;
        }
        printf("%d\n", result);
}
