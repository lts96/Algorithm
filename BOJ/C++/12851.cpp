#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n, k, ans = 2100000000;
bool visit[100001];
int arr[100001];
queue <pair <int, int>> q;
vector <int> v;
void bfs()
{
	int x, time, next;
	while (!q.empty())
	{
		x = q.front().first;
		time = q.front().second;
		q.pop();
		if(x != k)
			visit[x] = true;
		else
		{
			if (ans >= time)
			{
				ans = time;
				v.push_back(ans);
			}
		}

		if (2 * x <= 100000 && !visit[2 * x] && x != 0)
			q.push(make_pair(2*x, time + 1));
		if (x-1 >= 0 && !visit[x - 1])
			q.push(make_pair(x-1, time + 1));
		if (x + 1 <= 100000 && !visit[x + 1])
			q.push(make_pair(x+1, time + 1));
			
	}
	return;
}
int main(void)
{
	cin >> n >> k;
	q.push(make_pair(n, 0));
	visit[n] = true;
	if (n == k)
	{
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}
	bfs();
	cout << ans << "\n";
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";
		if (ans == v[i])
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}