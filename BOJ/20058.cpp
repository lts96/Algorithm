#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
using namespace std;
queue<pair<int, int>> q;
int n, l, sum, ans;
int s;
int arr[100][100];
int melt[100][100];
int arr2[100][100];
bool visit[100][100];
void rotate(int sx, int sy, int dx, int dy , int p)
{
	for (int x = 0; x <= dx-sx; x++)
	{
		for (int y = 0; y <= dy-sy; y++)
		{
			arr2[sx + y][sy + p - 1 - x] = arr[sx + x][y+sy];
			//cout << sx+x << " " << sy+y << " -> " << sx+y << " " << sy+p - 1 - x << endl;
		}
	}
	for (int x = sx; x <= dx; x++)
	{
		for (int y = sy; y <= dy; y++)
			arr[x][y] = arr2[x][y];
	}
	return;
}
void firestorm(int level)
{
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int p = pow(2, level);
	for (int i = 0; i < s; i += p)
	{
		for (int j = 0; j < s; j += p)
		{
			rotate(i, j, i + p - 1, j + p - 1, p);
			melt[i][j] = 0;
		}
	}
	int cnt, x, y;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				x = i + dx[k];
				y = j + dy[k];
				if (x >= 0 && x < s && y >= 0 && y < s)
				{
					if (arr[x][y])
						cnt++;
				}
			}
			if (cnt < 3)
				melt[i][j]--;
		}
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if(arr[i][j])
				arr[i][j] += melt[i][j];
			melt[i][j] = 0;
			//cout << arr[i][j] << " ";
		}
		//cout << endl;
	}
	return;
}
void bfs(int a, int b)
{
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	visit[a][b] = true;
	q.push(make_pair(a, b));
	int x, y, nx, ny;
	int cnt = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int k = 0; k < 4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];
			if (nx >= 0 && nx < s && ny >= 0 && ny < s)
			{
				if (arr[nx][ny] && !visit[nx][ny])
				{
					cnt++;
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	ans = max(ans, cnt);
	return;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	s = pow(2, n);
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
			cin >> arr[i][j];
	}
	int t;
	for (int i = 0; i < l; i++)
	{
		cin >> t;
		firestorm(t);
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
			sum += arr[i][j];
	}
	cout << sum << "\n";
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (arr[i][j] && !visit[i][j])
				bfs(i, j);
		}
	}
	cout << ans << "\n";
	return 0;
}