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
set <string> word;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s , sub;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sub = s.substr(i, j);
			//cout << sub << endl;
			if (sub.size() != 0  && word.find(sub) == word.end())
				word.insert(sub);
		}
	}
	cout << word.size() << "\n";
	return 0;
}
