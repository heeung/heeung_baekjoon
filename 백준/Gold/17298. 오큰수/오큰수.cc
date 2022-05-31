#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> dat;

int main() {
        int N, i;
        int arr[1000001];
        int ans[1000001];

        cin >> N;
        for (i = 0 ; i < N ; i++)
                cin >> arr[i];

        for (i = N ; i >= 0 ; i--) {
                while (!dat.empty() && dat.top() <= arr[i])
                        dat.pop();
                if (dat.empty())
                        ans[i] = -1;
                else
                        ans[i] = dat.top();
                dat.push(arr[i]);
        }
        for (i = 0 ; i < N ; i++)
                cout <<ans[i] << " ";
}