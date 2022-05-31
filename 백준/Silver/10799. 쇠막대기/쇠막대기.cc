#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);

        string str;
        int cnt = 0;
        cin >> str;
        stack<int> dat;
        for (int i = 0 ; i < str.size() ; i++) {
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
        cout << cnt << endl;
}