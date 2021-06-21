#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;
vector <pair <int , int>> v;
string arr[100001];
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n, index , age;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		index = i;
		v.push_back(make_pair(age, index));
		arr[index] = name;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << arr[v[i].second] << "\n";
	return 0;
}