#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
#include <stack>
using namespace std;
int n, ans;
int arr[1001];
int dp[1001];
// 간단한 dp문제 
int dfs(int card)
{
	if (card == 0)
		return 0;
	if (dp[card] != 0)
		return dp[card];
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (card - i >= 0)
			ret = max(dfs(card - i) + arr[i], ret);
	}
	return dp[card] = ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	ans = dfs(n);
	cout << ans << endl;
	return 0;
}
