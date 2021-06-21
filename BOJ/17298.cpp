#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;
int n;
stack <int> s;
vector <int> arr, ans;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	reverse(arr.begin(), arr.end());
	int t;
	for (int i = 0; i < n; i++)
	{
		if (s.empty())
		{
			ans.push_back(-1);
			s.push(arr[i]);
		}
		else
		{
			t = s.top();
			if (arr[i] < t)
			{
				ans.push_back(t);
				s.push(arr[i]);
			}
			else
			{
				while (1)
				{
					s.pop();
					if (s.empty())
					{
						ans.push_back(-1);
						s.push(arr[i]);
						break;
					}
					if (arr[i] < s.top())
					{
						ans.push_back(s.top());
						s.push(arr[i]);
						break;
					}
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}

