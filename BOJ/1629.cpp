#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
unsigned long long a, b, c , ans;
unsigned long long multiple(int n)
{
	if (n == 1)
		return a % c;
	if (n & 1) // 홀수번 곱해야할때
		return (multiple(n - 1) * (a % c)) % c;
		//return (temp * temp * (a % c)) % c;  // 오버 플로우 발생가능 
	else
	{
		unsigned long long temp = multiple(n / 2);
		return (temp * temp) % c;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	ans = multiple(b);
	cout << ans << "\n";
	return 0;
}