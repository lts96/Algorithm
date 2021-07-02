#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int ans;
vector<int> pi;

void setPi(string s)
{
	int m = s.length() , j = 0;
	pi.assign(m, 0);
	for (int i = 1; i < m; i++)
	{
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
}

void kmp(string t, string p)  // 위 함수와 동일한 방식 사용 
{
	int n = t.length(), m = p.length() , j=0;
	setPi(p);
	for (int i = 0; i < n; i++)
	{
		while ((j > 0) && (t[i] != p[j]))
			j = pi[j - 1];
		if (t[i] == p[j])
		{
			if (j == m - 1)
			{
				ans++;
				return;
			}
			else
				j++;
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	kmp(s1, s2);
	cout << ans << endl;
	
	return 0;
}