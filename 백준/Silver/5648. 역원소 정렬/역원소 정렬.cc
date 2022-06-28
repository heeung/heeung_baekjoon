#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
        int n;
        string str;
        vector<long long> arr;
        scanf("%d", &n);
        for (int i = 0 ; i < n ; i++)
        {
                cin >> str;
                reverse(str.begin(), str.end());
                arr.push_back(stoll(str));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0 ; i < n ; i++)
                printf("%lld\n", arr[i]);
}