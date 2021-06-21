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
int arr[1001];
int dp[1001];   
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				if (m < dp[j])
					m = dp[j];
			}
		}
		dp[i] = m + 1;
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}