#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n , a, b;
string ans;
queue <pair <int, string>> q;
bool visit[10000];
int d(int n)
{
	if (n * 2 <= 9999)
		return n * 2;
	else
		return n * 2 % 10000;
}
int s(int n)
{
	if (n == 0)
		return 9999;
	else
		return n - 1;
}
int l(int n)
{
	int temp = n / 1000;
	return (n % 1000) * 10 + temp;
}
int r(int n)
{
	int temp = n % 10 * 1000;
	return temp + (n / 10);
}
void bfs()
{
	int x , x1 , x2 , x3 , x4;
	string str;
	while (!q.empty())
	{
		x = q.front().first;
		str = q.front().second;
		q.pop();
		if (visit[x])
			continue;
		visit[x] = true;
		x1 = d(x);
		if (x1 == b)   // 넣을때 답을 찾으면 depth 1단계 축소 가능
		{
			ans = str + "D";
			return;
		}
		if(!visit[x1])
			q.push(make_pair(x1, str + "D"));
		x2 = s(x);
		if (x2 == b)
		{
			ans = str + "S";
			return;
		}
		if (!visit[x2])
			q.push(make_pair(x2, str + "S"));
		x3 = l(x);
		if (x3 == b)
		{
			ans = str + "L";
			return;
		}
		if (!visit[x3])
			q.push(make_pair(x3, str + "L"));
		x4 = r(x);
		if (x4 == b)
		{
			ans = str + "R";
			return;
		}
		if (!visit[x4])
			q.push(make_pair(x4, str + "R"));
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		for (int i = 0; i < 10000; i++)
			visit[i] = false;
		ans.clear();
		cin >> a >> b;
		q.push(make_pair(a, ""));
		bfs();
		cout << ans << "\n";
		while (!q.empty())
			q.pop();
	}
	return 0;
}