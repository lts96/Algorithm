#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n,m,ans;
int arr[10001];
int main()
{
	int start = 0, end = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = arr[0];
	while (start < n)
	{
		if (sum == m)
			ans++;
		if (sum > m || end == n - 1)
		{
			sum -= arr[start];
			start++;
		}
		else
		{
			end++;
			sum += arr[end];
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}