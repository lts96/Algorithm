#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
int n, ans;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue <pair <int, int>> q;
void clear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
	}
	return;
}
void bfs(int h)
{
	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx > n || ny < 0 || ny > n)
				continue;
			if (arr[nx][ny] > h && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
		q.pop();
	}
	return;
}
int find(int h)
{
	int cnt = 0;
	clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > h && !visit[i][j])
			{
				visit[i][j] = true;
				cnt++;
				q.push(make_pair(i, j));
				bfs(h);
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			d = max(arr[i][j], d);
		}
	}
	for (int i = 0; i < d; i++)
		ans = max(ans, find(i));
	cout << ans << endl;
	return 0;
}
