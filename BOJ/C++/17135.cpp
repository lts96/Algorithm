#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n, m, d, ans, enemy;
int arr[17][17];
int arr_copy[17][17];
int pos[3][2];
bool selected[17];


void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
void clear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr[i][j] = arr_copy[i][j];
	}
	return;
}
int dist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}
int move_enemy()
{
	int temp[17][17];
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			temp[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				temp[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = temp[i][j];
			if (arr[i][j])
				cnt++;
		}
	}
	return cnt;
}
int kill_enemy()
{
	int enemy_cnt = enemy;
	int min_temp;
	int range = d;
	int d;
	int result = 0;
	vector <pair <int, int >> v;
	vector <pair <int , pair <int, int >>> temp;
	//for (int i = 0; i < 3; i++)
		//cout << "archer : " << pos[i][0] << " " << pos[i][1]<< endl;
	while (enemy_cnt > 0)
	{
		for (int k = 0; k < 3; k++)
		{
			min_temp = 9999999;

			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = 0; j < m; j++)
				{
					if (arr[i][j] != 1)
						continue;
					d = dist(i, j, pos[k][0], pos[k][1]);
					if ((min_temp >= d) && (d <= range))
					{
						min_temp = d;
						// 왼쪽 우선시 하기 위해 거꾸로 넣고 소트
						temp.push_back({ d, {j , i} });
					}
				}
			}
			sort(temp.begin(), temp.end());
			if (temp.size() > 0)
				v.push_back({temp[0].second.second, temp[0].second.first});
			temp.clear();
		}
		// 같은 적을 죽이는 경우 때문에 따로 분리 
		// 궁수가 죽인 적 카운트
		for (int i = 0; i < v.size(); i++)
		{
			if (arr[v[i].first][v[i].second])
			{
				arr[v[i].first][v[i].second] = 0;
				result++;
			}
			//cout << v[i].first << " " << v[i].second << " ";
		}
		//cout << result << endl;
		//print();
		v.clear();
		enemy_cnt = move_enemy();
	}
	clear();
	return result;
}
void select_pos(int idx, int cnt)
{
	int result = 0;
	int k = 0;
	if (idx >= m || cnt == 3)
	{
		if (cnt != 3)
			return;
		for (int i = 0; i < m; i++)
		{
			if (selected[i])
			{
				pos[k][0] = n;
				pos[k][1] = i;
				k++;
			}
		}
		result = kill_enemy();
		ans = max(result, ans);
		return;
	}
	selected[idx] = true;
	select_pos(idx + 1, cnt + 1);
	selected[idx] = false;
	select_pos(idx + 1, cnt);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			arr_copy[i][j] = arr[i][j];
			if(arr[i][j])
				enemy++;
		}
	}
	select_pos(0, 0);
	cout << ans << endl;
	return 0;
}
