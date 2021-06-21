#include <iostream>
#include <queue>
#include <utility>
#pragma warning (disable : 4996)
  
using namespace std;
int n, m;
int ans = 100000000;
int found;
int arr[1001][1001];
bool visit[1001][1001][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue < pair<pair<int, int> , pair <int , int >>> q;
void bfs()   // 0,0 부터 
{
	int x, y; 
	int crash;
	int count; 
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		crash = q.front().second.first;
		visit[x][y][crash] = true;
		count = q.front().second.second; 
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
			{
				if (arr[x + dx[i]][y + dy[i]] == -1 && crash == 0)
				{ 
					visit[x + dx[i]][y + dy[i]][crash+1] = true;
					//printf("x = %d , y= %d , crash = %d , count = %d \n", x, y, crash, count + 1);
					q.push(make_pair(make_pair(x + dx[i], y + dy[i]), make_pair(crash+1,count+1)));
				}
				if (arr[x + dx[i]][y + dy[i]] == 0 && visit[x + dx[i]][y + dy[i]][crash] == false)
				{
					visit[x + dx[i]][y + dy[i]][crash] = true;
					//printf("x = %d , y= %d , crash = %d , count = %d \n", x, y, crash, count + 1);
					q.push(make_pair(make_pair(x + dx[i], y + dy[i]), make_pair( crash , count+1)));
				}

			}
		}
		if (x == n - 1 && y == m - 1)
		{
			if (count <= ans)
				ans = count;
			found++;
		}
		q.pop();
	}
	
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
			arr[i][j] = arr[i][j] * -1;
		}
	}
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	arr[0][0] = 1;
	bfs();
	if (found == 0)
		ans = -1;
	cout << ans << endl;


	//system("pause");
	return 0;
}