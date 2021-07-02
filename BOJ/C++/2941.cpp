#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int ans;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int i = 0;
	int size = s.length()-1;
	while (i <= size)
	{
		if (s[i] == 'c') // c= c-
		{
			if (i + 1 <= size && (s[i + 1] == '=' || s[i + 1] == '-'))
				i++;
			ans++;
			i++;
			continue;
		}
		if (s[i] == 'l' || s[i] == 'n')  // lj  nj
		{
			if (i + 1 <= size && s[i + 1] == 'j')
				i++;
			ans++;
			i++;
			continue;
		}
		if (s[i] == 's' || s[i] == 'z')  // s= z=
		{
			if (i + 1 <= size && s[i + 1] == '=')
				i++;
			ans++;
			i++;
			continue;
		}
		if (s[i] == 'd')
		{
			if (i + 2 <= size && (s[i + 1] == 'z' && s[i + 2] == '='))
				i += 2;
			else if (i + 1 <= size && s[i + 1] == '-')
				i++;
			ans++;
			i++;
			continue;
		}
		ans++;
		i++;
	}
	cout << ans << "\n";
	return 0;
}