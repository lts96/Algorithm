#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int ans;
int check(string s)
{
	bool alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = false;
	char temp = s[0];
	alpha[temp - 97] = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != temp)
		{
			temp = s[i];
			if (!alpha[temp - 97])
				alpha[temp - 97] = true;
			else
				return 0;
		}
	}
	return 1;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		ans += check(s);
	}
	cout << ans << endl;
	return 0;
}