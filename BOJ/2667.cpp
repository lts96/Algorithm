#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int n;
int **arr;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int apart_num;
int apart[630];

void dfs(int x, int y) 
{
	short flag = 0;
	arr[x][y] = apart_num + 2;

	if (apart[apart_num] == 0)
		apart[apart_num]++;

	for (int i = 0; i < 4; i++)
	{
		if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
		{
			if (arr[x + dx[i]][y + dy[i]] == 1)
			{
				apart[apart_num]++;
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
	return;
}
void find()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				dfs(i, j);
				apart_num++;

			}

		}
	}

}
int main(void)
{
	cin >> n;
	arr = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	find();
	/*
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	cout << apart_num << endl;
	sort(apart, apart + 630);
	for (int i = 0; i < 630; i++)
	{
		if (apart[i] != 0 && apart[i] != 1)
			cout << apart[i] << endl;
		if (apart[i] == 1)
			cout << apart[i] << endl;
	}
	//system("pause");
	return 0;
}