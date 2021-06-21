#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int cache[1001];
#define div 10007
int dp(int d)
{
	if (d < 1)
		return 0; 
	if (cache[d] != 0)
		return cache[d];
	return cache[d] = (dp(d - 1) + dp(d - 2)) % div;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cache[1] = 1;
	cache[2] = 2;
	int ans = dp(n);
	cout << ans << endl;
	return 0;
}
