#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
int n , m,k;
int arr[101];
int s;
long long ans;
int result;
long long dp[101][21];
// 조합은 함정 -> 시간 계산해보면  over 
// DP로 푸는 문제 
// 가짓수를 저장 , 이차원 캐시 사용 , 몇번째로 계산했는지 , 계산 결과가 얼마였는지
// 앞의 수들 전체의 합을 알 필요없음. 조건 검사는 i-1 수랑 i수랑 더하거나 뺀 경우만 검사
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int start;
	cin >> n;
	cin >> start;
	for (int i = 1; i < n; i++)
		cin >> arr[i];
	dp[0][start] = 1;
	result = arr[n - 1];
	for (int i=1; i<n;i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (dp[i - 1][j] != 0)
			{
				if (j + arr[i] < 21)    // 이 부분이 핵심, 인덱스의 의미를 잘 생각해볼것
					dp[i][j+arr[i]] += dp[i-1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i-1][j];
			}
		}
	}
	ans = dp[n - 2][result]; // 결과가 result와 같은 경우만 여기 저장됨
	cout << ans << "\n";
	return 0;
}