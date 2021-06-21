#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define INF 2147483647
long long arr[101][101];
long long n, m;
using namespace std;
long long p[101][101]; // 이전 노드 저장용 
void floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				// 경유점 i를 거치는게 최소일때
				if (arr[k][j] > arr[k][i] + arr[i][j]) 
				{
					arr[k][j] = arr[k][i] + arr[i][j];
					p[k][j] = p[i][j];
				}
			}
		}
	}
	return;
}
void dfs(int i, int d , int depth)
{
	if (d == 0 || d == i)
	{
		cout << depth << " " << d << " ";
		return;
	}
	dfs(i, p[i][d] , depth+1);
	cout << d << " ";
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> m;
	long long a, b, c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
		p[a][b] = a;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] < INF)
				cout << arr[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 0 || arr[i][j] >= INF)
				cout << "0\n";
			else
			{
				dfs(i, j ,1);
				cout << "\n";
			}
		}
	}
	return 0;
}