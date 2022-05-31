#include <iostream>
using namespace std;

int main() {
        int zero[41] = {1, 0, };
        int one[41] = {0, 1, };
        int T, num;

        cin >> T;
        while (T--) {
                cin >> num;
                for (int i = 2 ; i <= num ; i++) {
                        zero[i] = zero[i - 1] + zero[i - 2];
                        one[i] = one[i - 1] + one[i - 2];
                }
                cout << zero[num] << " " << one[num] << endl;
        }
}