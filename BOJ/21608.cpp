#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n, ans;
int seat[420][4];
int arr[21][21];
int sequence[420];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int cal_score()
{
	int x, y, idx , cnt, result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			idx = arr[i][j];
			cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				x = i + dx[k];
				y = j + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < n)
				{
					for (int h = 0; h < 4; h++)
					{
						if (seat[idx][h] == arr[x][y])
							cnt++;
					}
				}
			}
			if (cnt == 0)
				continue;
			else if (cnt == 1)
				result += 1;
			else if (cnt == 2)
				result += 10;
			else if (cnt == 3)
				result += 100;
			else if (cnt == 4)
				result += 1000;
		}
	}
	return result;
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
void setting(int num)
{
	// 조건 1
	int x, y, idx, cnt, max_cnt = 0 , rx , ry;
	int arr1[21][21], arr2[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr1[i][j] = arr2[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt = 0;
			if (arr[i][j])
				continue;
			for (int k = 0; k < 4; k++)
			{
				x = i + dx[k];
				y = j + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < n)
				{
					for (int h = 0; h < 4; h++)
					{
						if (seat[num][h] == arr[x][y])
							cnt++;
					}
				}
			}
			arr1[i][j] = cnt;
			max_cnt = max(cnt, max_cnt);
		}
	}
	vector <pair <int, int>> v;
	vector <pair <int, pair <int, int>>> v2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i][j] == max_cnt && arr[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}
	if (v.size() == 1)
	{
		rx = v[0].first;
		ry = v[0].second;
		arr[rx][ry] = num;
		v.clear();
		return;
	}
	else if (v.size() > 1)
	{
		max_cnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				x = v[i].first + dx[k];
				y = v[i].second + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < n)
				{
					if (arr[x][y] == 0)
						cnt++;
				}
			}
			v2.push_back(make_pair(cnt * -1, make_pair(v[i].first, v[i].second)));
		}
		sort(v2.begin(), v2.end());
		rx = v2[0].second.first;
		ry = v2[0].second.second;
		arr[rx][ry] = num;
		if (!v.empty())
			v.clear();
		if (!v2.empty())
			v2.clear();
	}
	return;
}
int main(void)
{
	cin >> n;
	int idx;
	for (int i = 0; i < n * n; i++)
	{
		cin >> idx;
		sequence[i] = idx;
		cin >> seat[idx][0] >> seat[idx][1] >> seat[idx][2] >> seat[idx][3];
	}
	for (int i = 0; i < n * n; i++)
		setting(sequence[i]);
	//print();
	ans = cal_score();
	cout << ans << "\n";
	return 0;
}