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
set <string> name;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	vector <string> v;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		name.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (name.find(s) != name.end())
			v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}
