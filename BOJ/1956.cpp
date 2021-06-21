#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 2147483647
using namespace std;
long long v, e;
long long dist[401][401]; // 거리 저장 
long long p[401][401];   // 이전 정점 저장용 

long long ans = INF;

void floyd()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			for (int k = 1; k <= v; k++)
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
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
			p[i][j] = -1;
		}
	}
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
		p[a][b] = a;
	}
	floyd();
	long long temp;
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i != j)
			{
				temp = dist[i][j] + dist[j][i];
				if (ans > temp)
					ans = temp;
			}
		}
	}
	if (ans >= INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}