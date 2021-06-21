#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m , ans;
vector <int> v[100];
vector <int> v2[100];
bool visit[100];
// 자식이 몇개인지 찾는 문제 
int dfs(int index)
{
	int next , cnt = 0;
	visit[index] = true;
	for (int i = 0; i < v[index].size(); i++)
	{
		next = v[index][i];
		if (!visit[next])
			cnt += dfs(next);
	}
	return cnt + 1;
}
int dfs2(int index)
{
	int next, cnt = 0;
	visit[index] = true;
	for (int i = 0; i < v2[index].size(); i++)
	{
		next = v2[index][i];
		if (!visit[next])
			cnt += dfs2(next);
	}
	return cnt + 1;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v2[b].push_back(a);
	}
	int temp = (n + 1) / 2 , r1 , r2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			visit[j] = false;
		r1 = dfs(i);
		for (int j = 1; j <= n; j++)
			visit[j] = false;
		r2 = dfs2(i);
		if (r1 > temp || r2 > temp)
			ans++;
	}
	cout << ans << endl;
	return 0;
}