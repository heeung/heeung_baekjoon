#include <stdio.h>
#include <string.h>

int main()
{
	while(1)
	{
		char arr[102];
		char board[102];
		int pos = 0;
		int flag = 0;
		
		fgets(arr,102,stdin);
		if (arr[0]=='.')
			break;
		for (int i = 0 ; arr[i] ; i++)
		{
			if (arr[i] == '(')
				board[pos++] = '(';
			else if (arr[i]==')')
			{
				if (board[pos - 1]=='(')
				{
					board[pos - 1] = 0 ;
					pos--;
				}
				else if (pos < 0)
				    flag++;
				else
				    flag++;
			}
			else if (arr[i] == '[')
				board[pos++]= '[';
			else if (arr[i]==']')
			{
				if (board[pos - 1] == '[')
				{
					board[pos - 1] = 0;
					pos--;	
				}
				else if (pos < 0)
				    flag++;
				else
				    flag++;
			}
		}
		if (flag > 0)
		    printf("no\n");
		else if (pos > 0)
		    printf("no\n");
		else
		    printf("yes\n");
	}
 }