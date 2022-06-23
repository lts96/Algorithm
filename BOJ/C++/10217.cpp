#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int n, m, k, ans;


// 2차원 배열을 사용하는 다익스트라 응용 문제 
// dist[도시 번호][비용]
// 해당 도시까지 ~ 비용이 들었을때 걸리는 최소 시간을 갱신해준다
int dist[101][10001];
vector <pair <int, pair <int, int>>> arr[101];

#define INF 210000000
void clear()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 10000; j++)
			dist[i][j] = INF;
		arr[i].clear();
	}
	return;
}
int dijkstra(int s, int d)
{
	dist[s][0] = 0;
	// 걸린 시간, 현재 노드 번호, 걸린 비용 
	priority_queue<pair <int, pair <int, int>>> q;
	q.push({ 0, {1, 0} });

	int x, time, cost, next, c, t;
	while (!q.empty())
	{
		time = q.top().first * -1;
		x = q.top().second.first;
		cost = q.top().second.second;
		q.pop();
		if (time > dist[x][cost])
			continue;
		for (int i = 0; i < arr[x].size(); i++)
		{
			next = arr[x][i].first;
			c = arr[x][i].second.first;
			t = arr[x][i].second.second;

			// 지원 비용 초과시 불가능 
			if (cost + c > m)
				continue;
			// 시간이 더 적게 걸리는 경우만 다음으로 넘어감 
			// 내가 가려는 곳이 어차피 똑같은 값을 가진다면 방문할 필요가 없다.
			// = 없으면 메모리 초과
			if (time + t >= dist[next][cost + c])
				continue;
			dist[next][cost + c] = time + t;
			q.push({ (time + t) * -1, {next, cost + c} });
		}
	}
	int ret = INF;
	for (int i = 0; i <= 10000; i++)
		ret = min(ret, dist[d][i]);
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	int u, v, c, d;
	for (int t = 1; t <= test; t++)
	{
		clear();
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> u >> v >> c >> d;
			arr[u].push_back({ v, {c, d} });
		}
		ans = dijkstra(1, n);
		if (ans == INF)
			cout << "Poor KCM" << "\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
