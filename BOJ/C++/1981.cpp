#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, ans = 210000000;
int arr[103][103];
int dx[4] = { -1, 1, 0,0 };
int dy[4] = { 0,0,-1,1 };
#define inf 2100000000
// 집배원 한상덕과 유사한 문제 -> 반드시 풀이를 기억하자 
// bfs를 결정함수로 쓰는 이분탐색 문제다 
// 총 시간복잡도 bfs (n ^ 2) * n * logn 

// 지정된 최소와 최대 값으로 통과가 가능한지 체크 
int bfs(int minh, int maxh)
{
	// 시작점은 반드시 방문하므로 이런 경우는 가능하지 않다 
	if (minh > arr[0][0] || maxh < arr[0][0])
		return 0;
	bool visit[103][103];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
	}
	visit[0][0] = true;
	queue <pair <int, int>> q;
	q.push({0,0});
	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1)
			return 1;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			// 방문했거나 지정된 최대 최소를 넘어가면 무시
			if (visit[nx][ny] || arr[nx][ny] > maxh || arr[nx][ny] < minh)
				continue;
			visit[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return 0;
}
int parametric(int m)
{
	// 최대 - 최소가 m이 되는 모든 경우를 bfs 돌려보면서
	// 가능한 경우를 찾는다 
	// 1개의 케이스라도 가능하면 참을 리턴 
	// 같은 구간 크기를 가지더라도 최대 최소가 다른 경우가 있기 때문에
	// 이 과정이 반드시 필요하다 
	for (int i = 0; i <= 200 - m; i++)
	{
		if (bfs(i, i + m))
			return 1;
	}
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int maxh = -1, minh = 2100000;
	vector <int> height;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			maxh = max(maxh, arr[i][j]);
			minh = min(minh, arr[i][j]);
		}
	}
	int left, right, mid, temp;
	left = 0;
	right = maxh - minh;

	// =을 넣지 않으면 모든 값이 같은 경우를 찾지 못한다 
	while (left <= right)
	{
		// mid는 (최대 - 최소) 값을 상징 
		mid = (left + right) / 2;
		temp = parametric(mid);
		if (temp)
		{
			ans = mid;
			right = mid - 1;
		}
		// 필요한 최소 간격을 증가 
		else
			left = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
