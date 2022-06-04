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
vector <pair <int, int >> tree[MAX];
int depth[MAX];
int parent[MAX][2];

/*
2개 정점의 lca를 구하는 문제
lca까지 올라가면서 거리를 쭉 더하고 총합을 출력해주면 된다
이건 n이 작아서 parse table 안써도 됨
*/

int lca(int a, int b)
{
	// 더 깊은 노드를 찾는다 
	// a를 더 깊은 노드로 정함 
	int sum = 0;
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// a와 b 노드의 깊이를 똑같이 맞춰준다
	// 더 깊은 쪽에서 올라온다 
	while (depth[a] != depth[b])
	{
		sum += parent[a][1];
		a = parent[a][0];
	}
	if (a == b)
		return sum;
	while (a != b)
	{
		sum += (parent[a][1] + parent[b][1]);
		a = parent[a][0];
		b = parent[b][0];
	}
	return sum;
}
void dfs(int idx, int d)
{
	if (depth[idx] == -1)
		depth[idx] = d;
	int next, w;
	for (int i = 0; i < tree[idx].size(); i++)
	{
		next = tree[idx][i].first;
		w = tree[idx][i].second;
		if (depth[next] != -1)
			continue;
		// 부모 기록
		parent[next][0] = idx;
		parent[next][1] = w;
		dfs(next, d + 1);
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
		depth[a] = depth[b] = -1;
	}
	// 모든 정점의 depth를 미리 구해서 저장 
	dfs(1, 0);
	
	cin >> m; 
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		ans = lca(a, b);
		cout << ans << "\n";
	}
	return 0;
}
