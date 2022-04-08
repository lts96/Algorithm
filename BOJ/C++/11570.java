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
int arr[2005];

// 백준 경찰차와 같은 로직의 문제 
// 점화식을 생각하는게 너무 어려워서 힌트 봄 
// dp[i][j] = i를 마지막으로 부르고 j번째를 마지막으로 각각 부른 경우
// 저장하는건 이때까지 든 힘듬의 최소합 
int dp[2005][2005];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	// 최소를 찾아야하므로 INF 초기화
	ans = INF;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	}
	// 각각 처음 부르는 음은 0이므로 dp[0][1]까진 0
	dp[1][0] = 0;
	dp[0][1] = 0;
	int next;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// 둘이서 같은 노래를 마지막으로 부르는 경우는 없다
			if (i != j)
			{
				// 왜 next가 이렇게 나오나?
				// i번째와 j번째중 더 큰수를 k라고 할때 k까진 누군가가 불렀음 
				// 다음에 계산해야할건 k+1번째 
				next = max(i, j) + 1;
				// 이걸하는 이유는 next가 처음 부르는 노래인 경우 abs값을 0으로 만들기 위해
				// next가 처음 부르는 노래면 힘든 정도는 0이 더해져야한다.
				dp[next][j] = min(dp[next][j], dp[i][j] + abs(i==0 ? 0 : arr[next] - arr[i]));
				dp[i][next] = min(dp[i][next], dp[i][j] + abs(j==0 ? 0 : arr[next] - arr[j]));
			}
		}
	}

	// 누구든 n번째 노래까지 불렀다면 정답에 들어갈 수 있음 
	// 그중에서 최소 찾기 
	for (int i = 0; i < n; i++)
	{
		ans = min(dp[n][i], ans);
		ans = min(dp[i][n], ans);
	}
	cout << ans << "\n";
	return 0;
}
