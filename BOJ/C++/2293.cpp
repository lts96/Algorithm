#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, k , ans;
int dp[10001];
int coin[101];
// 현재 동전만으로 k를 만드는 경우 dp[k]
// 동전 종류를 하나씩 늘려가면서 갱신해야함 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int index;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	// 반드시 이렇게 초기화 해줘야됨 
	// 0을 1로 하는 이유 -> 새로운 동전이 들어왔을때 경우의 수를 1씩 추가해주기 위해
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			index = j - coin[i];  // 새 동전 coin[i]가 생겼을때
			if(index >= 0)
				dp[j] += dp[index];
		}
	}
	ans = dp[k];
	cout << ans << endl;
	return 0;
}