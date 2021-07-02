#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
long long n, m , k;
long long ans1, ans2;  // ans1은 5의 개수 ans2는 2의 개수 
// 둘중에서 모자란 쪽으로 결정된다
long long func(int i)
{
	k = n - m;
	long long temp , cnt = i;
	long long result = 0;
	while (1)
	{
		temp = n / cnt;
		if (temp > 0)
			result += temp;
		else
			break;
		cnt *= i;
	}
	cnt = i;
	while (1)
	{
		temp = m / cnt;
		if (temp > 0)
			result -= temp;
		else
			break;
		cnt *= i;
	}
	cnt = i;
	while (1)
	{
		temp = k / cnt;
		if (temp > 0)
			result -= temp;
		else
			break;
		cnt *= i;
	}
	return result;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	ans1 = func(5);
	ans2 = func(2);
	cout << min(ans1 , ans2) << endl;
	return 0;
}