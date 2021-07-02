#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
using namespace std;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int arr[101][101];
bool visit[101][101];
queue <pair<int, int>> q;
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int isExist()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
				cnt++;
		}
	}
	return cnt;
}
void bfs()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
	}
	q.push(make_pair(0, 0));
	visit[0][0] = true;
	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1)
					arr[nx][ny] = 2;
				if (!visit[nx][ny] && arr[nx][ny] == 0)
				{
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	return;
}
void melt()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 1)
				arr[i][j] = 0;
		}
	}
	return;
}
int main(void)
{
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				cnt++;
		}
	}
	int ans = 0;
	int prev;
	while (1)
	{
		cnt = isExist();
		if (cnt > 0)
		{
			bfs();
			//print();
			melt();
			ans++;
			prev = cnt;
		}
		else
			break;
	}
	cout << ans << endl;
	cout << prev << endl;
	return 0;
}