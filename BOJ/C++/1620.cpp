#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
using namespace std;
int n, m, ans;
map <string, int> dict;
string key[100003];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		dict.insert({ s, i });
		key[i] = s;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> s;
		bool num = false;
		for (int j = 0; j < s.size(); j++)
		{
			if (isalpha(s[j]) == 0)
			{
				num = true;
				break;
			}
		}
		if (num)
		{
			int idx = stoi(s);
			cout << key[idx] << "\n";
		}
		else
			cout << dict.find(s)->second << "\n";
	}
	return 0;
}
