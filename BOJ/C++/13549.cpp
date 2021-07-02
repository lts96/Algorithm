#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n, k, ans;
int arr[100001];
int dist[100001];
#define INF 210000000
priority_queue <pair <int, int>> q;
/*
간선의 가중치가 곱하기 = 0 나머지 = 1 이라서 원래는 단순 bfs로 풀 수 없는 문제인데 어쩌다보니 통과된 것
이걸 해결하기 위해선 다익스트라 쓰거나 가중치가 0인 간선을 무조건 큐 맨앞에 넣는 과정이 필요
*/
void dijkstra(int src, int dest)
{
	for (int i = 0; i <= 100000; i++)
		dist[i] = INF;
	dist[src] = 0;
	q.push(make_pair(0, src));
	if (src == dest)
	{
		ans = 0;
		return;
	}
	int idx, d;
	while (!q.empty())
	{
		idx = q.top().second;
		d = -1 * q.top().first;  // 최단 거리
		q.pop();
		
		if (dist[idx] < d)
			continue;
		if (2 * idx <= 100000)
		{
			if (dist[2 * idx] > dist[idx])
			{
				dist[2 * idx] = dist[idx];
				q.push(make_pair(-1 * dist[2 * idx], 2 * idx));
			}
		}
		if (idx + 1 <= 100000)
		{
			if (dist[idx + 1] > dist[idx] + 1)
			{
				dist[idx + 1] = dist[idx] + 1;
				q.push(make_pair(-1 * dist[idx+1], idx + 1));
			}
		}
		if (idx - 1 >= 0)
		{
			if (dist[idx - 1] > dist[idx] + 1)
			{
				dist[idx - 1] = dist[idx] + 1;
				q.push(make_pair(-1 * dist[idx + 1], idx - 1));
			}
		}
	}
	ans = dist[dest];
	return;
}
int main(void)
{
	cin >> n >> k;
	dijkstra(n,k);
	cout << ans << "\n";
	return 0;
}