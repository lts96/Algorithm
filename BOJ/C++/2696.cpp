#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
using namespace std;
#define MAX 10000
priority_queue <int, vector<int>, greater<int>> minheap;
priority_queue <int> maxheap;
int n;
/*
가운데를 말해요랑 똑같은 문제
최소힙 최대힙 2개를 사용해서 최대힙부터 작은 값을 넣으면 된다
예외 케이스 하나를 빼먹음
양쪽 힙의 크기가 같을때 이게 딱 가운데 값이면 무조건 최대힙에 넣을것
*/
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int test, input, cnt = 0;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n;
		cnt = 0;
		vector <int> ans;
		for (int i = 1; i <= n; i++)
		{
			cin >> input;
			if (maxheap.size() == minheap.size())
			{
				if (maxheap.empty())
					maxheap.push(input);
				else
				{
					if (input <= maxheap.top())
						maxheap.push(input);
					else
					{
						if (input <= minheap.top())
							maxheap.push(input);
						else
						{
							maxheap.push(minheap.top());
							minheap.pop();
							minheap.push(input);
						}
					}
				}
			}
			else if (maxheap.size() > minheap.size())
			{
				if (input >= maxheap.top())
					minheap.push(input);
				else
				{
					minheap.push(maxheap.top());
					maxheap.pop();
					maxheap.push(input);
				}
			}
			//cout << i << " : " << maxheap.top() << endl;
			if (i % 2 != 0)
				ans.push_back(maxheap.top());
		}
		cout << n / 2 + 1 << "\n";
		for (int i = 1; i <= ans.size(); i++)
		{
			if (i % 10 == 0 || i == ans.size())
				cout << ans[i - 1] << "\n";
			else
				cout << ans[i - 1] << " ";
		}
		while (!maxheap.empty())
			maxheap.pop();
		while (!minheap.empty())
			minheap.pop();
		ans.clear();
	}
	return 0;
}
