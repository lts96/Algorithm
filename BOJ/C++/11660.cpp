#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;
int n, m;
int arr[1025][1025];
int sum[1025][1025];
int sum2[1025][1025];
int dp[1025][1025];
int x, y, x2, y2;
// 64%에서 시간 초과 , 단순한 걸론 안풀림 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	int s = 0 , s2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s += arr[i][j];
			s2 += arr[j][i];
			sum2[j][i] = s2;
			sum[i][j] = s;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = sum[1][i];
		dp[i][1] = sum2[i][1];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1] + dp[i-1][j] + arr[i][j];
		}
	}
	/*
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> x2 >> y2;
		if (x != x2 && y != y2)
		{
			cout << dp[x2][y2] - dp[x2][y - 1] - dp[x - 1][y2] + dp[x - 1][y - 1] << "\n";
		}
		else if (x == x2 && y != y2)
		{
			cout << sum[x][y2] - sum[x][y] + arr[x][y]<< "\n";
		}
		else if (x != x2 && y == y2)
		{
			cout << sum2[x2][y2] - sum2[x][y] + arr[x][y]<< "\n";
		}
		else if (x == x2 && y == y2)
			cout << arr[x][y] << "\n";
	}

	return 0;
}