#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int f, s, g, u, d;
#define MAX 1000000
int arr[MAX + 1];
bool visit[MAX + 1];
int ans = 210000000;
queue<pair<int, int >> q;
void bfs(int src, int dest)
{
	visit[src] = true;
	q.push(make_pair(src, 0));
	if (src == dest)
	{
		ans = 0;
		return;
	}
	int x, next, cnt;
	while (!q.empty())
	{
		x = q.front().first;
		cnt = q.front().second;
		next = x + u;
		if ((next >= 1 && next <= f) && !visit[next])
		{
			if (next == dest)
			{
				ans = min(ans, cnt + 1);
				return;
			}
			visit[next] = true;
			q.push(make_pair(next, cnt + 1));
		}
		next = x - d;
		if ((next >= 1 && next <= f) && !visit[next])
		{
			if (next == dest)
			{
				ans = min(ans, cnt + 1);
				return;
			}
			visit[next] = true;
			q.push(make_pair(next, cnt + 1));
		}
		q.pop();
	}
	return;
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	bfs(s, g);
	if (ans == 210000000)
		cout << "use the stairs\n";
	else
		cout << ans << "\n";
	return 0;
}