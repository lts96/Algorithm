#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
priority_queue <int, vector <int>, greater<int>> q;
// 그리디 문제 
// 우선순위큐 써서 작은거부터 먼저 합치면 된다
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, temp , ans = 0,a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);
	}
	while (!q.empty())
	{
		if (q.size() <= 1)
			break;
		else
		{
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			ans += (a + b);
			q.push(a + b);
		}
	}
	cout << ans << endl;
	return 0;
}
