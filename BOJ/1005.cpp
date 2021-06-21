#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, w, a, b;
bool visit[1001];
int arr[1001][1001];
int time[1001];
int dp[1001];
vector <int> order;
int t[501];
void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
int dfs(int idx)
{
	int next, temp = 0;
	if (!visit[idx])
		visit[idx] = true;
	for (int i = 1; i<= n; i++)
	{
		next = arr[idx][i];
		if (!visit[next] && next)
			temp = max(temp, dfs(next));
		else if (visit[next] && dp[next])
			temp = max(temp, dp[next]);
	}
	return dp[idx] = temp + time[idx];
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int h = 0; h < test; h++)
	{
		cin >> n >> k;
		for (int i = 1; i <= 1000; i++)
		{
			visit[i] = false;
			time[i] = dp[i] = 0;
			for (int j = 1; j <= 1000; j++)
				arr[i][j] = 0;
		}
		for (int i = 1; i <= n; i++)
			cin >> time[i];
		for (int i = 1; i <= k; i++)
		{
			cin >> a >> b;
			arr[b][a] = a;
		}
		cin >> w;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				dfs(i);
		}
		cout << dp[w] << "\n";
	}
	return 0;
}