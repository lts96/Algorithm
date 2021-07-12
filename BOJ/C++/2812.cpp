#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
stack <int> s;

// 백준 크게 만들기 문제  프로그래머스에도 똑같은거 있음 
// 그리디 + 스택 
int main(void)
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string str, temp;
	cin >> str;
	int num,t, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		temp = str[i];
		num = stoi(temp);
		if (!s.empty())
		{
			while (!s.empty())
			{
				t = s.top();
				if (t < num && cnt < k)
				{
					s.pop();
					cnt++;
				}
				else if (t >= num || cnt >= k)
					break;
			}
			s.push(num);
		}
		else
			s.push(num);
	}
	if (cnt == k)
	{
		vector <int> ans;
		while (!s.empty())
		{
			ans.push_back(s.top());
			s.pop();
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << "\n";
	}
	else if (cnt < k)
	{
		vector <int> ans;
		while (!s.empty())
		{
			ans.push_back(s.top());
			s.pop();
		}
		reverse(ans.begin(), ans.end());
		// k개를 빼지 못했을 경우 따로 예외처리 
		for (int i = 0; i < ans.size() - (k-cnt); i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}
