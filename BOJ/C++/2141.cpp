#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
long long n, ans;
vector <pair <long long, long long>> arr;
/*
무조건 사람 제일 많은 곳에 세우면 안됨
좌우 사람 수가 모두 같은 경우를 생각
왼쪽부터 사람 수를 더해가면서 사람 수 총합이 절반을 넘어가면 그 자리가 최소가 되는 자리 - > 그 이상 넘어가도 사람 차이가 증가하지 감소하지는 않기 때문
좌우 사람 수들의 합을 차이내서 구하는 방법은 더 작은 위치를 출력하지 못하는 경우가 발생해서 틀림
반례 
4 
1 1 
2 98 
3 97 
4 2    답 : 2
*/
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	long long left = 0, right = 0, diff, x, a, sum;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> a;
		arr.push_back(make_pair(x, a));
		right += a;
	}
	// 총합의 절반 계산, 홀수일 경우를 대비해서 + 1
	sum = (right + 1) / 2;
	if (n == 1)
	{
		cout << x << endl;
		return 0;
	}
	sort(arr.begin(), arr.end());
	// left는 현재 위치보다 왼쪽 사람 수
	for (int i = 0; i < arr.size(); i++)
	{
		left += arr[i].second;
		if (left >= sum)
		{
			ans = arr[i].first;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
