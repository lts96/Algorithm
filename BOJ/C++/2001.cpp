#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m, k, ans;
int jewel[101];
vector <pair <int, int>> arr[101];
bool visit[101][20000];

// 비트마스크 + bfs 문제 

// bfs로 가져가야할 정보 = 위치, 보석 개수 , 보석 번호 
void bfs(int s)
{
	queue <pair <pair <int, int>, int>> q;
	visit[s][0] = true;
	q.push({ {1, 0}, 0 });
	int x, nx, cnt, bit, nbit, w;

	while (!q.empty())
	{
		x = q.front().first.first;
		cnt = q.front().first.second;
		bit = q.front().second;
		//cout << "idx : "<<x << " " << cnt << " " << bit << endl;
		q.pop();
		if (x == 1 && cnt != 0)
		{
			ans = max(ans, cnt);
			continue;
		}
		for (int i = 0; i < arr[x].size(); i++)
		{
			nx = arr[x][i].first;
			w = arr[x][i].second;
			// 보석이 있다면
			if (jewel[nx] != -1)
			{
				nbit = bit | (1 << jewel[nx]);
				if (visit[nx][nbit] || cnt > w)
					continue;
				visit[nx][nbit] = true;

				// 이미 주운 보석이라면 개수는 그대로 
				if (bit & (1 << jewel[nx]))
					q.push({ {nx, cnt}, nbit });
				else
					q.push({ {nx, cnt + 1}, nbit });
			}
			// 보석이 없는 경우 or 줍지 않는 경우 
			// 이미 방문했거나 보석이 너무 많으면 패스 
			if (visit[nx][bit] || cnt > w)
				continue;
			visit[nx][bit] = true;
			q.push({ {nx, cnt}, bit });
		}
	}
	return;
}
int main(void)
{
	cin >> n >> m >> k;
	int temp, a, b, c;
	for (int i = 0; i <= 100; i++)
		jewel[i] = -1;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		jewel[temp] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}
	bfs(1);
	cout << ans << endl;
	return 0;
}
