#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
        int n;
        int arr[1002];
        vector<int> sm;

        scanf("%d", &n);
        for (int i = 0 ; i < n ; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr + n);
        for (int i = 0 ; i < n ; i++)
        {
                for (int j = i ; j < n ; j++)
                        sm.push_back(arr[i] + arr[j]);
        }
        sort(sm.begin(), sm.end());
        for (int i = n - 1 ; i > 0 ; i--)
        {
                for (int j = 0 ; j < i ; j++)
                {
                        if (binary_search(sm.begin(), sm.end(), arr[i] - arr[j]))
                        {
                                printf("%d", arr[i]);
                                return (0);
                        }
                }
        }
}