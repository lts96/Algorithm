#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int tx, ty, n, cx , cy , ans;
queue <pair <pair <int, int>, int >> q;
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
void bfs()
{
	vector <vector <bool>> visit(n, vector <bool>(n, false));
	visit[cx][cy] = true;
	q.push(make_pair(make_pair(cx, cy), 0));
	int x, y, c , nx, ny;
	if (cx == tx && cy == ty)
	{ 
		ans = 0;
		return;
	}
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		c = q.front().second;
		//cout << x << " " << y << endl;
		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if ((nx >= 0 && nx <= n - 1) && (ny >= 0 && ny <= n - 1))
			{
				if (nx == tx && ny == ty)
				{
					ans = min(ans ,c+1);
					break;
				}
				if (visit[nx][ny] == false)
				{
					visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), c+1));
				}
			}
		}
		q.pop();
	}
	while (!q.empty())
		q.pop();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ans = 99999990;
		cin >> n;
		cin >> cx >> cy;
		cin >> tx >> ty;
		bfs();
		cout << ans << "\n";
	}
	return 0;
}
