#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000][3];
int dp[1000][3];
#define inf 900000000
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 2;
	cin >> n;
	int temp[3];
	int ans = inf;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == j)
				dp[0][i] = arr[0][i];
			else
				dp[0][i] = inf;
		}
		for (int i = 1; i <= n-1; i++)
		{
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
		}
		for (int i = 0; i < 3; i++)
		{
			if (i != j)
				ans = min(ans, dp[n-1][i]);
		}
	}
	cout << ans << endl;
	return 0;
}