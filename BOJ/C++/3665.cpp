#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b;
bool visit[501];
int arr[501][501];
vector <int> ans;
int t[501];
void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
void dfs(int idx)
{
	int next;
	if (!visit[idx])
		visit[idx] = true;
	for (int i = 1; i<= n; i++)
	{
		next = arr[idx][i];
		if (!visit[next] && next)
			dfs(next);
	}
	ans.push_back(idx);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		for (int i = 0; i <= 500; i++)
		{
			visit[i] = false;
			for (int j = 0; j <= 500; j++)
				arr[i][j] = 0;
		}
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a;
			t[a] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (t[i] < t[j])
					arr[i][j] = j;
			}
		}
		cin >> m; 
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			if (t[a] > t[b])
			{
				arr[a][b] = b;
				arr[b][a] = 0;
			}
			else
			{
				arr[a][b] = 0;
				arr[b][a] = a;
			}
		}
		//print();
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				dfs(i);
		}
		reverse(ans.begin(), ans.end());

		// 사이클 검사 
		// 사이클이 있다면 오른쪽에서 왼쪽으로 가는 역방향 간선이 존재한다는 것 
		bool cycle = false;
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = i+1; j < ans.size(); j++)
			{
				if (arr[ans[j]][ans[i]])
				{
					cycle = true;
					break;
				}
			}
			if (cycle)
				break;
		}
		
		if(cycle)
			cout << "IMPOSSIBLE\n";
		else
		{
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << " ";
			cout << "\n";
		}
		ans.clear();
	}
	return 0;
}