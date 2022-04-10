#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
int n, m, k;
bool visit[1001];
vector <int> arr[1001];
vector <int> ans;
bool isCycle;
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


// 위상정렬 + 사이클 찾는 문제 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int prev, input;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		prev = -1;
		for (int j = 0; j < k; j++)
		{
			cin >> input;
			if (prev == -1)
			{
				prev = input; 
				continue;
			}
			else
			{
				arr[prev].push_back(input);
				prev = input;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
	// 사이클이 있으면 안됨 
  // 위상정렬한 결과를 봤을때 오른쪽에 있는 노드에서 왼쪽으로 가는 간선이 있다면 
  // 그건 역방향 간선 = 사이클이 있다는 것 
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = i + 1; j < ans.size(); j++)
		{
			for (int k = 0; k < arr[ans[j]].size(); k++)
			{
				if (arr[ans[j]][k] == ans[i])
				{
					cout << "0\n";
					return 0;
				}
			}
		}
	}
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	return 0;
}
