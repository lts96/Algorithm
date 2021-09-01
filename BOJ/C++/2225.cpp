#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
#define div 1000000000
ll n, k, ans;
ll cache[201][201];
/*
2차원 dp로 풀어야되는 문제 = dp[값][개수]
위부터 아래로 내려가면서 for문 돌려서 조건에 맞는 경우만 재귀 호출
점화식은 dp[n][k] = dp[n - value][k-1] 들의 모든 합
*/
ll dp(ll value, ll cnt)
{
	ll ret = 0;
	if (cnt == 1 && value >= 0)
		return 1;
	else
	{
		if (cache[value][cnt] != -1)
			return cache[value][cnt];
		for (int i = 0; i <= value; i++)
		{
			if (value - i >= 0 && cnt > 1)
				ret = (ret + dp(value - i, cnt - 1)) % div;
		}
		return cache[value][cnt] = ret;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
			cache[i][j] = -1;
	}
	cache[0][0] = 0;
	cache[0][1] = 1;
	cache[1][1] = 1;
	cache[2][1] = 1;
	ans = dp(n, k);
	cout << ans << endl;
	return 0;
}
