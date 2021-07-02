#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
long long arr[1000001];  
long long tree[4000002];
vector<long long> ans;
long long n, m, k;

long long init(long long index , long long left , long long right)
{
	if (left == right) // 커버해야되는 범위가 동일 -> 리프노드라는 의미 
		return tree[index] = arr[left];
	else
		return tree[index] = init(index * 2, left, (left + right) / 2) + init(index * 2 + 1, (left + right) / 2 + 1 , right);
}
void update(long long index , long long left , long long right , long long target , long long value)
{
	if (target < left || target > right)  // target이 범위 밖이면 바로 종료
		return;
	tree[index] += value;     // 어차피 구간 합은 전부 update 해줘야하므로 +
	if (left != right)  // 리프노드가 아니라면 계속 재귀 호출 
	{
		update(index * 2, left, (left + right) / 2, target, value);
		update(index * 2 + 1, (left + right) / 2+1, right, target, value);
	}
}
long long sum(long long index , long long left , long long right , long long x, long long y)
{
	if (y < left || right < x)
		return 0; 
	else
	{
		if (x <= left && y >= right)
			return tree[index];
		return sum(index * 2,left, (left+right)/2 ,x,y) + sum(index * 2 + 1, (left + right) / 2+1, right, x, y);
	}
}

int main()
{
	long long cmd , b , c;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);
	m += k;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd >> b >> c;
		if (cmd == 1)
		{
			update(1, 1, n, b, c - arr[b]);   //여기를 바꿔야되는 이유 -> 이미 구간들에는 arr[b]가 더해진 상태라서 
			// c를 그대로 더하면 arr[b]만큼 중복됨 
			arr[b] =c;  // 없으면 틀림  
			// 왜?? -> update 를 하고 이걸 안해주면 arr[b]가 그대로 유지되면서 
			// 다음 c - arr[b]가 틀리게 됨
		}
		else
			cout << sum(1,1,n,b,c) << "\n";
	}
	return 0;
}