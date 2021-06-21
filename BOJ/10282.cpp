#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
using namespace std;
priority_queue<pair<int,int>, vector <pair<int,int>>, greater<pair<int, int>>> pq;
int n, d, c ,ans1, ans2;
vector <pair <int, int >> arr[10001];
int dist[10001];
#define INF 2100000000
bool visit[10001];
queue <int> q;
void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	int d, idx, cnt, next,w;
	dist[start] = 0;
	while (!pq.empty())
	{
		d = pq.top().first;
		idx = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[idx].size(); i++)
		{
			next = arr[idx][i].first;
			w = arr[idx][i].second;
			if (dist[next] > dist[idx] + w)
			{
				dist[next] = dist[idx] + w;
				//cout << dist[next] << " " << next << endl;
				pq.push(make_pair(dist[next],next));
			}
		}
	}
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		idx = q.front();
		q.pop();
		for (int i = 0; i < arr[idx].size(); i++)
		{
			next = arr[idx][i].first;
			if (!visit[next])
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
	
	return;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	int a, b, s;
	for (int i = 0; i < test; i++)
	{
		ans1 = ans2 = 0;
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++)
		{
			dist[i] = INF;
			visit[i] = false;
		}
		for (int j = 0; j < d; j++)
		{
			cin >> a >> b >> s;
			arr[b].push_back(make_pair(a, s));
		}
		dijkstra(c);
		for (int i = 1; i <= n; i++)
		{
			if(dist[i] != INF)
				ans2 = max(ans2, dist[i]);
			if (visit[i])
				ans1++;
			arr[i].clear();
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}