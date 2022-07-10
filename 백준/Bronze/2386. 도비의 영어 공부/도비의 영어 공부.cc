#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    string str;
    
    while(1)
    {
        cin>>ch;
        getline(cin, str);
        if(ch=='#')
            break;
        int len=str.length();
        int cnt=0;
        for(int i=0; i<len; i++)
            if(str[i]==ch||str[i]==toupper(ch))
                cnt++;
        cout<<ch<<" "<<cnt<<"\n";
    }
}