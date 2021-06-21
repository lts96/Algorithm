#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
int n , k;
long long ans;
int dp[1002][1002];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		dp[i][1] = dp[i][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (!dp[i][j])
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] != 0)
				cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	ans =  (dp[n][k] + dp[n][k+1]) % 10007;
	cout << ans << endl;
	return 0;
}