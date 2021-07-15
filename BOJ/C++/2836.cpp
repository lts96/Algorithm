#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, ans;
vector <pair <ll, ll>> arr;
/*
스위핑 응용 문제 

푼 방법
되돌아가야하는 구간끼리 합쳐버리기
합치는건 이전에 풀었던 선 긋기와 동일한 방식으로
역으로 돌아가야되는 경우 ( a < b) 위주로 소팅해서 구현
*/
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b;
	ans = m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}
	// 역 구간 위주로 소팅 
	sort(arr.begin(), arr.end());
	ll x, y, s = 0, d= 0;
	for (int i = 0; i < n; i++)
	{
		x = arr[i].first;
		y = arr[i].second;
		if (x < y)
		{
			// 합칠 구간이 아예 떨어져있을때 
			if (d < x)
			{
				ans += ((d - s) * 2);
				s = x;
				d = y;
			}
			// 합칠 구간이 일부 겹칠때 
			else if (s <= x && d <= y)
				d = y;
			// 합칠 구간이 아예 포함되는 경우 -> 무시하면 됨 
			else if (s <= x && y <= d)
				continue;
		}
	}
	ans += ((d - s) * 2);
	cout << ans << endl;
	return 0;
}
