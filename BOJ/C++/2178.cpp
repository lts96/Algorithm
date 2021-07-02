#include <iostream>
#include <queue>
#include <utility>
#pragma warning(disable: 4996)    // 시작점이 3이되는 이유는 2번째 칸에서 3으로 바꿔버리기때문  답에는 지장 없음
using namespace std;
int n, m;
int ans;
int arr[120][120];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue <pair<int, int> > q;
void bfs()
{
	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i<4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= n - 1) && (y + dy[i] >= 0 && y + dy[i] <= m - 1))
			{
				if (arr[x + dx[i]][y + dy[i]] == 1)
				{
					arr[x + dx[i]][y + dy[i]] = arr[x][y] + 1;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
		}
		if(x==n-1&&y==m-1)
		ans = arr[x][y];
		q.pop();
	}

}
void find()
{
	q.push(make_pair(0, 0));
	bfs();
}
int main(void)
{
	cin >> n;
	cin >> m;
	for (int j = 0; j<n; j++)
	{
		for (int i = 0; i<m; i++)
		{
			scanf("%1d", &arr[j][i]);
		}
	}
	find();
	/*
	for (int j = 0; j<n; j++)
	{
		for (int i = 0; i<m; i++)
		{
			cout << arr[j][i] <<" ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	cout << ans;
	//system("pause");
	return 0;
}