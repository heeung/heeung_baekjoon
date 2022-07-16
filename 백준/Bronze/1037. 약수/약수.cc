#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int tot;

	cin >> tot;
	int *div = new int[tot];
	
	for (int i = 0 ; i < tot ; i++)
		cin >> div[i];

	sort(div, div+tot);
	cout << div[0] * div[tot - 1];
}