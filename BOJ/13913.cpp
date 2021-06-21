#include <iostream>
#include <stdlib.h> 
#include <queue>
#include <utility>
using namespace std;
int n, k, ans;
bool visit[100001];
int p[100001];
queue <pair <pair <int, int> , int >>  q;
vector<int> num;
void bfs()
{
	int x, time , prev;
	while (!q.empty())
	{
		x = q.front().first.first;
		time = q.front().first.second;
		prev = q.front().second;
		if(p[x] == -1)
			p[x] = prev;
		visit[x] = true;
		if (x == k)
		{
			ans = time;
			return;
		}
		else
		{
			if (x > k)
			{
				if (visit[x - 1] == false)
				{
					q.push(make_pair(make_pair(x - 1, time + 1) , x));
				}
			}
			else if (x < k)
			{
				if (((k - x >= x * 2 - k) && x != 0) && x * 2 <= 100000)
				{
					if (visit[x * 2] == false)
					{
						q.push(make_pair(make_pair(x * 2, time + 1), x));
					}
				}
				if (x + 1 <= k)
				{
					if (visit[x + 1] == false)
					{
						q.push(make_pair(make_pair(x + 1, time + 1), x));
					}
				}
				if (x - 1 >= 0)
				{
					if (visit[x - 1] == false)
					{
						q.push(make_pair(make_pair(x - 1, time + 1), x));
					}
				}
			}
		}
		q.pop();
	}
}
void trace(int n)
{
	if (n == -1)
		return;
	num.push_back(n);
	trace(p[n]);
	return;
}
int main(void)
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < 100001; i++)
		p[i] = -1;
	q.push(make_pair(make_pair(n, 0), -1));
	p[n] = -1;
	bfs();
	trace(k);
	cout << ans << endl;
	for (int i = num.size()-1; i >= 0; i--)
		cout << num[i] << " ";
	return 0;
}