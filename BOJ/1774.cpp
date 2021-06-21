#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m;
int cycle[1001];
bool connect[1001][1001];
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
	//ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	double a, b, ans = 0 ,weight ,x1 ,y1 , x2 , y2 , w;
	int x, y;
	double god[1003][2];   // 좌표 저장용 
	vector < pair <double, pair <int, int>>> arr;
	cin >> n >> m;
	for (int i = 0; i < 1001; i++)
		cycle[i] = i;
	for (int i = 0; i < n; i++)  // 일단 좌표 저장
	{
		cin >> a >> b;
		god[i + 1][0] = a;
		god[i + 1][1] = b;
	}
	for (int i = 0; i < m; i++) // 이미 만들어진 통로는 다시 만들 필요 x -> 비용 안들어감
	{
		cin >> x >> y;
		connect[x][y] = true;  // 이미 연결된 간선을 또 넣지 않기 위해
		union_set(x, y); // 이미 연결된 정점을 다시 연결하지 않기 위해
	}
	for (int i = 1; i <= n; i++) 
	{
		for (int j = i+1; j <= n; j++)
		{
			if ((i != j) && (connect[i][j] == false)) // 이미 연결된 통로는 제외
			{
				x1 = god[i][0];
				y1 = god[i][1];
				x2 = god[j][0];
				y2 = god[j][1];
				weight = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
				arr.push_back(make_pair(weight, make_pair(i, j)));
			}
		}
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
	printf("%.2f\n", ans);
	return 0;
}