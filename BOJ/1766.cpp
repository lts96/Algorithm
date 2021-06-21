#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b;
int degree[32001];
vector <int> v[32001];
priority_queue< int, vector<int>, greater<int> > q;
void topological_sort()
{
	int index;
	while (!q.empty())
	{
		index = q.top();
		cout << index << " ";
		q.pop();
		for (int i = 0; i < v[index].size(); i++)
		{
			degree[v[index][i]]--;
			if (degree[v[index][i]] == 0) 
				q.push(v[index][i]);
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		degree[b]++;  // 내 부모가 있는 경우
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!degree[i])
			q.push(i);
	}
	topological_sort();
	return 0;
}