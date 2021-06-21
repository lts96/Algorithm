#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <math.h>
#define INF 987654321
using namespace std;
int arr[520][2];
int dp[520][520];  // i는 맨앞 행렬 , j는 맨 뒤 행렬 
int ans , n;

// 점화식 인덱스 주의 
// 2덩이로 나눠지는 모든 경우를 체크해야됨 
// 단순하게 가운데로만 나누고 끝부분으로만 나누면 3-6 6-3 처럼 놓치는 경우 발생
int d(int f, int l)
{
	if (f == l)
		return 0;
	if (l < 0 || f > n - 1)
		return 0;
	if (dp[f][l] != 0)
		return dp[f][l];
	int m = INF;
	for (int i = f; i < l; i++)  // dp가 현재 0으로 되어있기 때문에 다른 변수 사용해서 최소값 추출
		m = min(m, d(f, i) + d(i + 1, l) + arr[f][0] * arr[l][1] * arr[i][1]);
	return dp[f][l] = m;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < n; i++)
	{
		dp[i][i + 1] = arr[i][0] * arr[i + 1][0] * arr[i + 1][1];
	}
	
	d(0, n - 1);
	ans = dp[0][n - 1];
	cout << ans << endl;
	return 0;
}