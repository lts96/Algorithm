#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int ans, n , m;
list <int> q;
void func1()
{
	q.pop_front();
	return;
}
void func2()
{
	int temp = q.front();
	q.pop_front();
	q.push_back(temp);
	ans++;
	return;
}
void func3()
{
	int temp = q.back();
	q.pop_back();
	q.push_front(temp);
	ans++;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int target , locate = 0;
	for (int i = 1; i <= n; i++)
		q.push_back(i);
	for (int i = 0; i < m; i++)
	{
		cin >> target;
		list<int>::iterator it;
		int temp = 0;
		for (it = q.begin(); it != q.end(); it++)
		{
			if (target == *it)
				locate = temp;
			temp++;
		}
		if (locate <= q.size() / 2)
		{
			while (q.front() != target)
				func2();
			func1();
		}
		else if (locate > q.size() / 2)
		{
			while (q.front() != target)
				func3();
			func1();
		}
		//cout <<locate << " : " <<  ans << endl;
	}
	cout << ans << endl;
	return 0;
}