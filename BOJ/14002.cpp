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
	vector<int> v;
	int temp = m;
	for (int i = n; i >= 1; i--)
	{
		if (dp[i] == temp)
		{
			temp--;
			v.push_back(arr[i]);
		}
	}
	cout << m << "\n";
	for (int i = v.size()-1; i >= 0; i--)
		cout << v[i] << " ";
	return 0;
}