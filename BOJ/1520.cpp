#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;
int m,n;
int **arr;
long long **cache;
long long ans;
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0 ,0,-1};
long long dfs(int x, int y)
{
	long long temp = 0;
	
	if (x == 0 && y == 0)
	{
		return 1;
	}
	if (cache[x][y] != -1)
	{
		return cache[x][y];
	}
	
	
	for (int i=0;i<4;i++)
	{
		if ((x + dx[i] >= 0 && x + dx[i] <= m - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
		{
			if (arr[x][y] < arr[x + dx[i]][y + dy[i]])
			{
				temp += dfs(x+dx[i], y+dy[i]);
				//cout << x + dx[i] << " " << y + dy[i] << endl;
			}
		}
	}


	return cache[x][y] = temp;
}
int main(void)
{
	cin >> m;
	cin >> n;
	arr = (int **)malloc(sizeof(int *)*m);
	cache = (long long **)malloc(sizeof(long long *)*m);
	for (int i = 0; i < m; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*n);
		cache[i] = (long long *)malloc(sizeof(long long)*n);
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			cache[i][j] = -1;
		}
	}
	
	cache[0][0] = 0;
	dfs(m - 1, n - 1);
	cout << cache[m - 1][n - 1];
	/*
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cache[i][j]<<" ";
		}
		cout << "\n";
	}*/
	
	//system("pause");
	return 0;
}
