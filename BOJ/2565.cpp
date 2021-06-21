#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
int ans, n, m;
int arr[501];
int dp[501];     // 교차하지 않는 직선은 증가 수열의 형태를 띄게된다 -> lis 사용 
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 1; i <= 500; i++)
	{
		int m = 0;
		if (arr[i] == 0)
			continue;
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
	//for (int i = 1; i <= 10; i++)
		//cout << dp[i] << " ";
	//cout << endl;
	int cnt = 0;
	for (int i = 1; i <= 500; i++)
	{
		if (arr[i])
			cnt++;
		if (ans < dp[i])
			ans = dp[i];
	}
	ans = cnt - ans;
	cout << ans << endl;
	return 0;
}