#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;

int n , m;
int arr[100000];
int sum[100000];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sum[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; 
		if (a - 1 == 0)
			cout << sum[b - 1] << "\n";
		else
			cout << sum[b - 1] - sum[a - 2] << "\n";
	}

	return 0;
}