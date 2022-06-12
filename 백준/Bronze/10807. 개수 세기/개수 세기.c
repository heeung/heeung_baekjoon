#include <stdio.h>

int main(){
    int arr[100000] = {0, };
    int n, v, cnt = 0;
    
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &v);
    for (int i= 0 ; i < n ; i++)
    {
        if (v == arr[i])
            cnt++;
    }
    printf("%d\n", cnt);
}