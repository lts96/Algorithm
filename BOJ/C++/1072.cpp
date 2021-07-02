#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;

long double x, y;
long long z, ans = -1;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y;
	z = (long double)y / (long double)x * 100;
	if (x == y)
	{
		cout << -1 << endl;
		return 0;
	}
	long long left = 0, right = 2100000000, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int v = (long double)(y + mid) / (long double)(x + mid) * 100;
		if (v <= z)
			left = mid + 1;
		else if (v >= z + 1)
		{
			
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
