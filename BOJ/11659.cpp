#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define INF 2147483600
using namespace std;
int n, m;
int arr[100001];
int sum[100001];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sum[1] = arr[1];
	for (int i = 2; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];
	int l, r;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		int result = sum[r] - sum[l - 1];
		cout << result << "\n";
	}

	return 0;
}