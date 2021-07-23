#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m;
vector <string> arr;
int t[51];
int c[51];
int g[51];
int a[51];
// 그리디 문제 
// 가장 많이 나온 문자 위주로 dna 구성하면 됨 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr.push_back(s);
	}
	char ch;
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ch = arr[i][j];
			if (ch == 'T')
				t[j]++;
			else if (ch == 'A')
				a[j]++;
			else if (ch == 'G')
				g[j]++;
			else
				c[j]++;
		}
	}
	
	string dna = "";
	for (int i = 0; i < m; i++)
	{
		temp = max(max(a[i], c[i]), max(t[i], g[i]));
		if (a[i] == temp)
			dna += "A";
		else if (c[i] == temp)
			dna += "C";
		else if (g[i] == temp)
			dna += "G";
		else if (t[i] == temp)
			dna += "T";
	}
	cout << dna << "\n";
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dna[j] != arr[i][j])
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
