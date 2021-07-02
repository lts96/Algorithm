#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 2100000000
using namespace std;
int n, m ,t , s , g , h;
priority_queue<pair <int, int>> q;
vector<pair <int, int>> v[2001];
vector<pair <int, int>> ans;
int dist[2001];
void clear(int s);
int dijkstra(int src, int dest)
{
	int index, d, next , w;
	clear(src);
	while (!q.empty())
	{
		index = q.top().first;
		d = q.top().second;
		q.pop();
		if (dist[index] < d) // 이미 방문한 곳이면 dist != INF 이므로 넘어감
			continue;
		for (int i = 0; i < v[index].size(); i++)
		{
			next = v[index][i].first;
			w = v[index][i].second;
			if (dist[next] > dist[index] + w)  // 갱신할 필요가 있을때
			{
				dist[next] = dist[index] + w;
				q.push(make_pair(next, dist[next]));
			}
		}
	}
	return dist[dest];
}
void clear(int s)
{
	for (int i = 0; i < 2001; i++)
	{
		if (i != s)
			dist[i] = INF;
		else
		{
			dist[i] = 0;
			q.push(make_pair(i, dist[i]));
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	int a, b,c, d , road = 0;
	for (int i = 0; i < test; i++)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b >> d;
			v[a].push_back(make_pair(b, d));
			if ((a == g && b == h)|| (a== h && b == g))
				road = d;
			v[b].push_back(make_pair(a, d));
		}
		int temp, d1, d2, min_ans = INF , d3;
		for (int j = 0; j < t; j++)
		{
			cin >> c;
			d3 = dijkstra(s, c);  // 원래 s 부터 목적지 후보까지 거리
			d1 = dijkstra(s, g);
			d2 = dijkstra(s, h);
			if (c == g)
				temp = d2 + road;
			else if (c == h)
				temp = d1 + road;
			else if (c != g && c != h)
			{
				int d3 = d1 + road + dijkstra(h, c);
				int d4 = d2 + road + dijkstra(g, c);
				temp = min(d3, d4);
			}
			// g - h를 거친 경로가 s 부터 t 까지 경로보다 작아야 한다 -> 문제에서 항상 최단으로 간다고 함
			if(d3 >= temp)
				ans.push_back(make_pair(c, temp));
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			min_ans = min(min_ans, ans[i].second);
		//cout << "min : " << min_ans << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " ";
		// 배열 초기화 
		while (!ans.empty())
			ans.pop_back();
		for (int i = 0; i < 2001; i++)
		{
			while (!v[i].empty())
				v[i].pop_back();
		}
		cout << "\n";
	}
	return 0;
}