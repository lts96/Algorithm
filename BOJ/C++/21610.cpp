#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n, m;
int arr[51][51];
bool isExist[51][51];
vector <pair <int, int>> cloud;
int cmd[101][2];
int dx[8] = {0,-1,-1,-1,0, 1, 1, 1};
int dy[8] = {-1,-1,0, 1, 1, 1, 0, -1};
int ans;
void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return;
}
void moving(int d, int s)
{
	int nx, ny,x,y;
	int speed = s % n;
	for (int i = 0; i < cloud.size(); i++)
	{
		x = cloud[i].first;
		y = cloud[i].second;
		nx = cloud[i].first + (dx[d] * speed);
		ny = cloud[i].second + (dy[d] * speed);
		if (nx > n)
			nx -= n;
		else if (nx < 1)
			nx += n;
		if (ny > n)
			ny -= n;
		else if (ny < 1)
			ny += n;
		cloud[i].first = nx;
		cloud[i].second = ny;
	}
	return;
}
void rain()
{
	int x, y;
	for(int i=0; i<=50; i++)
	{
		for (int j = 0; j <= 50; j++)
			isExist[i][j] = false;
	}
	for (int i = 0; i < cloud.size(); i++)
	{
		x = cloud[i].first;
		y = cloud[i].second;
		arr[x][y]++;
		isExist[x][y] = true;
	}
	cloud.clear();
	return;
}
void copyWater()
{
	int x, y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (isExist[i][j])
			{
				for (int k = 1; k < 8; k += 2)
				{
					x = i + dx[k];
					y = j + dy[k];
					if (x >= 1 && x <= n && y >= 1 && y <= n)
						if(arr[x][y] > 0)
							arr[i][j]++;
				}
			}
		}
	}
	return;
}
void makeCloud()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] >= 2 && isExist[i][j] == false)
			{
				arr[i][j] -= 2;
				cloud.push_back(make_pair(i, j));
			}
		}
	}
	return;
}
void counting()
{
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			ans += arr[i][j];
	}
	return;
}
void run()
{
	for (int i = 0; i < m; i++)
	{
		moving(cmd[i][0]-1, cmd[i][1]);
		//print();
		rain();
		//print();
		copyWater();
		//print();
		makeCloud();
		//print();
	}
	counting();
	return;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < m; i++)
		cin >> cmd[i][0] >> cmd[i][1];
	cloud.push_back(make_pair(n,1));
	cloud.push_back(make_pair(n, 2));
	cloud.push_back(make_pair(n - 1, 1));
	cloud.push_back(make_pair(n - 1, 2));
	run();
	cout << ans << "\n";
	return 0;
}