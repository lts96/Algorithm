#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[32001];
vector<int> arr[32001];
vector <int> ans;
void dfs(int idx)
{
	int next;
	if (!visit[idx])
		visit[idx] = true;
	for (int i = 0; i < arr[idx].size(); i++)
	{
		next = arr[idx][i];
		if (!visit[next])
			dfs(next);
	}
	ans.push_back(idx);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m , a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!visit[i])
			dfs(i);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";
	return 0;
}