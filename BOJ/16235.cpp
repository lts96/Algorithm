#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int arr[11][11];
int soil[11][11];
int a[11][11];
int cnt[11][11];
int n, m, k;
queue <int> tree[11][11];
queue <int> new_tree[11][11];
void spring()
{
	int age,size1,size2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			size1 = new_tree[i][j].size();
			size2 = tree[i][j].size();
			for (int k = 0; k < size1; k++)
			{
				age = new_tree[i][j].front();
				if (age <= arr[i][j])
				{
					arr[i][j] -= age;
					age++;
					tree[i][j].push(age);
				}
				new_tree[i][j].pop();
			}
			for(int k =0; k < size2; k++)  // 봄
			{
				age = tree[i][j].front();
				if (age <= arr[i][j])
				{
					arr[i][j] -= age;
					age++;
					tree[i][j].push(age);
				}
				else  // 여름
					soil[i][j] += (age / 2);
				tree[i][j].pop();
			}
		}
	}
	return;
}

void autumn()
{
	int x, y, size, age;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			size = tree[i][j].size();
			for (int k = 0; k < size; k++)
			{
				age = tree[i][j].front();
				tree[i][j].pop();
				if (age % 5 == 0)
					cnt[i][j]++;
				tree[i][j].push(age);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] += a[i][j];
			arr[i][j] += soil[i][j];
			soil[i][j] = 0;
			for (int k = 0; k < cnt[i][j]; k++)
			{
				for (int h = 0; h < 8; h++)
				{
					x = i + dx[h];
					y = j + dy[h];
					if (x >= 1 && x <= n && y >= 1 && y <= n)
						new_tree[x][y].push(1);
				}
			}
			cnt[i][j] = 0;
		}
	}
	return;
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	int x, y, z;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			arr[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		tree[x][y].push(z);
	}
	for (int i = 0; i < k; i++)
	{
		spring();
		autumn();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += tree[i][j].size();
			ans += new_tree[i][j].size();
		}
	}
	cout << ans << "\n";
	return 0;
}