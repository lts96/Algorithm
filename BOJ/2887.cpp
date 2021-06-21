#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m , ans;
int cycle[100001];
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
	int x, y , z; 
	vector <pair <int, int>> xpos;   // 앞은 좌표 , 뒤는 연결된 노드 번호
	vector <pair <int, int>> ypos;
	vector <pair <int, int>> zpos;
	vector < pair <int, pair <int, int>>> arr;
	cin >> n;
	for (int i = 0; i < 100001; i++)
		cycle[i] = i;
	for (int i = 1; i <= n; i++)  // 일단 좌표 저장
	{
		cin >> x >> y >> z;
		xpos.push_back(make_pair(x, i));
		ypos.push_back(make_pair(y, i));
		zpos.push_back(make_pair(z, i));
	}
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	sort(zpos.begin(), zpos.end());
	int dx, dy, dz , index1 , index2 , value , w;
	for (int i = 0; i < n-1; i++)   // 간선을 찾는 과정 = n^2에서 kn으로 줄여보기
	{
		index1 = xpos[i].second , index2 = xpos[i+1].second;
		dx = abs(xpos[i].first - xpos[i+1].first);
		arr.push_back(make_pair(dx, make_pair(index1, index2)));
	}
	for (int i = 0; i < n-1; i++)
	{
		index1 = ypos[i].second, index2 = ypos[i + 1].second;
		dy = abs(ypos[i].first - ypos[i + 1].first);
		arr.push_back(make_pair(dy, make_pair(index1, index2)));
	}
	for (int i = 0; i < n-1; i++)
	{
		index1 = zpos[i].second, index2 = zpos[i + 1].second;
		dz = abs(zpos[i].first - zpos[i + 1].first);
		arr.push_back(make_pair(dz, make_pair(index1, index2)));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		w = arr[i].first;
		x = arr[i].second.first;
		y = arr[i].second.second;
		if (find(x) == find(y)) 
			continue;
		else
		{
			union_set(x, y);
			ans += w;
		}
	}
	cout << ans << endl;
	return 0;
}