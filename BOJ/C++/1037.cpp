#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , input , ans; 
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[i] = input;
	}
	sort(arr, arr + n);
	if ((n & 1) == 0)  // 제곱수가 아닐때 
		ans = arr[0] * arr[n - 1];
	else // 제곱수 일때 
		ans = pow(arr[n / 2], 2);
	cout << ans << endl;
	return 0;
}
