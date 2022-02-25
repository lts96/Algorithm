#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define MAX 1001
#define INF 2100000000
vector <pair <int , int>> arr[MAX];
int ans[MAX][MAX];
int parent[MAX];
int n, k;
// 간선 가중치, depth, 다음에 갈 노드 저장
/*
간선의 합이 최소 , 1번이 슈퍼컴퓨터고 모든 곳으로 갈 수 있어야함
1에서 모든 정점으로 다익스트라 돌릴때 선택되는 간선들만 체크하면 답?
1에서 다익스트라 돌리면서 노드 값이 최소로 갱신될때 자신의 부모를 저장해서 출력하면 답
어쩌다보니 맞았는데 왜 맞는건지 백프로 확신을 못하겠음 -> 다른 설명좀 읽어보자
*/
void dijkstra(int s)
{
	priority_queue <pair <pair <int, int>, pair <int, int> >> q;
	int dist[MAX];
	int x, nx, d, w, prev;
	for (int i = 1; i <= n; i++)
	{
		if (i == s)
			continue;
		dist[i] = INF;
	}
	dist[s] = 0;
	q.push({ {0, 0}, {0, s} });
	while (!q.empty())
	{
		w = q.top().first.first * -1;
		prev = q.top().first.second;
		d = q.top().second.first;
		x = q.top().second.second;
		q.pop();
		if (dist[x] < w)
			continue;
		for (int i = 0; i < arr[x].size(); i++)
		{
			nx = arr[x][i].first;
			if (dist[nx] > dist[x] + arr[x][i].second)
			{
				dist[nx] = dist[x] + arr[x][i].second;
				parent[nx] = x;
				q.push({ {-1 * dist[nx] , x },{d + 1, nx} });
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int a, b, c, cnt = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++)
	{
		if (parent[i])
			cnt++;
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (parent[i])
			cout << i << " " << parent[i] << "\n";
	}
	return 0;
}
