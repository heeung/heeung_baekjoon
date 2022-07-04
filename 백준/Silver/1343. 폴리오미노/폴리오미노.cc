#include <iostream>
#include <cstring>
using namespace std;

char board[51];
int idx = 0;

void fill_A()
{
        for (int i = 0 ; i < 4 ; i++)
                board[idx++] = 'A';
}

void fill_B()
{
        for (int i = 0 ; i < 2 ; i++)
                board[idx++] = 'B';
}

int main()
{
        int cnt = 0;
        scanf("%s", board);
        for (int i = 0 ; i < strlen(board) + 1 ; i++)
        {
                if (board[i] == 'X')
                        cnt++;
                else
                {
                        if (cnt % 2 == 0)
                        {
                                while (cnt)
                                {
                                        if (cnt >= 4)
                                        {
                                                fill_A();
                                                cnt -= 4;
                                                continue ;
                                        }
                                        fill_B();
                                        cnt -= 2;
                                }
                                if (board[i] == '.')
                                        idx++;
                        }
                        else
                        {
                                printf("-1\n");
                                return (0);
                        }
                }
        }
        printf("%s\n", board); 
}