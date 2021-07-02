#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
long long n , ans;
vector <long long> arr , t , p;
vector <bool> visit;
long long dp(int i)
{
	if (i >= n)
		return 0;
	if (arr[i] != 0)
		return arr[i];
	if(i + t[i] <= n)
		return arr[i] = max(dp(i + t[i]) + p[i], dp(i + 1));
	else 
		return arr[i] = max(dp(i + t[i]), dp(i + 1));
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	arr.assign(n+2 , 0);
	t.assign(n+2, 0);
	p.assign(n+2,0);
	visit.assign(n + 2, false);
	long long a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		t[i] = a;
		p[i] = b;
	}
	ans = dp(0);
	//for (int i = 0; i < n; i++)
		//cout << arr[i] << " ";
	//cout << endl;
	cout << ans << "\n";
	return 0;
}
