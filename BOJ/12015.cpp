#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;
int n, m;
int arr[1000001];
int dp[1000001];
int ans;
vector <int> pick;
// n값이 커서 nlogn으로 풀어야됨
// 기존 탐색이 n -> logn으로 변형 (이분 탐색)
// 우선 순위 큐로는 해결 불가 -> 같은 dp값이 중복되어서 들어가서 올바른 인덱스 추출 불가
// 수열을 항상 최적화 하는 방법 -> 증가하는 상태를 유지하면서 각 원소를 작은 arr 값으로 
// 계속 갱신해주면 언제나 최적의 증가 수열을 보장.

// 길이는 맞는데 수열의 원소까지 구하려면 추가적인 조치 필요

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++)
	{
		if (pick.size() == 0)
		{
			pick.push_back(arr[i]);
			continue;
		}
		int m = pick.back();  
		if (arr[i] > m)
			pick.push_back(arr[i]);
		else
		{
			int index = lower_bound(pick.begin(), pick.end(), arr[i]) - pick.begin();
			pick[index] = arr[i];
		}
	}

	cout << pick.size() << "\n";
	return 0;
}