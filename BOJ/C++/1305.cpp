#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n , m , ans;
vector <int> pi;
void failure(string s)
{
	m = s.length();
	int j = 0;
	pi.assign(m,0);
	for (int i = 1; i < m; i++)
	{
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return;
}
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string s;
	cin >> s;
	failure(s);
	ans = s.length() - pi[m - 1];
	cout << ans << endl;
	return 0;
}