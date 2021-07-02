#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX 1000001
int dp[MAX];
int arr[MAX];
int n, ans;
int index[MAX];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		index[arr[i]] = i;
		dp[i] = 1;
	}
	int m = 0, idx;
	for (int i = 1; i < n; i++)
	{
		idx = index[arr[i] - 1];
		if(idx < i)
			dp[i] = dp[idx] + 1;
	}
	for (int i = 0; i < n; i++)
	{
		m = max(dp[i], m);
		//cout << dp[i] << " ";
	}
	cout << n - m << endl;
	return 0;
}