#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int k;
priority_queue<pair<int, int>> maxheap;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
bool visit[1000001];
// pair 앞은 값 , 뒤가 index
// pair인 경우 앞을 기준으로 소팅하므로 값이 먼저 와야됨 
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, v;
	cin >> test;
	char c;
	for (int t = 0; t < test; t++)
	{
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> c >> v;
			if (c == 'D')
			{
				if (v == 1)
				{
					// 이미 다른 큐에서 나갔던 놈인데 아직 있는 경우
					while (!maxheap.empty() && !visit[maxheap.top().second])
						maxheap.pop();
					if (!maxheap.empty()) // 현재 나가야 될 놈 pop
					{
						visit[maxheap.top().second] = false;
						maxheap.pop();
					}
				}
				else
				{
					while (!minheap.empty() && !visit[minheap.top().second])
						minheap.pop();
					if (!minheap.empty())
					{
						visit[minheap.top().second] = false;
						minheap.pop();
					}
				}
			}
			else
			{
				// 들어왔다고 표시 
				visit[i] = true;
				minheap.push(make_pair(v,i));
				maxheap.push(make_pair(v, i));
			}
		}
		// 마지막까지 이상한 놈 있는지 확인해줘야됨 
		while (!maxheap.empty() && !visit[maxheap.top().second])
			maxheap.pop();
		while (!minheap.empty() && !visit[minheap.top().second])
			minheap.pop();

		if (minheap.size()==0 && maxheap.size()==0)
			cout << "EMPTY\n";
		else
			cout << maxheap.top().first << " " << minheap.top().first << "\n";
		
		while (!maxheap.empty())
			maxheap.pop();
		while (!minheap.empty())
			minheap.pop();
		for (int i = 0; i < 1000001; i++)
			visit[i] = false;
	}
	return 0;
}