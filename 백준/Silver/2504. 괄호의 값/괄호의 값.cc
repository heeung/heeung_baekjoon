#include <iostream>
#include <stack>
using namespace std;

int main()
{
        stack<char> dat;
        char str[31];
        int ans = 0, res = 1, err = 0;

        scanf("%s", str);
        for (int i = 0 ; str[i] ; i++) {
                if (str[i] == '(') {
                        dat.push('(');
                        res *= 2;
                }
                else if (str[i] == '[') {
                        dat.push('[');
                        res *= 3;
                }
                else if (str[i] == ')') {
                        if (dat.empty() || dat.top() != '(') {
                                err = 1;
                                break ;
                        }
                        if (dat.top() == '(') {
                                if (str[i - 1] == '(')
                                        ans += res;
                                dat.pop();
                                res /= 2;
                        }
                }
                else if (str[i] == ']') {
                        if (dat.empty() || dat.top() != '[') {
                                err = 1;
                                break ;
                        }
                        if (dat.top() == '[') {
                                if (str[i - 1] == '[')
                                        ans += res;
                                dat.pop();
                                res /= 3;
                        }
                }
        }
        if (err == 1 || !dat.empty())
                printf("0\n");
        else
                printf("%d\n", ans);
}