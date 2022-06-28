#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> dat;

int main()
{
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        dat.push(i);
    while(dat.size() != 1)
    {
        printf("%d ", dat.front());
        dat.pop();
        dat.push(dat.front());
        dat.pop();
    }
    printf("%d", dat.front());
}