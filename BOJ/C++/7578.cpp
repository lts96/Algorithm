#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
ll n, ans;
ll tree[1000001];
ll arr[1000001];
vector <ll> v;
// 문제가 복잡하지만 본질은 inverse counting 문제 
// 식별 숫자는 크게 의미는 없고 중요한건 나온 순서 
// 펜윅트리 구현하는 법 자세히 외워두기 -> 안쓰면 자꾸 까먹음
ll sum(int pos)
{
	ll ret = 0;
	while (pos >= 1)
	{
		ret += tree[pos];
		pos &= (pos - 1);
	}
	return ret;
}
void update(int pos, int value)
{
	while (pos <= n)
	{
		tree[pos] += value;
		pos += (pos & -pos);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	ll temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[temp] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		// 굳이 pair 할 필요 없음 
		// v에는 앞에서 나왔던 숫자가 지금 몇번째 v[i]에 있는지 저장되어있음 
		v.push_back(arr[temp]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		ans += (sum(n) - sum(v[i]));
		update(v[i], 1);
	}
	cout << ans << endl;
	return 0;
}
