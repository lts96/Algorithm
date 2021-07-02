#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;

// 17144번 미세먼지 안녕!

queue<pair <pair<int, int> , int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int r, c, t;
int arr[51][51];
int arr_copy[51][51];
int ans = 0;
int cleaner[2][2];
void wind()   // 이상 없음 
{
	int x1 = cleaner[0][0];
	int x2 = cleaner[1][0];
	// 위쪽부터 
	for (int i = x1-1; i > 0; i--)
		arr[i][0] = arr[i - 1][0];
	for (int i = 0; i < c-1; i++)
		arr[0][i] = arr[0][i + 1];
	for (int i = 0; i < x1; i++)
		arr[i][c - 1] = arr[i + 1][c - 1];
	for (int i = c - 1; i > 0; i--) 
		arr[x1][i] = arr[x1][i - 1];
	// 공기청정기에서 나오는 바람은 0
	arr[x1][1] = 0;

	// 아래 
	for (int i = x2 + 1; i < r-1; i++)
		arr[i][0] = arr[i + 1][0];
	for(int i=0; i< c-1; i++)
		arr[r-1][i] = arr[r-1][i + 1];

	for (int i = r-1; i > x2; i--)
		arr[i][c-1] = arr[i-1][c-1];
	for (int i = c - 1; i > 0; i--)
		arr[x2][i] = arr[x2][i - 1];
	arr[x2][1] = 0;
}
void bfs()
{
	int x, y , time;
	int sec = 0;
	while (1)
	{
		while (!q.empty())
		{
			x = q.front().first.first;
			y = q.front().first.second;
			time = q.front().second;

			int dust = arr[x][y] / 5;
			for (int i = 0; i < 4; i++)
			{
				if ((x + dx[i] >= 0 && x + dx[i] < r) && (y + dy[i] >= 0 && y + dy[i] < c))
				{
					if (arr[x + dx[i]][y + dy[i]] >= 0)
					{
						arr_copy[x + dx[i]][y + dy[i]] += dust;
						arr[x][y] -= dust;
					}
				}
			}
			q.pop();
		}



		sec++;
		for (int i = 0; i < r; i++)  // 확산하면서 값이 덧씌워지는걸 막기위해 분리 
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] += arr_copy[i][j];
				arr_copy[i][j] = 0;
			}
		}
		wind();

		for (int i = 0; i < r; i++)  // 여기서 헤맴 -> 반드시 바람 불고 나서 5넘는것만 큐에 넣기 
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] >= 5)
					q.push(make_pair(make_pair(i, j), sec));
			}
		}
		// 안그럼 시간초과 or 틀림 
		if (sec == t)
			break;
	}
	


	for (int i = 0; i < r; i++)  // 방에 남아있는 미세먼지 총합 
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] >= 0)
				ans += arr[i][j];
		}
	}
	
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> t;
	int pos = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0)
				q.push(make_pair(make_pair(i, j),0));
			if (arr[i][j] < 0)
			{
				cleaner[pos][0] = i;
				cleaner[pos][1] = j;
				pos++;
			}
		}
	}
	bfs();
	/*
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	*/
	cout << ans << endl;
	return 0;
}