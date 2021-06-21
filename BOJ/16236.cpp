#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[21][21];
bool visit[21][21];
int baby = 2, n, fish, ans, cnt;
int px, py;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
bool can_go = true;
queue<pair<pair <int, int >, int>> q;
void bfs()
{
	int x, y, time, t;
	vector <pair<int, int >> v;
	bool flag = false;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		time = q.front().second;
		if (arr[x][y] < baby && arr[x][y] != 0)
		{
			//cout << x << " " << y << " " << arr[x][y]<< endl;
			cnt++;
			if (cnt == baby)
			{
				baby++;
				cnt = 0;
			}
			fish--;
			ans += time;
			sort(v.begin(), v.end());
			px = v[0].first;
			py = v[0].second;
			arr[px][py] = 0;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= n - 1))
			{
				if (!visit[x + dx[i]][y + dy[i]])
				{
					visit[x + dx[i]][y + dy[i]] = true;
					if (arr[x + dx[i]][y + dy[i]] == 0)
						q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time + 1));
					else if (arr[x + dx[i]][y + dy[i]] < baby)
					{
						if (!flag)
						{
							t = time + 1;
							flag = true;
						}
						if (time + 1 == t)
							v.push_back(make_pair(x + dx[i], y + dy[i]));
						q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time + 1));
					}
					else if (arr[x + dx[i]][y + dy[i]] == baby)
						q.push(make_pair(make_pair(x + dx[i], y + dy[i]), time + 1));
				}
			}
		}
		q.pop();
	}
	can_go = false;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				px = i;
				py = j;
				arr[i][j] = 0;
			}
			else if (arr[i][j] >= 1 && arr[i][j] <= 6)
				fish++;
		}
	}
	while (fish > 0)
	{

		//cout <<"before: "<< px << " " << py << " " << ans << " " << baby<< endl;
		q.push(make_pair(make_pair(px, py), 0));
		visit[px][py] = true;
		bfs();
		//cout << "after: " << px << " " << py << " " << ans << " " << baby << endl;
		/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		if (!can_go)
			break;
		while (!q.empty())
			q.pop();
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = false;
				if (arr[i][j] < baby && arr[i][j] != 0)
					temp++;
			}
		}
		if (temp == 0)
			break;
	}
	cout << ans << endl;
	return 0;
}