#include <iostream>
#include <stdlib.h>
using namespace std; 
int n , white , blue; 
int **arr;

void divide(int size , int x1 , int x2 , int y1, int y2)
{
	int flag = arr[x1][y1];
	if (size == 1)
	{
		if (flag == 1)
			blue++;
		else
			white++;
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
					divide(size / 2, x1 , x1 + size/2 , y1 , y1+ size/2);  // 왼쪽 상단
					divide(size / 2, x1 + size / 2 , x2 , y1, y1 + size / 2); // 오른쪽 상단
					divide(size / 2, x1, x1 + size / 2, y1 + size / 2, y2);
					divide(size / 2, x1 + size / 2, x2 , y1 + size / 2, y2);
					//cout << "divide! \n";
					return;
				}
			}
		}
		if (flag == 1)
			blue++;
		else
			white++;
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
			cin >> arr[i][j];
		}
	}
	divide(n,0,n, 0 , n);
	
	cout << white << endl;
	cout << blue << endl; 
	//system("pause");
	return 0;
}