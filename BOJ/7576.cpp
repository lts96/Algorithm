#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int ans;
int arr[1003][1003];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue <pair<int, int> > q;
void bfs()
{
	int x, y;
	int temp;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= m - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
			{
				if (arr[x + dx[i]][y + dy[i]] == 0)
				{
					arr[x + dx[i]][y + dy[i]] = arr[x][y] + 1;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
		}
		q.pop();
	}
	ans = arr[x][y];
	ans--;
	return;
}
void find()
{
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
				cnt++;
			}
		}
	}
	if(cnt > 0)
		bfs();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> arr[i][j];
		}
	}
	find();

	for (int i = 0; i < m; i++) // 만약 다 끝나고 안익은게 있는지 확인  
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				ans = -1;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}