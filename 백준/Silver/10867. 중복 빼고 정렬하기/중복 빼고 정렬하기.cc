#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    
    scanf("%d", &N);
    vector<int> arr(N);
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for (int i = 0 ; i < arr.size() ; i++)
        printf("%d ", arr[i]);
}