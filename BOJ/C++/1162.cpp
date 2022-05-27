#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
ll n, m , k, ans = 9223372036854775800;
ll dist[10001][21];
vector <pair <ll, ll>> arr[10001];
#define INF 9223372036854775800

// 다익스트라 응용 문제 
// 다익스트라 간선 중 k개가 제거 가능 
// 2차원 테이블 사용해서 현재 노드까지 몇개 간선을 제거했는지 찾아보면서 진행 

void dijkstra(int s, int d)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
			dist[i][j] = INF;
	}
	dist[s][0] = 0;
	priority_queue <pair <ll , pair <ll, ll>>> q;
	q.push({ 0, {s, 0} });
	ll sum, x, y, nx, ny, w;
	while (!q.empty())
	{
		sum = q.top().first * -1;
		x = q.top().second.first;
		y = q.top().second.second;
		//cout << x << " " << y << " " << sum << endl;
		q.pop();
		if (dist[x][y] < sum)
			continue;
		for (int i = 0; i < arr[x].size(); i++)
		{
			nx = arr[x][i].first;
			w = arr[x][i].second;

			// 도로 포장이 가능한 경우 
			if (y < k)
			{
				if (dist[nx][y + 1] > dist[x][y])
				{
					dist[nx][y + 1] = dist[x][y];
					q.push({ dist[nx][y + 1] * -1 , {nx, y + 1} });
				}
			}
			// 포장을 하지 않는 경우 
			if (dist[nx][y] > dist[x][y] + w)
			{
				dist[nx][y] = dist[x][y] + w;
				q.push({ dist[nx][y] * -1 , {nx, y} });
			}
		}
	}
	for (int i = 0; i <= k; i++)
		ans = min(ans, dist[n][i]);
	return;
}
int main(void)
{
	cin >> n >> m >> k;
	ll a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	dijkstra(1, n);
	cout << ans << endl;
	return 0;
}
