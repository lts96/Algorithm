#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;
long long n , ans;
long long pow2(long long v)
{
	long long result = 1;
	return result << v;
}
// n번 분할했을때 커버가능한 수   (n+1) * 2^(n+1)-1
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	long long temp, cnt = 0;
	while (1)
	{
		temp = (cnt + 1) * pow2(cnt + 1) - 1;
		if (n <= temp)
		{
			ans = cnt; 
			break;
		}
		cnt++;
	}
	cout << ans << "\n";
	return 0;
}