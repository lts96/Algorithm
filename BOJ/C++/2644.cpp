#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
int n, ans = -1;
int arr[101][101];
bool visit[101];
int s, d;
queue <pair <int, int>> q;
// 전형적인 bfs 문제 
void bfs()
{
	int x, cnt;
	while (!q.empty())
	{
		x = q.front().first;
		cnt = q.front().second;
		if (x == d)
		{
			ans = cnt;
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			if (arr[x][i] && !visit[i])
			{
				visit[i] = true;
				q.push(make_pair(i, cnt + 1));
			}
		}
		q.pop();
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	int a, b, m;
	cin >> s >> d;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	q.push(make_pair(s, 0));
	visit[s] = true;
	bfs();
	cout << ans << endl;
	return 0;
}
