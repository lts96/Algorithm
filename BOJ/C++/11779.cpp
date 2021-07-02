#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define INF 99999999999
using namespace std;
typedef pair<pair<long long, long long>, long long> edge;
// 최소 힙 사용 
priority_queue < edge, vector < edge > , greater<edge>>q; 
vector <pair<long long, long long >> v[1001];
long long dist[1001];
long long p[1001];
int n, m;
vector <int> ans;
long long dijkstra(int src, int dest)
{
	for (int i = 0; i < 1001; i++)
		dist[i] = INF;
	dist[src] = 0;
	p[src] = -1;
	q.push(make_pair(make_pair(0, src), -1));
	long long w , next;
	while (!q.empty())
	{
		long long d = q.top().first.first;
		long long index = q.top().first.second;
		long long prev = q.top().second;
		q.pop();
		if (dist[index] < d)
			continue;
		for (int i = 0; i < v[index].size(); i++)
		{
			next = v[index][i].first;
			w = v[index][i].second;
			if (dist[next] > dist[index] + w)
			{
				dist[next] = dist[index] + w;
                p[next] = index;   // 반드시 여기서 이전 위치를 저장해줘야 한다
				q.push(make_pair(make_pair(w, next), index));
			}
		}
	}
	return dist[dest];
}
void trace(int d)
{
	if (d == -1)
		return;
	ans.push_back(d);
	trace(p[d]);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> m;
	int a, b, c , s , d;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	cin >> s >> d;
	long long cost = dijkstra(s, d);
	trace(d);
	cout << cost << endl;
	cout << ans.size() << endl;
	for (int i = ans.size()-1; i >= 0; i--)
		cout << ans[i] << " ";
	return 0;
}