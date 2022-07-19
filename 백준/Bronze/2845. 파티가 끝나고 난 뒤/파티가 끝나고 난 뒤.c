#include <stdio.h>

int main()
{
    int L, P, arr[6] = {0, }, n, res;

    scanf("%d %d", &L, &P);
    n = L * P;
    for (int i = 0 ; i < 5 ; i++)
    {
        int num;
        scanf("%d", &num);
        res = num - n;
        arr[i] = res;
    }
	for (int i = 0 ; i < 5 ; i++)
	{
		printf("%d ", arr[i]);
	}
}