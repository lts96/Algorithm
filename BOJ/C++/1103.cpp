#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n, m, ans;
int arr[103][103];
bool visit[103][103];
int cache[103][103];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
// 그래프 탐색 문제인데 사이클을 찾아야된다. -> 사이클 있으면 -1
// 밟은 곳을 또 밟으면 사이클 생겼다고 간주 -> -1 리턴
// 정석적으로 풀면 시간 초과 -> dp를 이용해서 연산을 줄여야함 

/*
반례
4 4
3HH2
H1HH
H2H1
2219
답은 8
*/
int dfs(int x, int y)
{
	/*
	cout << x << " " << y << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << visit[i][j] << " ";
		cout << endl;
	}
	*/
	int value = arr[x][y];
	int temp;
	if (visit[x][y])  // 사이클 처리 
		return -1;
	visit[x][y] = true;
	if (cache[x][y] > 0)  // 캐시 값 있으면 바로 반환 -> 연산 줄이기 
	{
		visit[x][y] = false;
		return cache[x][y];
	}
	for (int i = 0; i < 4; i++)
	{
		if ((x + value * dx[i] >= 0 && x + value * dx[i] <= n - 1) && (y + value * dy[i] >= 0 && y + value * dy[i] <= m - 1))
		{
			if (arr[x + value * dx[i]][y + value * dy[i]] == 0)
				continue;
			temp = dfs(x + value * dx[i], y + value * dy[i]);
			if (temp == -1)
				return temp;
			else
				cache[x][y] = max(temp, cache[x][y]);
		}
	}
	visit[x][y] = false;
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << visit[i][j] << " ";
		cout << endl;
	}
	*/
	cache[x][y]++;
	//cout << "cache[" << x << "][" << y << "] : " << cache[x][y] << endl;
	return cache[x][y];
}

int main()
{
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'H')
				arr[i][j] = 0;
			else
				arr[i][j] = s[j] - '0';
		}
	}
	ans = dfs(0, 0);
	cout << ans << endl;
	//system("pause");
	return 0;
}
