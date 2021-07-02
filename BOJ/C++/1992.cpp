#include <iostream>
#include <stdlib.h>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int n , white , blue; 
int **arr;
string ans = "";
void divide(int size , int x1 , int x2 , int y1, int y2 )
{
	int flag = arr[x1][y1];
	if (size == 1)
	{
		if (flag == 1)
			ans += "1";
		else
			ans += "0";
		return; 
	}
	else
	{
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				if (arr[i][j] != flag) 
				{
					ans += "(";
					divide(size / 2, x1 , x1 + size/2 , y1 , y1+ size/2 );  // 왼쪽 상단
					divide(size / 2, x1, x1 + size / 2, y1 + size / 2, y2);
					divide(size / 2, x1 + size / 2 , x2 , y1, y1 + size / 2 ); // 오른쪽 상단
					//divide(size / 2, x1, x1 + size / 2, y1 + size / 2, y2 );
					divide(size / 2, x1 + size / 2, x2 , y1 + size / 2, y2);
					ans += ")";
					return;
				}
			}
		}
		if (flag == 1)
			ans += "1";
		else
			ans += "0";
		return;
	}
}

int main(void)
{
	cin >> n;
	arr = new int *[n]; 
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	divide(n,0,n, 0 , n );
	cout << ans << endl;
	//system("pause");
	return 0;
}