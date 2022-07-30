#include <stdio.h>

int dOM[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *dOW[7] {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
	int month, day;
	scanf("%d %d", &month, &day);
	for (int i = 1 ; i < month ; ++i)
    {
		day += dOM[i];
	}
	printf("%s\n", dOW[day % 7]);
}