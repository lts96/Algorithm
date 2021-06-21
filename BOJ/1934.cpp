#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t,a,b;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << a * b / gcd(max(a,b), min(a,b)) << "\n";
	}
	return 0;
}
