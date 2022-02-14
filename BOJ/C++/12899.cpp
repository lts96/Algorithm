#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
#define MAX 2000001 * 4 + 10
int n , m = 2000000;
int tree[MAX];
int ans;
void update(int idx, int left, int right, int target, int value)
{
	// 내가 갱신하길 원하는 구간을 벗어날때
	if (target < left || target > right)
		return;
	// 개수를 하나 증가
	tree[idx] += value;
	// 리프노드가 아니라면 이어서 호출
	if (left != right)
	{
		update(idx * 2, left, (left + right) / 2, target, value);
		update(idx * 2 + 1, (left + right) / 2 + 1, right, target, value);
	}
}
int find(int idx, int left, int right, int k)
{
	// 리프노드면 자신을 리턴
	if (left == right)
		return left;
	// 왼쪽 자식이 k 이상일때는 그쪽으로 이동
	if (tree[idx * 2] >= k)
		return find(idx * 2, left, (left + right) / 2, k);
	// 이 부분이 중요 ! 왼쪽이 k 보다 작으면 오른쪽 구간을 탐색하는데
	// 이미 왼쪽은 k보다 적은 개수이므로 이걸 빼서 오른쪽에서 몇번째인지 찾는다
	else
		return find(idx * 2 + 1, (left + right) / 2 + 1,right, k - tree[idx * 2]);
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a == 1)
			update(1,1,m,b,1);
		else
		{
			ans = find(1, 1, m, b);
			cout << ans << "\n";
			update(1, 1, m, ans, -1);
		}
	}
	return 0;
}
