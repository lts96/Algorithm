#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
int ans, n, m;
list <int> q;
int d(bool flag)
{
	if (q.empty())
		return -1;
	if (flag)
		q.pop_front();
	else
		q.pop_back();
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test , n;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int temp = 0;
		bool flag = true;  // 정방향 역방향 체크용 
		string s1 , s2;
		cin >> s1 >> n >> s2;
		s2 = s2.substr(1, s2.size() - 2);
		istringstream iss(s2);
		string tok;
		while (getline(iss, tok, ','))
		{
			int j = stoi(tok);
			q.push_back(j);
		}

		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == 'R')
				flag = !flag;
			else if (s1[i] == 'D')
			    temp = d(flag);
		}
		if (temp == -1)
			cout << "error\n";
		else
		{
			string ans = "[";
			list<int>::iterator it;
			if (flag)
			{
				for (it = q.begin(); it != q.end(); it++)
				{
					ans += to_string(*it);
					ans += ",";
				}
			}
			else
			{
				q.reverse();
				for (it = q.begin(); it != q.end(); it++)
				{
					ans += to_string(*it);
					ans += ",";
				}
			}
			if (ans.size() >= 2)
				ans[ans.size() - 1] = ']';
			else
				ans += ']';
			cout << ans << "\n";
			while (!q.empty())
				q.pop_back();
		}
	}
	return 0;
}