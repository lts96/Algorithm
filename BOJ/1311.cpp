#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, fin;
int w[21][21];
int dp[21][1048576];   // i는 사람, j는 할당된 일자리 
int bitmaskDP(int cur, int bit)
{
	if (bit >= fin)  // 종료 조건
		return 0;
	int& ret = dp[cur][bit];
	if (ret != 0)
		return ret;
	ret = 2100000000;
	for (int i = 0; i < n; i++)
	{
		if (!(bit & (1 << i)))  // 할당 안한 일거리 찾기 
			ret = min(ret, bitmaskDP(cur + 1, bit | (1 << i)) + w[cur][i]);
	}
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	fin = (1 << n) - 1;
	int ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}
	// 시작을 잘못함 
	ans = bitmaskDP(0, 0);
	cout << ans << "\n";
	return 0;
}