#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
#define INF 2100000000
int n, m, k , ans;
int arr[1005][2];
// dp[i][j] = 경찰차 1이 마지막으로 i사건 해결하고 2가 마지막으로 j를 
// 해결한 경우 최소 
// dp[i][j] =  min (dp[i][?] + ?에서 오는 거리 , dp[?][j] + ?에서 오는 거리)
int dp[1005][1005];

// 이전 좌표 갱신용
int p[1005][1005][3];
int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> arr[i][0] >> arr[i][1];
	// 최소를 찾아야하므로 INF 초기화
	ans = INF;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
			dp[i][j] = INF;
	}
	dp[1][0] = dist(1,1, arr[1][0], arr[1][1]);
	dp[0][1] = dist(n, n, arr[1][0], arr[1][1]);
	// 이전으로 가는 x
	p[1][0][0] = 0;
	// 이전으로 가는 y
	p[1][0][1] = 0;
	// 이전 사건을 해결한 경찰차 번호 
	p[1][0][2] = 1;

	p[0][1][0] = 0;
	p[0][1][1] = 0;
	p[0][1][2] = 2;
	int next , d1, d2;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			// 둘이서 같은 사건 해결 x
			if (i == j)
				continue;
			// next는 여태까지 해결한 사건 번호 중 최대 + 1
			next = max(i, j) + 1;
		  
      // 여기가 점화식 
      // 사건이 0번째일땐 각각 1,1이랑 n,n에 있으므로 ?로 별도 처리 
			// dp[i][j]까지 최소 거리합  + i에서 next까지 오는 거리 
			d1 = dp[i][j] +
				dist(i == 0 ? 1 : arr[i][0], i == 0 ? 1 : arr[i][1], arr[next][0], arr[next][1]);
			// dp[i][j]까지 최소 거리합  + j에서 next까지 오는 거리 
			d2 = dp[i][j] +
				dist(j == 0 ? n : arr[j][0], j == 0 ? n : arr[j][1], arr[next][0], arr[next][1]);
			if (dp[next][j] > d1)
			{
				dp[next][j] = d1;
				// i -> next로 왔음, next - 1번째 해결은 i,j
				p[next][j][0] = i;
				p[next][j][1] = j;
				p[next][j][2] = 1;
			}
			if (dp[i][next] > d2)
			{
				dp[i][next] = d2;
				// j -> next로 왔음, next - 1번째 해결은 i,j
				p[i][next][0] = i;
				p[i][next][1] = j;
				p[i][next][2] = 2;
			}
		}
	}

	/*
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (dp[i][j] == INF)
				cout << "0 ";
			else
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// k번째 사건을 해결했다면 정답 후보에 들어갈 수 있음 
	// 그중에서 최소 찾기 
	int px = 0, py = 0;
	for (int i = 0; i < k; i++)
	{
		if (ans > dp[k][i])
		{
			ans = min(dp[k][i], ans);
			px = k;
			py = i;
		}
		if (ans > dp[i][k])
		{
			ans = min(dp[i][k], ans);
			px = i;
			py = k;
		}
	}
	cout << ans << "\n";

	// 역추적 
	int nx, ny;
	vector <int> car;
	while (k > 0)
	{
		car.push_back(p[px][py][2]);
		//cout << p[px][py][2] << "\n";
		nx = p[px][py][0];
		ny = p[px][py][1];
		px = nx;
		py = ny;
		k--;
	}
	for (int i = car.size() - 1; i >= 0; i--)
		cout << car[i] << "\n";
	return 0;
}
