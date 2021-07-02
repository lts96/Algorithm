#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
vector <pair<int, int>> ans;
vector <pair<int, int >> arr;
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(make_pair(temp, i));
	}
	sort(arr.begin(), arr.end());
	int idx = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i > 0)
		{
			if (arr[i].first == arr[i - 1].first)
				ans.push_back(make_pair(arr[i].second, idx));
			else
				ans.push_back(make_pair(arr[i].second, ++idx));
		}
		else
			ans.push_back(make_pair(arr[i].second, 0));
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].second << " ";
	cout << "\n";
	return 0;
}