#include <iostream>
#include <stack>
using namespace std;

int main()
{

        char str[100001];
        int cnt = 0;
        scanf("%s", str);
        stack<int> dat;
        for (int i = 0 ; str[i] ; i++) {
                if (str[i] == '(')
                        dat.push(str[i]);
                else if (str[i] == ')' && str[i - 1] == '(') {
                        dat.pop();
                        cnt += dat.size();
                }
                else {
                        cnt++;
                        dat.pop();
                }
        }
        printf("%d\n", cnt);
}