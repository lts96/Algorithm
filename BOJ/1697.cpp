#include <iostream>
#include <stdlib.h> 
#include <queue>
#include <utility>
using namespace std; 
int n, k, ans;
bool visit[100001];
queue <pair <int , int>>  q; 

void bfs()
{
	int x, time;
	while (!q.empty())
	{
		x = q.front().first;
		time = q.front().second;
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
				if(visit[x-1]==false)
				q.push(make_pair(x - 1, time + 1));
			}
			else if (x < k)
			{
				if ((( k - x >= x* 2 - k) && x!= 0 )&&x*2<=100000)
				{
					if (visit[x * 2] == false)
					q.push(make_pair(x * 2, time + 1));
				}
				if (x + 1 <= k)
				{
					if (visit[x + 1] == false)
					q.push(make_pair(x + 1, time + 1));
				}
				if (x - 1 >= 0)
				{
					if (visit[x - 1] == false)
					q.push(make_pair(x-1, time+1));
				}
			}
		}
		q.pop();
	}
}
int main(void)
{
	cin >> n; 
	cin >> k;
	q.push(make_pair(n,0));
	bfs();
	cout << ans << endl; 
	//system("pause");
	return 0; 
}