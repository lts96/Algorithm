#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n, index;
list<int> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string s;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.compare("push_front") == 0)
		{
			cin >> temp;
			q.push_front(temp);
		}
		if (s.compare("push_back") == 0)
		{
			cin >> temp;
			q.push_back(temp);
		}
		else if (s.compare("pop_front") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (s.compare("pop_back") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		else if (s.compare("size") == 0)
			cout << q.size() << "\n";
		else if (s.compare("empty") == 0)
			cout << q.empty() << "\n";
		else if (s.compare("front") == 0)
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (s.compare("back") == 0)
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}

	}

	return 0;
}