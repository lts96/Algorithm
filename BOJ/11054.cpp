#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
int ans , ans1 , ans2 , ans3 , n, m;
int arr[1001];
int dp[1001];
int dp2[1001];
bool flag[1001];
void clear()
{
	for (int i = 0; i < n; i++)
		dp[i] = 0;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)   // 가장 긴 증가수열 찾기 
	{
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (m < dp[j])
					m = dp[j];
			}
		}
		dp[i] = m + 1;
	}
	for (int i = 0; i < n; i++)
		ans1 = max(ans1, dp[i]); 

	for (int i = n-1; i >= 0; i--)  // 가장 긴 감소수열 찾기 
	{
		int m = 0;
		for (int j = n-1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				if (m < dp2[j])
					m = dp2[j];
			}
		}
		dp2[i] = m + 1;
	}
	for (int i = 0; i < n; i++)
		ans2 = max(ans2, dp2[i]);  

	for (int i = 0; i < n; i++)
	{
		dp[i] = dp[i] + dp2[i] - 1;
		ans3 = max(ans3, dp[i]);
	}

	ans = max(ans3, max(ans1, ans2));
	cout << ans << endl;
	return 0;
}