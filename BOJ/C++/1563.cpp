#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
long long n, ans;
long long cache[1001][2][3];
#define div 1000000


long long dp(int d, int l, int a)
{
	if (l == 2 || a == 3)
		return 0;
	if (d == n)
		return 1;
	if (cache[d][l][a] != -1)
		return cache[d][l][a];
	long long ret = dp(d + 1,l, 0);
	if (l < 1)
		ret = (ret + dp(d + 1,l+1, 0)) % div;
	if (a < 2)
		ret = (ret + dp(d + 1, l, a+1)) % div;
	return cache[d][l][a] = ret;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = -1;
		}
	}
	dp(0,0,0);
	ans = cache[0][0][0];
	cout << ans << "\n";
	return 0;
}