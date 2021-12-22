#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n, m, ans;
int arr[1003][1003];
bool visit[1003];

// 연결요소의 개념만 잘 알아두자

void dfs(int idx)
{
	int next;
	for (int i = 0; i < n; i++)
	{
		if (arr[idx][i] && !visit[i])
		{
			visit[i] = true;
			dfs(i);
		}
	}
	return;
}

int main()
{
	int a,b, cnt;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a-1][b-1] = 1;
		arr[b-1][a-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
