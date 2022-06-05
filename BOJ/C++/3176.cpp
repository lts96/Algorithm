#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define MAX 100001
int n, m, ans1, ans2;
vector <pair <int, int >> tree[MAX];
int depth[MAX];
int parent[MAX][21];
int min_road[MAX][21];
int max_road[MAX][21];

// 희소배열을 사용하면서 값도 갱신해주는 문제 
// 점화식이 중요하다 
// min_road[x][k] = x의 2^k 조상까지 최소도로 
// min_road[x][k] = min(min_road[parent[x][k-1]][k-1], min_road[x][k-1])
// 각 조상이 어디까지 커버하는지 범위를 잘 살펴보자 
void lca(int a, int b)
{
	// 더 깊은 노드를 찾는다 
	// a를 더 깊은 노드로 정함 
	int maxw = 0;
	int minw = 210000000;
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// depth 맞춰주기
	// 올라가면서 최소 최대도 같이 갱신 
	int jump;
	for (int i = 20; i >= 0; i--)
	{
		jump = 1 << i;
		if (depth[a] - depth[b] >= jump)
		{
			minw = min(minw, min_road[a][i]);
			maxw = max(maxw, max_road[a][i]);
			a = parent[a][i];
		}
	}
	// a와 b가 높이도 같고 같은 노드라면 
	if (a == b)
	{
		ans1 = minw;
		ans2 = maxw;
		return;
	}
	for (int i = 20; i >= 0; i--)
	{
		// 부모 노드가 다르고 범위를 넘지 않는다면 점프 
		if ((parent[a][i] != parent[b][i]) && parent[a][i] != 0)
		{
			minw = min(minw, min_road[a][i]);
			maxw = max(maxw, max_road[a][i]);
			minw = min(minw, min_road[b][i]);
			maxw = max(maxw, max_road[b][i]);
			a = parent[a][i];
			b = parent[b][i];
		}
		// 부모가 같고 한칸 차이라면 
		minw = min(minw, min_road[a][0]);
		maxw = max(maxw, max_road[a][0]);
		minw = min(minw, min_road[b][0]);
		maxw = max(maxw, max_road[b][0]);
	}
	ans1 = minw;
	ans2 = maxw;
	return;
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
		min_road[next][0] = w;
		max_road[next][0] = w;
		dfs(next, d + 1);
	}
	return;
}
void connect()
{
	for (int j = 1; j < 21; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			min_road[i][j] = min(min_road[parent[i][j - 1]][j - 1], min_road[i][j - 1]);
			max_road[i][j] = max(max_road[parent[i][j - 1]][j - 1], max_road[i][j - 1]);
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 21; j++)
			min_road[i][j] = 210000000;
	}

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
		depth[a] = depth[b] = -1;
	} 
	dfs(1, 0);
	connect();


	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		ans1 = 210000000;
		ans2 = 0;
		lca(a, b);
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}
