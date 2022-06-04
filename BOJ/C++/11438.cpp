#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define MAX 100001
int n, m, ans;
vector <int> tree[MAX];
int depth[MAX];

// 희소 배열 사용하는 lca 문제
int parent[MAX][21];
int lca(int a, int b)
{
	// 더 깊은 노드를 찾는다 
	// a를 더 깊은 노드로 정함 
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// a와 b 노드의 깊이를 똑같이 맞춰준다
	// 더 깊은 쪽에서 올라온다 
	for (int i = 20; i >= 0; i--)
	{
		if (depth[a] - depth[b] >= (1 << i))
			a = parent[a][i];
	}

	// a와 b노드의 깊이가 같고, 같은 노드라면 바로 리턴
	if (a == b)
		return a;
	for (int i = 20; i >= 0; i--)
	{
		// 부모 노드가 다르면 점프 
		if (parent[a][i] != parent[b][i])
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	// lca는 반드시 존재하므로 for문을 나올때 a와 b의 부모는 같다 
	return parent[a][0];
}
void dfs(int idx, int d)
{
	if (depth[idx] == -1)
		depth[idx] = d;
	int next;
	for (int i = 0; i < tree[idx].size(); i++)
	{
		next = tree[idx][i];
		if (depth[next] != -1)
			continue;
		// 내 부모 저장 
		parent[next][0] = idx;
		dfs(next, d + 1);
	}
	return;
}
void setParent()
{
	// 부모의 부모를 계속 건너뛰면서 2^n으로 뛰게됨 
	for (int j = 1; j < 21; j++)
	{
		for (int curr = 1; curr <= n; curr++)
			parent[curr][j] = parent[parent[curr][j - 1]][j - 1];
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		depth[a] = depth[b] = -1;
	}
	// 모든 정점의 depth를 미리 구해서 저장 
	dfs(1, 0);
	// 나의 2^n번째 부모도 찾아서 희소배열에 저장
	// 왜 이렇게 되는지는 직접 그려보면 이해가 빠름 
	setParent();
	cin >> m; 
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		ans = lca(a, b);
		cout << ans << "\n";
	}
	return 0;
}
