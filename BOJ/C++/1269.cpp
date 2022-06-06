#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
int n, m, ans;
set <int> num;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int temp, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		num.insert(temp);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (num.find(temp) != num.end())
			cnt++;
	}
	cout << n + m - (cnt * 2) << "\n";
	return 0;
}
