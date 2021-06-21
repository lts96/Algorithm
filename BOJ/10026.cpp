#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans1, ans2;
int arr[101][101];
bool visit[101][101];
queue <pair <int, int>>q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void bfs()
{
	int x, y,nx,ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (!visit[nx][ny] && arr[nx][ny] == arr[x][y])
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
void bfs2()
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (!visit[nx][ny])
				{
					if ((arr[x][y] == arr[nx][ny]) || (arr[x][y] != 3 && arr[nx][ny] != 3))
					{
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		q.pop();
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			if (c == 'R')
				arr[i][j] = 1;
			else if (c == 'G')
				arr[i][j] = 2;
			else
				arr[i][j] = 3;
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	*/
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
				bfs();
				if (arr[i][j] == 1)
					r++;
				else if (arr[i][j] == 2)
					g++;
				else
					b++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
	}
	ans1 = r + g + b;
	r = g = b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
				bfs2();
				if (arr[i][j] == 1)
					r++;
				else if (arr[i][j] == 2)
					g++;
				else
					b++;
			}
		}
	}
	ans2 = r+g + b;
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}