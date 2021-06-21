#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int a[2] , b[2] , c[2], ans[2];
int m, n , r;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	c[1] = a[1] * b[1];
	c[0] = a[0] * b[1] + a[1] * b[0];
	m = max(c[0], c[1]);
	n = min(c[0], c[1]);
	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	c[1] /= m;
	c[0] /= m;
	cout << c[0] << " " << c[1] << "\n";
	return 0;
}