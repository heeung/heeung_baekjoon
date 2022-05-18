#include <stdio.h>
#include <stdlib.h>

typedef struct dot
{
        int x;
        int y;
}t_dot;

int cmp_x(const void *a, const void *b)
{
        t_dot *d1 = (t_dot *)a;
        t_dot *d2 = (t_dot *)b;

        if (d1->x > d2->x)
                return (1);
        else if (d1->x < d2->x)
                return (-1);
        else
                return (0);
}

int cmp_y(const void *a, const void *b)
{
        t_dot *d1 = (t_dot *)a;
        t_dot *d2 = (t_dot *)b;

        if (d1->y > d2->y)
                return (1);
        else if (d1->y < d2->y)
                return (-1);
        else
                return (0);
}

int main(void)
{
        int N, i;
        t_dot *dots;

        scanf("%d", &N);
        dots = (t_dot *)malloc(sizeof(t_dot) * N);
        for (i = 0 ; i < N ; i++)
                scanf("%d %d", &dots[i].x, &dots[i].y);
        qsort(dots, N, sizeof(t_dot), cmp_x);
        qsort(dots, N, sizeof(t_dot), cmp_y);
        for (i = 0 ; i < N ; i++)
                printf("%d %d\n", dots[i].x, dots[i].y);
        free(dots);
        return (0);
}
