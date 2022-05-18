#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
        int     age;
        char name[101];
}t_member;

int cmp(const void *a, const void *b)
{
        t_member *m1 = (t_member *)a;
        t_member *m2 = (t_member *)b;

        if (m1->age > m2->age)
                return (1);
        else if (m1->age < m2->age)
                return (-1);
        else
                return (0);
}

int main(void)
{
        int N, i;
        t_member *members;

        scanf("%d", &N);
        members = (t_member *)malloc(sizeof(t_member) * N);
        for (i = 0 ; i < N ; i++)
                scanf("%d %s", &members[i].age, members[i].name);
        qsort(members, N, sizeof(t_member), cmp);
        for (i = 0 ; i < N ; i++)
                printf("%d %s\n", members[i].age, members[i].name);
        free(members);
        return (0);
}
