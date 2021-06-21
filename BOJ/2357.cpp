#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MIN 1000000001
#define SIZE 400008
using namespace std;
int n, m;
int arr[100001];
vector <int> minTree;
vector <int> maxTree;
int init1(int left , int right , int index)
{
	if (left == right)
		return minTree[index] = arr[left];
	int mid = (left + right) / 2;
	return minTree[index] = min(init1(left, mid, index * 2), init1(mid + 1, right, index * 2 + 1));
}
int init2(int left, int right, int index)
{
	if (left == right)
		return maxTree[index] = arr[left];
	int mid = (left + right) / 2;
	return maxTree[index] = max(init2(left, mid, index * 2), init2(mid + 1, right, index * 2 + 1));
}
int query1(int start, int end, int left, int right, int index)
{
	if (left > end || right < start)
		return MIN;
	if (start <= left && right <= end)
		return minTree[index];
	int mid = (left + right) / 2;
	return min(query1(start, end, left, mid, index * 2), query1(start, end, mid + 1, right, index * 2 + 1));
}
int query2(int start, int end, int left, int right, int index)
{
	if (left > end || right < start)
		return 0;
	if (start <= left && right <= end)
		return maxTree[index];
	int mid = (left + right) / 2;
	return max(query2(start, end, left, mid, index * 2), query2(start, end, mid + 1, right, index * 2 + 1));
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	minTree.assign(SIZE, MIN);
	maxTree.assign(SIZE, 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init1(1,n,1);
	init2(1, n, 1);
	int a, b , ans1 , ans2;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		ans1 = query1(a, b, 1, n, 1);
		ans2 = query2(a, b, 1, n, 1);
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}