#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int n;
vector <pair <int, int >> p ,v;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a; 
		p.push_back(make_pair(a, i));
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++)
		v.push_back(make_pair(p[i].second, i));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << " ";
	return 0;
}
