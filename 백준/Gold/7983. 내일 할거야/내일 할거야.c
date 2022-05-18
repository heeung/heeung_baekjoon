#include <stdio.h>
#include <stdlib.h>

typedef struct quest
{
        int     day;
        int end;
} quest_t;

int compare(const void *a, const void *b)
{
        quest_t *q1 = (quest_t *)a;
        quest_t *q2 = (quest_t *)b;

        if (q1->end > q2->end)
                return (1);
        else if (q1->end < q2->end)
                return (-1);
        else
                return (0);
}

int     main(void)
{
        int     n, i, max, now;
        quest_t arr[1000001] = {0, };

        scanf("%d", &n);
        for (i = 0 ; i <= n ; i++)
        {
                if (i == 0)
                {
                        arr[i].day = 0;
                        arr[i].end = 0;
                }
                else
                {
                        scanf("%d %d", &arr[i].day, &arr[i].end);
                }
        }

        qsort(arr, n + 1, sizeof(quest_t), compare);
        max = 0;
        now = 0;
        for (i = n ; i > 0 ; i--)
        {
                if (now < 0)
                        now = arr[i].end - arr[i - 1].end - arr[i].day + now;
                else
                        now = arr[i].end - arr[i - 1].end - arr[i].day;
                max = now;
        }
        printf("%d\n", max);
        return (0);
}
