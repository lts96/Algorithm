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
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	int temp = 0;
	for (int i = 1; i < n; i++)
	{
		temp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
				temp = max(dp[j], temp);
		}
		dp[i] = temp + 1;
	}
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		m = max(m, dp[i]);
		//cout << dp[i] << " ";
	}
	//cout << endl;
	cout << n - m << endl;
	return 0;
}