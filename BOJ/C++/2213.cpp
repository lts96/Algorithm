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
vector <int> v;
// 트리의 독립집합 = 우수 마을 문제와 동일 
// 대신 추가된 것은 집합에 속하는 노드를 출력하라는 것
// p는 이전 노드 번호 
int dfs(int idx, int flag, int p)
{
	if (idx < 1 || idx > n)
		return 0;
	if (dp[idx][flag])
		return dp[idx][flag];
	int next, result;
	if (flag) // 독립집합에 속하는 경우 
	{
		result = arr[idx];
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if (next != p)
				result += dfs(next, 0, idx);
		}
		return dp[idx][flag] = result;
	}
	else
	{
		// 내가 독립집합에 속하지 않는 경우 자식은 2가지 경우 모두 가능 
		result = 0;
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if (next != p)
			{
				int r1, r2;
				r1 = dfs(next, 1, idx);
				r2 = dfs(next, 0, idx);
				result += max(r1, r2);
			}
		}
		return dp[idx][flag] = result;
	}
}
// 이 부분을 생각해내지 못함 
// 이미 값이 전부 갱신되어 있으므로 max가 되는 방향으로만 탐색을 진행하면됨
void trace(int idx, int flag, int p)
{
	if (idx < 1 || idx > n)
		return;
	int next;
	if (flag) // 이 노드가 독립집합에 속한다는 의미 
	{
		v.push_back(idx);
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if (next != p)
				trace(next, 0, idx);
		}
	}
	else 
	{
		for (int i = 0; i < tree[idx].size(); i++)
		{
			next = tree[idx][i];
			if (next != p)
			{
				// 독립집합에 포함시켜야 하는 경우 
				if (dp[next][1] >= dp[next][0])
					trace(next, 1, idx);
				else 
					trace(next, 0, idx);
			}
		}
	}
	return;
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
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int r1, r2;
	r1 = dfs(1, 1, 0);
	r2 = dfs(1, 0, 0);
	ans = max(r1 , r2);
	cout << ans << endl;
	if (r1 >= r2)
		trace(1, 1, 0);
	else
		trace(1, 0, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
