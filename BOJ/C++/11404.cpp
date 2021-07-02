#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 2147483647
using namespace std;
long long n, m;
long long dist[101][101]; // 거리 저장 
long long p[101][101];   // 이전 정점 저장용 

long long ans = INF;
void floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (dist[k][j] > dist[k][i] + dist[i][j])
				{
					dist[k][j] = dist[k][i] + dist[i][j];
					p[k][j] = p[i][j];
				}
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	long long a, b, c;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
			p[i][j] = -1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		p[a][b] = a;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= INF)
				dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}