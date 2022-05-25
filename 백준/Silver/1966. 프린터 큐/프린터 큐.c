#include <stdio.h>

int main() 
{
	int cnt, n, m;
	int i, j, k;
	int arr[100] = { 0, };

	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++)
	{
		scanf("%d %d", &n, &m);
		int res = 1;
		int head = 0;
		int tail = 0;
		for (j = 0; j < n; j++)
			scanf("%d", &arr[j]);
		while (1) 
		{
			for (k = 0; k < n; k++)
				if (arr[k] > tail)
                    tail = arr[k];
			while (arr[head] != tail)
				head = (head + 1) % n;
			if (head == m)
                break;
			arr[head] = 0;
			head = (head + 1) % n;
			tail = 0;
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}