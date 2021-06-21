#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int time[501];
int arr[501][501];
int visit[501];
int dp[501];
int dfs(int idx)
{
	int next, ret = 0;
	if (!visit[idx])
		visit[idx]++;
	for (int i = 1; i <= n; i++)
	{
		next = arr[idx][i];
		if (!visit[next] && next)
			ret = max(ret, dfs(next));
		else if (visit[next] && dp[next])
			ret = max(ret, dp[next]);
	}
	return dp[idx] = ret + time[idx];
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];
		while (1)
		{
			cin >> a;
			if (a == -1)
				break;
			else
				arr[i][a] = a;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
			dfs(i);
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << "\n";
	return 0;
}