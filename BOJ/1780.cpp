#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
int n;     // n= 3^k 
int ans[3];
int **arr; 
void div(int k , int r , int c)   
{
	bool check=false;
	int temp;
	if (k == 1)
	{
		ans[arr[r][c] + 1]++;
		return; 
	}
	else
	{
		temp = arr[r][c]; 
		for (int i = r; i < r+k; i++)
		{
			for (int j = c; j < c+k; j++)
			{
				if (arr[i][j] != temp)
				check = true; 
			}
		}
		if (check == true) // 자르기 
		{
			div(k / 3,r,c);
			div(k / 3,r+k/3,c);
			div(k / 3,r+k/3*2,c);
			div(k / 3, r, c+k/3);
			div(k / 3, r+k / 3, c+k/3);
			div(k / 3, r+k / 3 * 2, c+k/3);
			div(k / 3, r, c+k/3*2);
			div(k / 3, r+k / 3, c+k/3*2);
			div(k / 3, r+k / 3 * 2, c+k/3*2);
			return; 
		}
		else
		{
			ans[temp + 1]++;
		}
	}
}
int main(void)
{
	cin >> n;
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) 
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	div(n,0,0);
	cout << ans[0] << endl; // -1
	cout << ans[1] << endl; //  0
	cout << ans[2] << endl; //  1
	//system("pause"); 
	return 0; 
}