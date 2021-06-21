#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define mod 1000000007
using namespace std;
int n, m, k;
int arr[1000002];
long long tree[5000008];  // 이진 트리로 구현
// 왜 tree의 크기가 4*n 일까?
long long init(int index, int left, int right)
{
	if (left == right)    // 1개 구간만 커버하는건 리프노드 
		return tree[index] = arr[left] % mod;
	int mid = (left + right) / 2;
	return tree[index] = (init(index * 2, left, mid) * init(index * 2 + 1, mid + 1, right)) % mod;
}
long long multiple(int tl, int tr, int left, int right, int index)
{
	// tl = target left , tr = target right
	if ((left > tr) || (right < tl))  // 정해진 구간을 벗어났을때
		return 1;  // 곱의 항등원 =1 
	if ((tl <= left) && (right <= tr))  // 구간에 속할때
		return tree[index];
	int mid = (left + right) / 2;
	return (multiple(tl, tr, left, mid, index * 2) * multiple(tl, tr, mid + 1, right, index * 2 + 1)) % mod;
}
// 이진 트리라서 자식의 인덱스는 2^n 꼴 + 완전 이진트리가 아니라서 자식부터 올라갈수 없음 
// 루트부터 구간 맞는 자식을 찾아나가야한다. 
long long update(int left, int right, int index, int target, long long value)
{
	if ((target < left) || (target > right))
		return tree[index];
	if (left == right) // 리프노드일때
		return tree[index] = value;
	int mid = (left + right) / 2;
	long long l1, l2;
	l1 = update(left, mid, index * 2, target, value);
	l2 = update(mid + 1, right, index * 2 + 1, target, value);
	return tree[index] = (l1 * l2) % mod;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < 5000008; i++)
		tree[i] = 1;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	m += k;
	init(1, 1, n);  // root는 index = 1 로 지정 , 1부터 n까지 구간  
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, n, 1, b, c);  
			arr[b] = c;
		}
		else
			cout << multiple(b, c, 1, n, 1) % mod << "\n";
	}
	return 0;
}