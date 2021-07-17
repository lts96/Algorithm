#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector <int> arr;
vector <int> tree[10001];
int dp[10001][2];
int n, ans;
// 백준 사회망 서비스와 동일한 방식 
int dfs(int idx, int flag, int p)
{
	if (idx < 1 || idx > n)
		return 0;
	if (dp[idx][flag])
		return dp[idx][flag];
	// 우수마을일때랑 아닐때랑 구분 
	if (flag)  // 우수마을일때 
	{
		int next, result = arr[idx];
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if(next != p)
				result += dfs(next, 0, idx);
		}
		return dp[idx][flag] = result;
	}
	else
	{
		// 내가 우수마을이 아닐때 내 자식이 반드시 우수마을이어야 하는건 아님
		int next, result = 0;
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if (next != p)
				result += max(dfs(next, 1, idx), dfs(next, 0, idx));
		}
		return dp[idx][flag] = result;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	arr.push_back(0);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	ans = max(dfs(1, 0, 0), dfs(1, 1, 0));
	cout << ans << endl;
	return 0;
}
