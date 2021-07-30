#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
int n, ans;
vector <pair <int, int>> arr;
int day[10001];
/*
6퍼에서 틀림 , n = 0인 경우도 일단 고려해둘것
계속 틀렸던 이유 -> d일에 해달라는게 아니라 d일 전까지만 해주면 되는거
d = 10이어도 첫날에 해도 된다는 것
가치가 크고 day가 큰 순으로 정렬한다음 n^2 돌면서 내 가치보다 가장 작은 위치에 강연을 하면 됨
*/
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n == 0)
	{
		cout << ans << endl;
		return 0;
	}
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a,b));
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	int d, p, idx = 10000, mp, md, k;
	for (int i = 0; i < arr.size(); i++)
	{
		d = arr[i].second;
		mp = p = arr[i].first;
		md = -1;
		idx = d;
		for (int j = d; j >= 1; j--)
		{
			if (day[j] == 0)
			{
				md = j;
				break;
			}
			else if (mp >= day[j])
			{
				mp = day[j];
				md = j;
			}
		}
		//cout << md << " " << p << endl;
		if (md != -1)
			day[md] = p;
		else
			continue;
	}
	for (int i = 1; i <= 10000; i++)
		ans += day[i];
	cout << ans << endl;
	return 0;
}
