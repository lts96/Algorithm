#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
vector<pair <string, double>> v;

/*
백준 4358번 생태학
입출력 받는게 까다로웠던 문제
그거 말곤 그냥 맵써서 각 원소 별로 카운팅하고 나눠주면 끝
*/
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double n = 0;
	double temp;
	string s = "a";
	while (true) 
	{
		getline(cin, s, '\n');
		if (s == "")
			break;
		if (m.count(s) == 0)
			m.insert(make_pair(s, 1));
		else
			m[s]++;
		n++;
	}
	cout << fixed;
	cout.precision(4);
	double d;
	for(auto it = m.begin(); it != m.end(); it++)
	{
		
		d = (it->second / n) * 100.0;
		cout << it->first << " "  << d << '\n';
	}
	return 0;
}
