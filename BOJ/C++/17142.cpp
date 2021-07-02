#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
queue <pair<pair <int, int>, int >> q;
int n, m, ans, cnt;
int arr[51][51] , arr2[51][51];
bool visit[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool activate[11];
vector <int> v2;
vector <pair<int, int >> pos;
bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void bfs()
{
	int x, y, time;
	ans = 0;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		time = q.front().second;
		ans = max(ans, time);
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] < n) && (y + dy[i] >= 0 && y + dy[i] < n))
			{
				if (!visit[x + dx[i]][y + dy[i]] && arr[x + dx[i]][y + dy[i]] == 0)
				{
					visit[x + dx[i]][y + dy[i]] = true;
					arr[x + dx[i]][y + dy[i]] = 2;
					q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time + 1));
				}
				if (!visit[x + dx[i]][y + dy[i]] && arr[x + dx[i]][y + dy[i]] == -1)
				{
					visit[x + dx[i]][y + dy[i]] = true;
					arr[x + dx[i]][y + dy[i]] = 2;
					if(check())
						q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time));
					else 
						q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time + 1));
				}
			}
		}
		q.pop();
	}
	// 남은 공간 있는지 체크
	for (int i = 0; i < n; i++)
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
	v2.push_back(ans);
	return;
}
void select(int index, int c)
{
	if (c == m)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			if (activate[i] == true)
			{
				visit[pos[i].first][pos[i].second] = true;
				arr[pos[i].first][pos[i].second] = 2;
				q.push(make_pair(make_pair(pos[i].first, pos[i].second),0));
			}
		}
		cnt++;
		bfs();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = false;
				arr[i][j] = arr2[i][j];
			}
		}
		return;
	}
	for (int i = index; i < pos.size(); i++)
	{
		activate[i] = true;
		select(i + 1, c + 1);
		activate[i] = false;
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
			if (arr[i][j] == 2)
			{
				pos.push_back(make_pair(i, j));
				arr2[i][j] = arr[i][j] = -1;
			}
		}
	}
	select(0,0);
	int result = 10000000;
	bool flag = false;
	for (int i = 0; i < v2.size(); i++)
	{
		if (v2[i] != -1)
		{
			flag = true;
			result = min(v2[i], result);
		}
		//cout << v2[i] << " ";
	}
	//cout << endl << "cnt : " << cnt << endl;
	if (flag)
		cout << result << "\n";
	else
		cout << "-1\n";
	return 0;
}
