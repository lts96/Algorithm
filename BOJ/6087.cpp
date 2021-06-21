#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 210000000
int w, h, ans;
int arr[101][101];
int visit[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int sx, sy, ex, ey;
struct node {
	node(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		cnt = c;
		direct = d;
	}
	int x;
	int y;
	int cnt;
	int direct;
};
queue <node> q;
void bfs()
{
	int x, y, c, d, nx, ny;
	visit[sx][sy] = 0; // 이미 방문 
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		c = q.front().cnt;
		d = q.front().direct;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			int temp = c;
			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;
			if (arr[nx][ny] == -1)
				continue;
			if (i != d)
				temp++;
			if (visit[nx][ny] >= temp) 
			//여기가 핵심, 경로가 겹치더라도 내가 더 작으면 지나가야됨
			{
				visit[nx][ny] = temp;
				q.push({ nx, ny, temp, i });
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> w >> h;
	char c;
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> c;
			if (c == 'C'&& cnt == 0)
			{
				arr[i][j] = -2;
				sx = i; 
				sy = j;
				cnt++;
			}
			else if (c == 'C' && cnt == 1)
			{
				arr[i][j] = -2;
				ex = i; 
				ey = j;
			}
			else if (c == '*')
				arr[i][j] = -1;
			visit[i][j] = INF;
		}
	}
	q.push({ sx, sy, -1, -1 });
	bfs();
	ans = visit[ex][ey];
	cout << ans << "\n";
	return 0;
}