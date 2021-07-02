#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector <pair <int, int>> v;
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (pair<int, int> p : v)  // 범위 기반 for 문   (v의 요소 타입 : for문 대상 v) 
		cout << p.first << " " << p.second << "\n";
	return 0;
}