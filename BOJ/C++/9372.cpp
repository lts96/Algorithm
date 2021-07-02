#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m;
int cycle[1001];  // 유니온 파인드 이용해서 사이클 체크 
// 이미 연결된 상태면 pass 하는 방식 (i != cycle[i])
int find(int i)
{
	if (i == cycle[i])
		return i;
	return cycle[i] = find(cycle[i]);
}
void union_set(int a, int b)
{
	int root1 = find(a), root2 = find(b);
	if (root1 == root2)
		return;
	cycle[root2] = root1;
	return;
}
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int test , a, b , ans ,x, y;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		vector <pair <int, int>> v;
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < 1001; i++)
			cycle[i] = i;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
			// 이 문제에선 가중치가 동일 -> 전부 1로 설정 
		}
		//sort(v.begin(), v.end());  // 가중치가 같아서 사실 안해도됨
		for (int i = 0; i < v.size(); i++)
		{
			x = v[i].first;
			y = v[i].second;
			if (find(x) == find(y)) // x y 가 이미 그래프에 존재할 경우 사이클을 막기 위해서 pass
				continue;
			else
			{
				union_set(x, y);
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}