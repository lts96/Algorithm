#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n , ans;
list<int> q;
void push(int temp)
{
	q.push_back(temp);
}
int pop()
{
	int r = q.front();
	q.pop_front();
	return r;
}
int size()
{
	return q.size();
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test , m , temp, target;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		ans = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			push(temp);
		}
		list<int> ::iterator it;
		while (m >= 0)
		{
			target = q.front();
			bool flag = true;
			for (it = q.begin(); it != q.end(); it++)
			{
				if ((*it) > target)
					flag = false;
			}
			if (!flag)  // 뒤로 보내기 
			{
				int a = pop();
				push(a);
				if (m == 0)
					m = q.size() - 1;
				else
					m--;
			}
			else  // 출력 
			{
				pop();
				ans++;
				if (m == 0)
					break;
				else
					m--;
			}
		}
		cout << ans << "\n";
		while (!q.empty())
			q.pop_back();
	}

	
	return 0;
}