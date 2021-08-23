#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
long long tree[2000008];
int n;
long long ans;
vector <pair <int, int >> arr;
// 하도 안풀려서 구글링함 
// 다시봐도 이해안되면 직접 구간 트리를 그려보기
// 나중에 펜윅 트리로도 풀어볼 것 

// 구간트리에 저장된 값 가져오기 
// 왜 이렇게 되는지 이해가 잘 안간다면 3 2 3 1 을 가지고 직접
// 그려보면서 어떤 구간이 더해지게 되는지 알아보자 
long long cnt(int start, int end, int left, int right, int node)
{
	if (left > end || right < start)
		return 0;
	int mid = (left + right) / 2;
	if (start <= left && right <= end)
	{
		return tree[node];
	}
	return cnt(start, end, left, mid, node * 2) + cnt(start, end, mid + 1, right, node * 2 + 1);
}
void update(int left, int right, int node, int value , int idx)
{
	// 말단 구간에서 출현수는 1일 수밖에 없다 
	if (left == right)
	{
		tree[node] = value;
		return;
	}
	int mid = (left + right) / 2;
	// 여기가 핵심   반으로 나눠가면서 현재 숫자 인덱스가 속한 구간만 업데이트 
	if (idx <= mid)
		update(left, mid, node * 2, value, idx);
	else 
		update(mid+1, right, node * 2+1, value, idx);
	// 자식들의 출현수를 더한 값 
	tree[node] = tree[2 * node] + tree[2 * node+1];
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int temp;
	// 숫자 값과 출현 위치를 pair로 같이 저장한다 
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back({ temp, i });
	}
	// 작은 숫자, 그리고 먼저 나온 숫자가 앞으로 오도록 sort 
	sort(arr.begin(), arr.end());
	int index;
	for (int i = 0; i < n; i++)
	{
		index = arr[i].second;
		// 나보다 뒤쪽을 봐야하므로 볼 구간은 index+1 ~ n-1까지 
		// 구간 트리에는 출현한 숫자의 수를 저장 
		ans += cnt(index+1,n-1, 0, n-1, 1);
		// 전체 구간 중에서 수가 출현했던 인덱스를 포함하는 구간만 갱신 
		update(0, n - 1, 1, 1, index);
	}
	cout << ans << endl;
	return 0;
}
