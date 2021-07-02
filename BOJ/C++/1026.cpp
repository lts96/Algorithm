#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> a;
vector <int> c;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n , x,y ;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
    for (int i = 0; i < n; i++)
	{
		cin >> x;
		c.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (a[i] * c[n - 1 - i]);
	cout << ans << endl;
	return 0;
}
