#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;
vector <pair <int , string>> v;
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , length;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		length = s.size();
		v.push_back(make_pair(length, s));
	}
	sort(v.begin(), v.end());
	string check = "1";
	for (int i = 0; i < n; i++)
	{
		if(check.compare(v[i].second))
			cout << v[i].second << "\n";
		check = v[i].second;
	}
	return 0;
}