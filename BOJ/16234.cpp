#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
int n, l, r , ans;
int arr[51][51];
int un[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
using namespace std;
queue<pair<int, int>> q;
void bfs()
{
	int x, y , diff;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
			{
				diff = abs(arr[x][y] - arr[x + dx[i]][y + dy[i]]);
				if ((diff >= l) && (diff <= r))
				{
					if (un[x + dx[i]][y + dy[i]] == 0)
					{
						un[x + dx[i]][y + dy[i]] = un[x][y];
						q.push(make_pair(x + dx[i], y + dy[i]));
					}
				}
			}
		}
		q.pop();
	}


	return;
}
int find()
{
	int diff;
	int mark = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((i + dx[k] >= 0 && i + dx[k] <= n - 1) && (j + dy[k] >= 0 && j + dy[k] <= n - 1))
				{
					diff = abs(arr[i][j] - arr[i + dx[k]][j + dy[k]]);
					if ((diff >= l) && (diff <= r))
					{
						if (un[i][j] == 0)
						{
							mark++;
							un[i][j] = mark;
							q.push(make_pair(i, j));
							bfs();
						}
					}
				}
			}
		}
	}
	vector <int> sum(mark, 0);
	vector <int> cnt(mark, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < mark; k++)
			{
				if (un[i][j] == k + 1)
				{
					sum[k] += arr[i][j];
					cnt[k]++;
				}
			}
		}
	}
	for (int i = 0; i < mark; i++)
		sum[i] /= cnt[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < mark; k++)
			{
				if (un[i][j] == k + 1)
				{
					un[i][j] = 0;
					arr[i][j] = sum[k];
				}
			}
		}
	}
	/*
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	*/
	return mark;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		int temp = find();
		if (temp != 0)
			ans ++;
		else
			break;
	}
	cout << ans << endl;
	return 0;
}