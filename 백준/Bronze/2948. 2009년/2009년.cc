#include <iostream>
using namespace std;

typedef long long ll;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m;
char w[7][20]={"Wednesday", "Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday"};

int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 1 ; i < n ; i++)
        m+=mon[i];
    printf("%s",w[m%7]);
}