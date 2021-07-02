#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n, m , h;
int ans;
int arr[101][101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int dz[] = { -1, 1 };
queue < pair <pair<int, int> , int> > q;
void bfs()
{
	int x, y,z;
	int temp;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		z = q.front().second;
		for (int i = 0; i<4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= m - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
			{
				if (arr[x + dx[i]][y + dy[i]][z] == 0)
				{
					arr[x + dx[i]][y + dy[i]][z] = arr[x][y][z] + 1;
					q.push(make_pair(make_pair(x + dx[i], y + dy[i]),z));
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (z + dz[i] >= 0 && z + dz[i] <= h - 1)
			{
				if (arr[x][y][z + dz[i]] == 0)
				{
					arr[x][y][z + dz[i]] = arr[x][y][z] + 1;
					q.push(make_pair(make_pair(x , y), z+dz[i]));
				}
			}
		}
		q.pop();
	}
	ans = arr[x][y][z];
	ans--;
    return;
}
void find()
{
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			for (int k = 0; k < h; k++)
			{
				if (arr[i][j][k] == 1)
				{
					q.push(make_pair(make_pair(i, j),k));
				}
			}
		}
	}
    if(q.size()>0)
	    bfs();
    return;
}
int main(void)
{
	cin >> m;
	cin >> n;
	cin >> h;
	for (int k = 0; k < h; k++)
	{
		for (int j = 0; j<n; j++)
		{
			for (int i = 0; i<m; i++)
			{
				cin >> arr[i][j][k];
			}
		}
	}
	find();

	for (int i = 0; i<m; i++) // 만약 다 끝나고 안익은게 있는지 확인  
	{
		for (int j = 0; j<n; j++)
		{
			for (int k = 0; k < h; k++)
			{
				if (arr[i][j][k] == 0)
				{
					ans = -1;
					break;
				}
			}
		}
	}
	

	cout << ans << endl;
	//system("pause");
	return 0;
}