#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans;
bool visit[501] , input[501];
vector <int> arr[501];

bool dfs(int i, int p)
{
	if (!visit[i])  // 처음 방문
		visit[i] = true;
	else           // 재방문 -> 사이클이거나 경로가 2개 
		return false;
	if (arr[i].size() == 0)
		return true;
	bool flag = true;
	for (int j = 0; j < arr[i].size(); j++)
	{
		if (arr[i][j] != p)
		{
			if (dfs(arr[i][j], i) == false)
			{
				flag = false;
				//cout << "!!!!" << endl;
				return flag;
			}
		}
	}
	//cout << i << " flag : " << flag << endl;
	return flag;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a , b, t = 0;
	while (1)
	{
		ans = 0;
		t++;
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			if (a == 0 && b == 0)
				return 0;
			arr[a].push_back(b);
			arr[b].push_back(a);
			//input[a] = input[b] = true;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				if (dfs(i, 0) == true)
				{
					ans++;
				}
			}
		}
		cout << "Case " << t << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees.\n";
		else if (ans == 1)
			cout << "There is one tree.\n";
		else
			cout << "No trees.\n";
		for (int i = 0; i < 501; i++)
		{
			arr[i].clear();
			visit[i] = input[i] = false;
		}
	}
	return 0;
}

