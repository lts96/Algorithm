#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
int n, m, k, ans;
bool selected[11];
int arr[11][11];
vector <pair <int, int>> stair;
vector <pair <int, int>> people;

// 브루트포스 + 구현문제
// 중간에 디버깅하면서 변수 값을 제대로 안바꿔둔 잔 실수가 많았다
// 시간 단축하려면 변수값이 제대로 들어가는지 확인하는 습관을 가질것 
int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
int excape()
{
	int x, y, sx, sy, d;
	int time[2];
	time[0] = 0;
	time[1] = 0;
	vector<pair <int, int>> s[2];
	queue<pair <int, int>> q[2];
	for (int i = 0; i < m; i++)
	{
		x = people[i].first;
		y = people[i].second;
		if (selected[i] == false)
		{
			sx = stair[0].first;
			sy = stair[0].second;
		}
		else
		{
			sx = stair[1].first;
			sy = stair[1].second;
		}
		d = dist(x, y, sx, sy) + 1;
		k = arr[sx][sy];
		s[selected[i]].push_back({ d, k });
	}
	// 선입 선출이므로 도착한 순서로 정렬 
	sort(s[0].begin(), s[0].end());
	sort(s[1].begin(), s[1].end());
	for (int i = 0; i < 2; i++)
	{
		if (s[i].size() <= 3)
			continue;
		for (int j = 0; j < s[i].size() - 3; j++)
			s[i][j + 3].first = max(s[i][j + 3].first, s[i][j].first + s[i][j].second);
	}
	//cout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			time[i] = max(time[i], s[i][j].first + s[i][j].second);
			//cout << time[i] << " ";
		}
		//cout << endl;
	}
	return max(time[0], time[1]);
}
void brute(int idx)
{
	if (idx == m)
	{
		int temp = excape();
		ans = min(ans, temp);
		return;
	}
	selected[idx] = false;
	brute(idx + 1);
	selected[idx] = true;
	brute(idx + 1);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		// m 사람수 
		m = 0;
		ans = 2100000000;
		cin >> n;
		for (int i = 0; i <= 10; i++)
			selected[i] = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] > 1)
					stair.push_back({ i, j });
				else if (arr[i][j] == 1)
				{
					people.push_back({i, j});
					m++;
				}
			}
		}
		brute(0);
		cout << "#" << t << " " << ans << "\n";
		stair.clear();
		people.clear();
	}
	return 0;
}
