#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector <pair<int, int>> v;
long long ccw(long long x1 , long long y1 , long long x2 , long long y2 , long long x3 , long long y3)
{
	long long temp = (long long)((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1));
	return temp;
}
int main(void)
{
	//ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , a, b; 
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	int x = v[0].first;
	int y = v[0].second;
	for (int i = 1; i < n - 1; i++)
		ans += ccw(x, y, v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	ans = abs(ans);
	if (ans & 1)  // 어차피 넓이가 짝수면 나머지는 0, 홀수면 0.5인걸 이용
		cout << ans / 2 << ".5" << endl;
	else
		cout << ans / 2 << ".0" << endl;
	return 0;
}