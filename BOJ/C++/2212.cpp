#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n,k;
vector <long long> arr, dist;
long long ans;
// 좌표를 정렬하고 각 좌표별 차이값을 구한다
// 기지국이 k개이므로 k-1개의 거리를 지울 수 있음 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> k;
	long long temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
  // k가 n보다 크거나 같을 수 있으므로 이런 경우를 반드시 예외처리해줘야한다 
	if (n <= k)
	{
		cout << ans << endl;
		return 0;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 1; i++)
		dist.push_back(arr[i + 1] - arr[i]);
	long long s = dist.size();
	sort(dist.begin(), dist.end());
	for (int i = 0; i < k-1; i++)
		dist[s - 1 - i] = 0;
	for (int i = 0; i < s; i++)
		ans += dist[i];
	cout << ans << endl;
	return 0;
}
