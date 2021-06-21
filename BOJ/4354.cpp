#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m, ans = 1;
vector <int> pi;
int failure(string s)
{
	int m = s.length();
	int j = 0;
	int result = 0;
	pi.assign(m, 0);
	for (int i = 1; i < m; i++)
	{
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	result = pi.size() - pi[pi.size() - 1];
	return result;
}
void kmp(string t, string p)
{
	failure(p);
	int n = t.length(), m = p.length(), j = 0;
	double check = ((double)n / (double)m);
	double check2 = n / m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		while ((j > 0) && (t[i] != p[j]))
			j = pi[j - 1];
		if (t[i] == p[j])
		{
			if (j == m - 1)
			{
				cnt++;
				j = pi[j];
			}
			else
				j++;
		}
	}
	//cout << cnt << endl;
	if (cnt == check)
		ans = max(cnt, ans);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	string s = " ";
	int index;
	while (1)
	{
		ans = 0;
		cin >> s;
		if (!s.compare("."))
			break;
		index = failure(s);
		if (index == 0)
			ans = 1;
		else
		{
			string a = s.substr(0, index);
			//cout << a << endl;
			kmp(s, a);
		}
		if (ans == 0)
			ans++;
		cout << ans << endl;
	}
	return 0;
}