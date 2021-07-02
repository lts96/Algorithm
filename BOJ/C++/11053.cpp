#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;
int n, m;
int arr[1001];
int dp[1001];
int ans;

// 점화식을 좀 넓게 생각 -> 나보다 arr[i] 값이 작은 애들 중 제일 큰 length를
// 가진 놈을 골라서 +1
// 왜 n이 1000 이었나 의심해볼것 -> n^2으로도 풀리게 하기 위해
int main(void)
{
	int max;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		int m = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > m)
					m = dp[j];
			}
		}
		dp[i] = m + 1;
	}
	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > m)
			m = dp[i];
	}
	cout << m << "\n";
	return 0;
}