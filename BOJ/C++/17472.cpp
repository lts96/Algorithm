#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n,m, ans;
int arr[11][11];
bool visit[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cycle[7];
int num;
vector <pair  <int , pair <int, int> >> v;   // 앞은 연결된 노드 번호  뒤는 간선 가중치 
queue <pair <int, int>>q;

int find(int i)
{
	if (i == cycle[i])
		return i;
	return cycle[i] = find(cycle[i]);
}
void union_set(int a, int b)
{
	int root1 = find(a), root2 = find(b);
	if (root1 == root2)
		return;
	cycle[root2] = root1;
	return;
}
void numbering(int c)
{
	int x , y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		visit[x][y] = true;
		arr[x][y] = c;
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] < n) && (y + dy[i] >= 0 && y + dy[i] < m))
			{
				if (visit[x + dx[i]][y + dy[i]] == false && arr[x + dx[i]][y + dy[i]] == -1)
					q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
		q.pop();
	}
	num++;
	return;
}
void run()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] < 0)
			{
				q.push(make_pair(i, j));
				cnt++;
				numbering(cnt);
			}
		}
	}
	return;
}
void findEdge1()   // 가로로 지나는 다리 찾아서 간선으로 만들기 
{
	int s, d;
	bool flag;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] > 0)
			{
				flag = false;
				s = j;
				int cnt = 0;
				for (int k = j + 1; k < m; k++)
				{
					if (arr[i][k] == 0)
						cnt++;
					else
					{
						d = k;
						flag = true;
						break;
					}
				}
				if (cnt >= 2 && flag)
				{
					if (arr[i][s] != arr[i][d])
						v.push_back(make_pair(cnt, make_pair(arr[i][s], arr[i][d])));
				}
			}
		}
	}
	return;
}
void findEdge2()   // 세로로 지나는 다리 찾아서 간선으로 만들기 
{
	int s, d;
	bool flag;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] > 0)
			{
				flag = false;
				s = i;
				int cnt = 0;
				for (int k = i + 1; k < n; k++)
				{
					if (arr[k][j] == 0)
						cnt++;
					else
					{
						d = k;
						flag = true;
						break;
					}
				}
				if (cnt >= 2 && flag)
				{
					if(arr[s][j]!= arr[d][j])
						v.push_back(make_pair(cnt, make_pair(arr[s][j], arr[d][j])));
				}
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> t;
			if (t == 1)
				t *= -1;
			arr[i][j] = t;
		}
	}
	for (int i = 0; i <= 6; i++)
		cycle[i] = i;
	run();
	findEdge1();
	findEdge2();
	sort(v.begin(), v.end());
	int w, x, y;
	for (int i = 0; i < v.size(); i++)
	{
		w = v[i].first;
		x = v[i].second.first;
		y = v[i].second.second;
		if (find(x) == find(y))
			continue;
		else
		{
			union_set(x, y);
			ans += w;
		}
	}

	// 모든 점이 연결되지 않는 경우 -1 출력 
	for (int i = 1; i <= num; i++)  // path compression으로 루트 갱신하기 위해서
		find(i);
	int temp = cycle[1];
	for (int i = 1; i <= num; i++)
	{
		if (temp != cycle[i])
		{
			cout << -1 << "\n";
			return 0;
		}
		//cout << cycle[i] << endl;
	}
	cout << ans << "\n";
	return 0;
	/* 반례 
	10 6
	0 0 0 1 0 0
	0 0 0 1 0 0
	0 1 0 0 0 1
	0 0 0 0 0 0
	1 1 0 1 1 0
	1 0 0 0 1 0
	1 1 0 0 1 0
	0 0 0 0 1 1
	0 0 0 0 0 0
	0 1 0 0 0 0
	*/
}


