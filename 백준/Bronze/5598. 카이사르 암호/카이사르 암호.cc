#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    char ch;
    for(int i = 0 ; i < len ; i++)
    {
        char c = str[i];
        if(c >= 65 && c <= 67)
            ch = c + 23;
        else
            ch = c - 3;
        cout << ch;
    }
}