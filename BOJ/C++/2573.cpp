#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue < pair <int, int>> q;
int arr[301][301];
int arr_copy[301][301];
bool visit[301][301];
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}
int check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				cnt++;
		}
	}
	return cnt;
}
void melt()
{
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					x = i + dx[k];
					y = j + dy[k];
					if ((x >= 0 && x < n) && (y >= 0 && y < m))
					{
						if (arr[x][y] == 0)
							arr_copy[i][j]--;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = arr_copy[i][j];
			if (arr[i][j] < 0)
				arr[i][j] = 0;
		}
	}
	return;
}
void bfs()
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
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m))
			{
				if (arr[nx][ny] > 0 && visit[nx][ny] == false)
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
int count()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] && visit[i][j] == false)
			{
				cnt++;
				visit[i][j] = true;
				q.push(make_pair(i, j));
				bfs();
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			visit[i][j] = false;
	}
	return cnt;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			arr_copy[i][j] = arr[i][j];
		}
	}
	while (1)
	{
		if (check() > 0)
		{
			melt();
			ans++;
			if (count() >= 2)
				break;
		}
		else
		{
			ans = 0;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}