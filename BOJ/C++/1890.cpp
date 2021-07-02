#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility>
using namespace std;
int n;
queue <pair <int, int >>q;
int **arr;
long long **cache;
long long ans;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
void bfs()
{
	int x, y;
	int x_dist, y_dist;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		x_dist = arr[x][y];
		y_dist = arr[x][y];
		for (int i = 0; i < 2; i++)
		{
			if ((x + dx[i] * x_dist >= 0 && x + dx[i] * x_dist <= n - 1) && (y + dy[i] * y_dist >= 0 && y + dy[i] * y_dist <= n - 1))
			{
				if (arr[x + dx[i] * x_dist][y + dy[i] * y_dist] != 0)
				{
					q.push(make_pair(x + dx[i] * x_dist, y + dy[i] * y_dist));
				}
				else
				{
					if (x + dx[i] * x_dist == n - 1 && y + dy[i] * y_dist == n - 1)
					{
						ans++;
					}
					else
					{
						break;
					}
				}
			}
		}
		q.pop();
	}
}
long long dfs(int x, int y)
{
	long long temp = 0;
	int dist = arr[x][y];
	if (x == 0 && y == 0)
	{
		return 1;
	}
	if (cache[x][y] != -1)
	{
		return cache[x][y]; 
	}
	for (int i = 0; i < x; i++)
	{
		if (i + arr[i][y] == x)
		{
			temp += dfs(i,y);
			//cout << "(" << x << " , " << y << " )" << "<-(" << i << " , " << y << " )" << endl;
		}
	}
	for (int i = 0; i < y; i++)
	{
		if (i + arr[x][i] == y)
		{
			temp += dfs(x,i);
			//cout << "(" << x << " , " << y << " )" << "<- (" << x << " , " << i << " )" << endl;
		}
	}

	return cache[x][y] = temp;
}
int main(void)
{
	cin >> n;
	arr = (int **)malloc(sizeof(int *)*n);
	cache = (long long **)malloc(sizeof(long long *)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*n);
		cache[i] = (long long *)malloc(sizeof(long long)*n);
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			cache[i][j] = -1; 
		}
	}
	//q.push(make_pair(0, 0));
	//bfs();
	cache[0][0] = 0;
	dfs(n-1,n-1);
	cout << cache[n-1][n-1];
	/*
	cout << endl; 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cache[i][j]<<" ";
		}
		cout << "\n"; 
	}
	*/
	//system("pause");
	return 0;
}