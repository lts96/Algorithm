#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, ans;
int dx[4] = { 0,1 ,1 };
int dy[4] = { 1,0 , 1 };
queue<pair <pair <int, int>, int>> q;
// 3번째 변수는 이전 파이프 모양  가로 = 1, 대각 = 2 , 세로 = 3
int arr[18][18];
int cnt[18][18];
void bfs()
{
	int x, y , state , nx , ny;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		state = q.front().second;
		if (state == 1)  // 이전 파이프가 가로일때
		{
			if ((y + 1 <= n) && (arr[x ][y+1] != 1))
			{
				q.push(make_pair(make_pair(x, y+1), 1));
				cnt[x][y+1]++;
			}
			if ((x + 1 <= n) && (y + 1 <= n))
			{
				if ((arr[x + 1][y + 1] == 0) && ((arr[x][y + 1] == 0) && (arr[x + 1][y] == 0)))
				{
					q.push(make_pair(make_pair(x + 1, y + 1), 2));
					cnt[x + 1][y + 1] ++;
				}
			}
		}
		if (state == 3) // 세로일때  
		{
			if ((x + 1 <= n) && (arr[x+1][y] != 1))
			{
				q.push(make_pair(make_pair(x+1, y), 3));
				cnt[x+1][y] ++;
			}
			if ((x + 1 <= n) && (y + 1 <= n))
			{
				if ((arr[x + 1][y + 1] == 0) && ((arr[x][y + 1] == 0) && (arr[x + 1][y] == 0)))
				{
					q.push(make_pair(make_pair(x + 1, y + 1), 2));
					cnt[x + 1][y + 1]++;
				}
			}
		}
		if (state == 2)  // 대각선일때 
		{
			if ((x + 1 <= n) && (y + 1 <= n))
			{
				if ((arr[x + 1][y + 1] == 0) && ((arr[x][y + 1] == 0) && (arr[x + 1][y] == 0)))
				{
					q.push(make_pair(make_pair(x + 1, y + 1), 2));
					cnt[x+ 1][y + 1] ++;
				}
			}
			if ((x + 1 <= n) && (arr[x + 1][y] != 1))
			{
				q.push(make_pair(make_pair(x + 1, y), 3));
				cnt[x + 1][y] ++;
			}
			if ((y + 1 <= n) && (arr[x][y + 1] != 1))
			{
				q.push(make_pair(make_pair(x, y + 1), 1));
				cnt[x][y + 1] ++;
			}
		}
		q.pop();
	}
	return;
}
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	cnt[1][2] = 1;
	q.push(make_pair(make_pair(1, 2),1));
	bfs();
	ans = cnt[n][n];
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << cnt[i][j] << " ";
		cout << endl;
	}*/
	cout << ans << endl;
	return 0;
}