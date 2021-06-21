#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
// A = gcd * a , B = gcd * b;
// LCM 은 A,B 로 나눴을때 나머지가 0 이어야 하므로 lcm = gcd * a * b;
int gcd(int a, int b)
{
	if (b == 0)    // 더이상 공약수가 없을때
		return a;
	else
		return gcd(b, a % b);  // 유클리드 알고리즘 참고 

}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int a, b, ans1 = 0, ans2 = 0;
	cin >> a >> b;
	ans1 = gcd(a, b);

	ans2 = ans1 * (a / ans1) * (b / ans1);
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}