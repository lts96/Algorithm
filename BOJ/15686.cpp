#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;
int n, m, ans = 999999;
bool* chicken;
int k;
int arr[50][50];
vector <pair<int, int>> h, c;

// k개의 치킨 집이 있다고 할때 k 중 m개 선택
bool* selected;  // 선택 기록 저장용

void dfs(int n , int r)
{
	if (r == m) // m개 선택 시 거리계산 
	{
		int dist_sum = 0;
		for (int i = 0; i < h.size(); i++)
		{
			int dist = 999999;
			for (int j = 0; j < c.size(); j++)
			{
				if(selected[j])  // 고른 여러개 치킨집들과의 거리중 최소 거리 1개만 찾아야함
					dist = min(dist, abs(h[i].first - c[j].first) + abs(h[i].second - c[j].second));
			}
			dist_sum += dist;
		}
		if (dist_sum < ans)
			ans = dist_sum;
		return;
	}
	if (n == c.size())  // 이거 먼저 넣으면 동시에 끝나는 경우 무시됨
		return; 
	selected[n] = true;  // 0부터 순서대로 가야됨 , r이 들어가면 m개 밖에 안가므로 틀림
	dfs(n + 1, r + 1);  // 지금꺼 골랐을때 
	selected[n] = false;
	dfs(n + 1, r);
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				k++;
				c.push_back(make_pair(i, j));
			}
			if (arr[i][j] == 1)
				h.push_back(make_pair(i, j));
		}
	}
	selected = new bool[k];
	for (int i = 0; i < k; i++)
		selected[i] = false;
	dfs(0,0);
	cout << ans << endl;
	return 0;
}