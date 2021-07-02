#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int n;
int depth[10001];
int parent[10001];
vector <int> tree[10001];
void dfs(int idx, int d)
{
	depth[idx] = d;
	int next;
	for (int i = 0; i < tree[idx].size(); i++)
	{
		next = tree[idx][i];
		dfs(next, d + 1);
	}
	return;
}
int lca(int x, int y)
{
	int a = x, b = y;
	while (1)
	{
		if (depth[a] == depth[b])  // 깊이가 일치할때 
		{
			if (a == b)      // 한쪽이 다른 한쪽의 조상인 경우 예외처리 
				return a;
			if (parent[a] == parent[b])  // 부모도 일치하면 정답  
				return parent[a];
			else                  // 부모가 일치하지 않으면 둘다 1단계 위로
			{
				a = parent[a];
				b = parent[b];
				continue;
			}
		}
		else   // 뎁스가 다르면 더 깊은 쪽을 1칸 위로 
		{
			if (depth[a] > depth[b])
				a = parent[a];
			else 
				b = parent[b];
		}
	}
	return 0;
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test,a ,b;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n;
		for (int i = 0; i <= 10000; i++)
		{
			depth[i] = parent[i] = 0;
			tree[i].clear();
		}
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			parent[b] = a;
			tree[a].push_back(b);
		}
		for (int i = 1; i <= 10000; i++)
		{
			if (!parent[i])
			{
				dfs(i, 0);
				break;
			}
		}
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
	return 0;
}