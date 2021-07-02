#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iomanip>
using namespace std;
int n, k;
int arr[501];
int main(void)
{
	std::cout << std::setprecision(11);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int a;
	long double ans = 9999999999;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (k <= n)
	{
		for (int i = 0; i < n - k + 1; i++)
		{
			long double sum = 0, result;
			for (int j = i; j < i + k; j++)
				sum += arr[j];
			sum /= (double)k;
			long double temp = 0;
			for (int j = i; j < i + k; j++)
				temp = temp + pow(arr[j] - sum, 2);
			temp /= (double)k;
			result = sqrt(temp);
			//cout << result << endl;
			ans = min(result, ans);
		}
		k++;
	}
	cout << ans << endl;
	return 0;
}