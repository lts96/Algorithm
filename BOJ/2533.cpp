#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000001
vector <int> arr[MAX];
vector <int> tree[MAX];
int dp[MAX][2];
int n, ans;
bool visit[MAX];
int dfs(int idx, int ea)
{
	visit[idx] = true;
	if (tree[idx].size() == 0)
	{
		if (ea)
			return 1;
		else
			return 0;
	}
	if (dp[idx][ea] != -1)
		return dp[idx][ea];
	if (ea)  // 내가 얼리어답터 
	{
		int &ret1 = dp[idx][1];
		if (ret1 == -1)
			ret1 = 1;
		for (int i = 0; i < tree[idx].size(); i++)
			ret1 += min(dfs(tree[idx][i], 0), dfs(tree[idx][i], 1));
		
		return ret1;
	}
	else //내가 얼리어답터가 아닐때
	{
		int& ret2 = dp[idx][0];
		if (ret2 == -1)
			ret2++;
		for (int i = 0; i < tree[idx].size(); i++)
			ret2 += dfs(tree[idx][i], 1);  // 자식은 무조건 얼리 
		return ret2;
	}
}
void setTree(int root, int parent) // 단방향 그래프 생성 
{
	if (parent != 0)
		tree[parent].push_back(root);
	for (int i = 0; i < arr[root].size(); i++)
	{
		if (arr[root][i] != parent)
			setTree(arr[root][i], root);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][1] = -1;
	setTree(1, 0);

	ans = min(dfs(1, 1),dfs(1,0));
	//for (int i = 1; i <= n; i++)
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	cout << ans << "\n";
	return 0;
}