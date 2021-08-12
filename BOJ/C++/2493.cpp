#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
#include <stack>
using namespace std;
int n;
// 스택으로 푸는 간단한 문제 -> 아이디어만 떠올리면 쉬움 
vector <pair <int, int>> arr;
stack <pair <int, int>> s;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int input;
	vector <int> ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back({input, i+1});
	}
	bool find;
	for (int i = 0; i < arr.size(); i++)
	{
		find = false;
		if (s.empty())
		{
			s.push(arr[i]);
			continue;
		}
		while (!s.empty())
		{
			if (s.top().first >= arr[i].first)
			{
				ans[i] = s.top().second;
				find = true;
				break;
			}
			s.pop();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
