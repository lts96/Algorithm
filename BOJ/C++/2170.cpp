#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
stack <pair <int, int>> s;

// 스위핑 알고리즘 연습문제 
/*
반례 
4
5 10
15 20
25 30
7 35
답: 30
*/
// 하나의 선분이 아예 다른 선분 안에 포함되는 경우 처리를 잘못했었음, 고치니까 맞음
int main(void)
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,a,b;
	vector <pair <int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int s, d;
	s = v[0].first;
	d = v[0].second;
	if (n == 1)
	{
		cout << d - s << endl;
		return 0;
	}
	// s와 d는 이전 선분의 끝점 
	// v[i]는 현재 선분의 끝점 
	else   
	{
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			//cout << s << " " << d << endl;
			if (d >= v[i].first)
			{
				if(d <= v[i].second)
					d = v[i].second;
			}
			else
			{
				ans += (d - s);
				s = v[i].first;
				d = v[i].second;
			}
		}
		ans += (d - s);
		cout << ans << endl;
	}
	return 0;
}
