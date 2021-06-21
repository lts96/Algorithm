#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <utility>
using namespace std; 
int m, n, r, c , d;
int **arr;
int ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
queue<pair <int, int>>q;
void bfs()
{
	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		//cout << "x : " << x << " y : " << y  << " d : " << d << endl;
		arr[x][y] = 2; // 청소함 
		if (d == 0)  // 현재 방향 북 
		{
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
				{
					if (arr[x + dx[i]][y + dy[i]] != 0)
						count++;
				}
			}
			if (count == 4)
			{
				if (x + 1 <= n - 1) // c의 경우 
				{
					if (arr[x + 1][y] != 1)
					{
						q.pop();
						q.push(make_pair(x + 1, y));
						continue;
					}
					else  // d의 경우 
					{
						return;
					}
				}
			}

			if (y - 1 >= 0) 
			{
				if (arr[x][y - 1] == 0) // a의 경우
				{
					d = 3; 
					q.pop();
					q.push(make_pair(x, y - 1));
					ans++;
					continue;
				}
				else // b의 경우 
				{
					d = 3;
					q.pop();
					q.push(make_pair(x, y));
					continue;
				}
			}
		}
		else if (d == 1)
		{
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
				{
					if (arr[x + dx[i]][y + dy[i]] != 0)
						count++;
				}
			}
			if (count == 4)
			{
				if (y - 1 >= 0)
				{
					if (arr[x][y - 1] != 1)
					{
						q.pop();
						q.push(make_pair(x, y - 1));
						continue;
					}
					else  // d의 경우 
					{
						return;
					}
				}
			}
			if (x - 1 >= 0)
			{
				if (arr[x - 1][y] == 0) // a의 경우
				{
					d = 0;
					q.pop();
					q.push(make_pair(x - 1, y));
					ans++;
					continue;
				}
				else // b의 경우 
				{
					d = 0;
					q.pop();
					q.push(make_pair(x, y));
					continue;
				}
			}
			
		}
		else if (d == 2)
		{
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
				{
					if (arr[x + dx[i]][y + dy[i]] != 0)
						count++;
				}
			}
			if (count == 4)
			{
				if (x - 1 >= 0)
				{
					if (arr[x - 1][y] != 1)
					{
						q.pop();
						q.push(make_pair(x - 1, y));
						continue;
					}
					else  // d의 경우 
					{
						return;
					}
				}
			}
			if (y + 1 <= m-1)
			{
				if (arr[x][y + 1] == 0) // a의 경우
				{
					d = 1;
					q.pop();
					q.push(make_pair(x, y + 1));
					ans++;
					continue;
				}
				else // b의 경우 
				{
					d = 1;
					q.pop();
					q.push(make_pair(x, y));
					continue;
				}
			}

		}
		else if (d == 3)
		{
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
				{
					if (arr[x + dx[i]][y + dy[i]] != 0)
						count++;
				}
			}
			if (count == 4)
			{
				if (y + 1 <= m - 1)
				{
					if (arr[x][y + 1] != 1)
					{
						q.pop();
						q.push(make_pair(x, y + 1));
						continue;
					}
					else  // d의 경우 
					{
						return;
					}
				}
			}
			if (x+1 <=n-1)
			{
				if (arr[x + 1][y] == 0) // a의 경우
				{
					d = 2;
					q.pop();
					q.push(make_pair(x + 1, y));
					ans++;
					continue;
				}
				else // b의 경우 
				{
					d = 2;
					q.pop();
					q.push(make_pair(x, y));
					continue;
				}
			}
			
		}
		q.pop();
	}
}

int main(void)
{
	cin >> n >> m; 
	cin >> r >> c >> d;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	q.push(make_pair(r,c));
	bfs();
	cout << ans + 1 << endl;
	//system("pause");
	return 0;
}
