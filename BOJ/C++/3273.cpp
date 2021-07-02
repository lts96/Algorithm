#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector <int> arr;
	int temp, start = 0 , end = n-1, x;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> x;
	sort(arr.begin(), arr.end());
	while (start < n && start < end)
	{
		temp = arr[start] + arr[end];
		if (temp == x)
			ans++;
		else if(temp > x)
		{
			end--;
			continue;
		}
		start++;
	}
	cout << ans << "\n";
	return 0;
}
