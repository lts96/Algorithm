#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> v;
bool visit[10001];
vector<pair <int, int>> ans;
vector<int> num;
int cnt;

void dfs(int index)
{
	if (!visit[index])
	{
		visit[index] = true;
		cnt++;
	}
	if (!v[index].size())
		return;
	int next;
	for (int i = 0; i < v[index].size(); i++)
	{
		next = v[index][i];
		if (!visit[next])
			dfs(next);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= 10000; i++)
		v.push_back(vector<int>());
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		//v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		dfs(i);
		ans.push_back(make_pair(i, cnt));
		for (int i = 0; i <= 10000; i++)
			visit[i] = false;
	}
	int max = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		//cout << ans[i].second << endl;
		if (ans[i].second > max)
			max = ans[i].second;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].second == max)
			num.push_back(ans[i].first);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	return 0;
}