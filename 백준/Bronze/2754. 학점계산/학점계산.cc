#include <iostream>
#include <string>
using namespace std;

int main()
{
        string a;

        cin >> a;
        if (a.compare("A+") == 0)
                printf("4.3\n");
        else if (a.compare("A0") == 0)
                printf("4.0\n");
        else if (a.compare("A-") == 0)
                printf("3.7\n");
        else if (a.compare("B+") == 0)
                printf("3.3\n");
        else if (a.compare("B0") == 0)
                printf("3.0\n");
        else if (a.compare("B-") == 0)
                printf("2.7\n");
        else if (a.compare("C+") == 0)
                printf("2.3\n");
        else if (a.compare("C0") == 0)
                printf("2.0\n");
        else if (a.compare("C-") == 0)
                printf("1.7\n");
        else if (a.compare("D+") == 0)
                printf("1.3\n");
        else if (a.compare("D0") == 0)
                printf("1.0\n");
        else if (a.compare("D-") == 0)
                printf("0.7\n");
        else if (a.compare("F") == 0)
                printf("0.0\n");
}