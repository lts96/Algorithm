#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m;
int cycle[101]; 
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
	double a, b, ans ,weight ,x1 ,y1 , x2 , y2 , w;
	int x, y;
	double star[103][2];   // 좌표 저장용 
	vector < pair <double, pair <int, int>>> arr;
	ans = 0;
	cin >> n;
	for (int i = 0; i < 101; i++)
		cycle[i] = i;
	for (int i = 0; i < n; i++)  // 일단 좌표 저장
	{
		cin >> a >> b;
		star[i + 1][0] = a;
		star[i + 1][1] = b;
	}
	for (int i = 1; i <= n; i++) // 돌면서 간선 정보를 벡터에 저장
	{
		for (int j = i+1; j <= n; j++)
		{
			if (i != j)
			{
				x1 = star[i][0];
				y1 = star[i][1];
				x2 = star[j][0];
				y2 = star[j][1];
				weight = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
				arr.push_back(make_pair(weight, make_pair(i, j)));
			}
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) // 저장된 간선 정렬하고 작은 것부터 추출
	{
		w = arr[i].first;
		x = arr[i].second.first;
		y = arr[i].second.second;
		if (find(x) == find(y)) // x y 가 이미 그래프에 존재할 경우 사이클을 막기 위해서 pass
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