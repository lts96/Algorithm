#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
using namespace std;
#define MAX 2147483647
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 예전 벽부수고 넘어가기랑 비슷
char arr[51][51];
// 좌표 (x,y)에 도달했을때 열쇠조합에 따라 다르게 방문처리해야한다
// 6개 키를 비트마스킹 사용시 최대 127까지 가능
bool visit[51][51][128];
int n, m, ans = MAX;
// 좌표 2개와 거리, 열쇠 조합
queue < pair <pair <int, int>, pair <int, int>>> q;
void bfs()
{
	int x, y, nx, ny, d, key, idx, nkey;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		d = q.front().second.first;
		key = q.front().second.second;
		//cout << x << " " << y << " " << d << " " << key << endl;
		q.pop();
		if (arr[x][y] == '1')
		{
			ans = min(ans, d);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == '#')
				continue;
			if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f')
			{
				idx = arr[nx][ny] - 'a';
				// 다른 노드 key가 같이 변경되지 않도록 별도의 변수 사용
				nkey = key | (1 << idx);
				if (!visit[nx][ny][nkey])
				{
					visit[nx][ny][nkey] = true;
					q.push({ {nx, ny}, {d + 1, nkey} });
				}
			}
			else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F')
			{
				idx = arr[nx][ny] - 'A';
				if ((key & (1 << idx)) && !visit[nx][ny][key])
				{
					visit[nx][ny][key] = true;
					q.push({ {nx, ny}, {d + 1, key} });
				}
			}
			// . 또는 1 일때
			else 
			{
				if (!visit[nx][ny][key])
				{
					visit[nx][ny][key] = true;
					q.push({ {nx, ny}, {d + 1, key} });
				}
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			arr[i][j] = s[j];
			if (arr[i][j] == '0')
			{
				visit[i][j][0] = true;
				arr[i][j] = '.';
				q.push({ {i,j}, {0,0} });
			}
		}
	}
	bfs();
	if (ans == MAX)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}
