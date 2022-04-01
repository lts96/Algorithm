#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int w, h, ans;
/*
1
5 5
***b*
***A*
***$*
.a***
*****
0
답 : 1
*/
// 비트마스크 + bfs 문제 
// 생각할게 조금 많았고 디버깅도 까다롭 

// 열쇠를 상태값으로 넣었다간 너무 배열이 커짐 
// 어차피 열쇠는 점점 증가하기만 하니까 int로 구분 
int visit[103][103];
char arr[103][103];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void print()
{
	cout << endl;
	for (int i = 0; i <= w + 1; i++)
	{
		for (int j = 0; j <= h + 1; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return;
}
void bfs(int sx, int sy, int sb)
{
	queue <pair <pair <int, int>, int>> q;
	visit[sx][sy] = sb;
	q.push({ {sx, sy}, sb });

	int x, y, nx, ny, key, door;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		key = q.front().second;
		//cout << x << " " << y << " " << key << endl;
		q.pop();
		// 열쇠를 주웠을때 
		if (arr[x][y] >= 'a' && arr[x][y] <= 'z')
		{
			key |= (1 << (arr[x][y] - 'a'));
			
		}
		// 문서를 먹었을때
		if (arr[x][y] == '$')
		{
			ans++;
			arr[x][y] = '.';
		}
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= w + 2 || ny < 0 || ny >= h + 2)
				continue;
			if (arr[nx][ny] == '*')
				continue;
			// 문을 열 수 없을때
			if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z')
			{
				door = 1 << (arr[nx][ny] - 'A');
				if ((door & key) == 0)
					continue;
			}
			// 이미 방문했을때
			if (visit[nx][ny] >= key)
				continue;
			visit[nx][ny] = key;
			q.push({ {nx, ny}, key });
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> w >> h;
		string s;
		int b;
		ans = 0;
    
		// 주어진 지도에 테두리를 한칸 더 쳐서 알아서 찾아들어가게 구현 
    // 이렇게 하면 매우 편함 
		for (int i = 0; i <= 102; i++)
		{
			for (int j = 0; j <= 102; j++)
			{
				arr[i][j] = '.';
				visit[i][j] = -1;
			}
		}
		for (int i = 1; i <= w; i++)
		{
			cin >> s;
			for (int j = 0; j < s.length(); j++)
				arr[i][j + 1] = s[j];
		}
		cin >> s;
		if (s == "0")
			b = 0;
		else
		{
			b = 0;
			int idx;
			for (int i = 0; i < s.length(); i++)
			{
				idx = 1 << (s[i] - 'a');
				b |= idx;
			}
		}
		//print();
		//cout << b << endl;
		bfs(0, 0, b);
		cout << ans << "\n";
	}
	return 0;
}
