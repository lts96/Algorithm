#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX 1000001
int dp[MAX];
int arr[MAX];
int n, ans;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = 1;
	vector <int> v;
	v.push_back(arr[0]);
	int maximum;
	for (int i = 1; i < n; i++)
	{
		maximum = v[v.size() - 1];
		// 지금 값이 제일 크면 바로 픽해준다
		if (arr[i] > maximum)
			v.push_back(arr[i]);
		else
		{
			// 지금 값이 제일 크지 않으면 내 값과 같거나 큰 값의 위치를 찾는다
			// 위치 = 증가 수열의 크기 
			int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[index] = min(v[index], arr[i]);
		}
	}
	cout << v.size() << endl;
	return 0;
}