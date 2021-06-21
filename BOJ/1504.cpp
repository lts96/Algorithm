#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define INF 2147483600
using namespace std;
class vertax {
public :
	int dist;  //여기까지 오는데 최소 거리?
	int index; // 해당 꼭짓점의 index 번호
	int check;
	vertax(int i, int d , int c)
	{
		this->dist = d;
		this->index = i;
		this->check = c;
	}
};
int n, e , v1 ,v2;
unsigned long long ans;
int dist[801];
priority_queue<vertax> pq;
vector <pair <int, int>> edge[801];
bool operator < (const vertax& a, const vertax& b)
{
	return a.dist > b.dist;
}
int dijkstra(int src, int dest)
{
	int d, index , next , weight;
	for (int i = 1; i <= n; i++)
	{
		if (i == src)
		{
			dist[i] = 0;
			pq.push(vertax(i, 0, 0));
		}
		else
			dist[i] = INF;
	}
	while (!pq.empty())
	{
		d = pq.top().dist;
		index = pq.top().index;
		pq.pop();
		if (dist[index] < d)
			continue;
		for (int i = 0; i < edge[index].size(); i++)
		{
			next = edge[index][i].first;
			weight = edge[index][i].second;
			if (dist[next] > dist[index] + weight)
			{
				dist[next] = dist[index] + weight;
				pq.push(vertax(next, dist[next] , 0));
			}
		}
	}
	return dist[dest];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	int a, b, c;
	
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));  // 양방향이므로 2번 기록 
	}
	cin >> v1 >> v2;
	unsigned long long d1 = 0, d2 = 0;   // 2가지 루트가 나옴 , 그 중 더 작은거 찾기   
	// 1 -> v1 -> v2 -> n 
	d1 += dijkstra(1, v1);
	d1 += dijkstra(v1, v2);
	d1 += dijkstra(v2, n);

	// 1-> v2 -> v1 -> n
	d2 += dijkstra(1, v2);
	d2 += dijkstra(v2, v1);
	d2 += dijkstra(v1, n);

	ans = min(d1, d2);
	if (ans >= INF)   // ans 가 inf와 같은 경우를 생략하니 틀림
		cout << -1 << endl;
	else 
		cout << ans << endl;
	return 0;
}