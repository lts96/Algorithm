#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
#define INF 210000000
int arr[11][11];
int num[11];
int n,m, ans = INF;
bool selected[11];
vector <int> node[2];
queue <int> q;
/*
구현 잔 실수 많고 게시판에 반례 있음 -> 다른 방식으로 해보자
푼 방법 : 모든 경우의 수 탐색하면서 내가 고른 구역과 아닌 구역 각각 bfs 돌림
bfs 돌려서 내가 선택한만큼 방문이 가능하면 그 값들을 계산해서 정답 갱신, 아니면 pass
*/
int bfs(int flag)
{
	int x, nx;
	int ret = 0, cnt = 0;
	bool visit[2][11];
	bool check[11] = {};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= 10; j++)
			check[j] = visit[i][j] = false;
	}
	int idx;
	// 선택하지 않은 구역은 이미 방문된걸로 처리해야 탐색에 오류가 안생김 
	// 안그러면 도달하지 못하는 곳도 가게됨 
	for (int i = 0; i < node[!flag].size(); i++)
	{
		idx = node[!flag][i];
		visit[flag][idx] = true;
	}
	for (int i = 0; i < node[flag].size(); i++)
		check[node[flag][i]] = true;
	q.push(node[flag][0]);
	while (!q.empty())
	{
		x = q.front();
		visit[flag][x] = true;
		if (check[x])
		{
			check[x] = false;
			ret += num[x];
			cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (arr[x][i] && visit[flag][i] == false)
				q.push(i);
		}
		q.pop();
	}
	if (cnt != node[flag].size())
		return -1;
	return ret;
}
void selectNode(int idx)
{
	int r1 = 0, r2 = 0;
	if (idx == n)
	{
		for (int i = 1; i <= n; i++)
			node[selected[i]].push_back(i);
		// 하나도 없는 경우는 제외
		if (node[0].size() == 0 || node[1].size() == 0)
		{
			node[0].clear();
			node[1].clear();
			return;
		}
		r1 = bfs(0);
		r2 = bfs(1);
		if(r1 != -1 && r2 != -1)
		{
			ans = min(ans, abs(r1 - r2));
		}
		node[0].clear();
		node[1].clear();
		return;
	}
	selected[idx] = true;
	selectNode(idx + 1);
	selected[idx] = false;
	selectNode(idx + 1);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	int k;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> k;
			arr[i][k] = arr[k][i] = 1;
		}
	}
	selectNode(1);
	if (ans != INF)
		cout << ans << endl;
	else
		cout << "-1\n";
	return 0;
}
