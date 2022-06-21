#include <iostream>
#include <string>
using namespace std;

int main()
{
        while (1)
        {
                string str;
                getline (cin, str);
                if (str == "\0")
                        break;
                cout << str << "\n";
        }
}