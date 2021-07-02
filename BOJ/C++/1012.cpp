#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std; 
int n, m , k;
int **arr;
int test; 
int ans; 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
queue <pair<int, int> > q;
void bfs();
void find()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = 0;
				q.push(make_pair(i, j));
				bfs();
				ans++;
			}
		}
	}
}
void bfs()
{
	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i<4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= m - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
			{
				if (arr[x + dx[i]][y + dy[i]] == 1)
				{
					arr[x + dx[i]][y + dy[i]] = 0;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
		}
		q.pop();
	}
}
int main(void)
{
	int x, y;
	cin >> test; 
	for (int h = 0; h < test; h++)
	{
		cin >> m >> n >> k;
		arr = (int **)malloc(sizeof(int *)*m);
		for ( int i = 0; i < m; i++)
			arr[i] = (int *)malloc(sizeof(int)*n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = 0;
		}

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y; 
			arr[x][y] = 1;
		}
		find();
		cout << ans << endl; 
		ans = 0;
	}
	//system("pause"); 
	return 0; 
}
