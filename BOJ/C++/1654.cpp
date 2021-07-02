#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
unsigned long long n, k , ans;
unsigned long long * arr;

unsigned long long cut(int m)
{
	unsigned long long result = 0 , temp;
	for (int i = 0; i < k; i++)
	{
		temp = arr[i] / m;
		if (temp > 0)
			result += temp;
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;
	arr = new unsigned long long[k];
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k);
	unsigned long long left = 1, right = arr[k-1], mid , result;
	while (left <= right)
	{
		mid = (left + right) / 2;
		result = cut(mid);
		if (result >= n)
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}
	cout << ans << endl;
	delete [] arr;
	return 0;
}
