#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int arr[3001];
int cnt[3001];
int line[3001][4];
typedef long long ll;
int n;
/*
반례 
2 2 3 3
1 1 4 4
1 
2
*/
// n이 3000이라 2중 for문 돌면서 교차하면 유니온 파인드로 합치면 되는 문제 
// 이전에 선분 교차를 잘 구현했다면 여기에 유니온 파인드만 추가하면 끝이었다. 
int find(int i)
{
	if (arr[i] == i)
		return i;
	return arr[i] = find(arr[i]);
}
void union_set(int a,int b)
{
	int root1 = find(a);
	int root2 = find(b);
	if (root1 == root2)
		return;
	else
	{
		arr[root2] = root1;
		return;
	}
}
ll ccw(ll s)
{
	long long temp;
	if (s > 0) // 반시계 
		temp = 1;
	else if (s == 0) // 평행
		temp = 0;
	else if (s < 0) // 시계
		temp = -1;
	return temp;
}
bool cross(ll x1,ll y1, ll x2,ll y2,ll x3,ll y3, ll x4, ll y4)
{
	// ccw (a,b,c)
	ll s1 = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);
	// ccw (a,b,d)
	ll s2 = (x1 * y2 + x2 * y4 + x4 * y1) - (x1 * y4 + x4 * y2 + x2 * y1);
	// ccw (c,d,a)
	ll s3 = (x3 * y4 + x4 * y1 + x1 * y3) - (x3 * y1 + x1 * y4 + x4 * y3);
	// ccw (c,d,b)
	ll s4 = (x3 * y4 + x4 * y2 + x2 * y3) - (x3 * y2 + x2 * y4 + x4 * y3);
	s1 = ccw(s1);
	s2 = ccw(s2);
	s3 = ccw(s3);
	s4 = ccw(s4);
	if (s1 * s2 == 0 && s3 * s4 == 0)
	{
		// pair를 안쓰면 y축에 일직선일때랑 x축에 일직선일때 따로 처리해야된다
		pair<int, int> a = make_pair(x1, y1);
		pair<int, int> b = make_pair(x2, y2);
		pair<int, int> c = make_pair(x3, y3);
		pair<int, int> d = make_pair(x4, y4);
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		if (a <= d && c <= b)
			return true;
		else
			return false;
	}
	// 교차할때 
	if (s1 * s2 <= 0 && s3 * s4 <= 0)
		return true;
	else
		return false;
}
// ccw 해서 교차하면 같은 집합에 넣고 아니면 계속 
// 이중 for문 돌려서 모든 선분에 대해서 실행 
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	bool flag;
	for (int i = 1; i <= n; i++)
	{
		cin >> line[i][0] >> line[i][1] >> line[i][2] >> line[i][3];
		arr[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			// 이미 같은 집합이면 pass
			if (find(i) == find(j))
				continue;
			else
			{
				flag = cross(line[i][0], line[i][1], line[i][2], line[i][3], line[j][0], line[j][1], line[j][2], line[j][3]);
				if (flag)
					union_set(i, j);
			}
		}
	}
	int root, ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++)
	{
		root = find(i);
		cnt[root]++;
	}
	for (int i = 1; i <= n; i++)
	{
		//cout << arr[i] << " ";
		ans2 = max(ans2, cnt[i]);
		if (cnt[i])
			ans1++;
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
