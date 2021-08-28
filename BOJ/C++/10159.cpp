#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
#define INF 210000000
int dist[101][101];
int n, m, ans;
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	cin >> m;
	int a, b;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		dist[a][b] = 1;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		ans = 0;
		// 내가 알 수 없는 지점 = 내가 갈 수 없으면서 나보다 크다고 비교된적 없는 곳 
		// 즉 a-> b  뿐만 아니라 b->a 의 경로가 둘다 없어야됨 
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= INF && dist[j][i] >= INF && i != j)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
