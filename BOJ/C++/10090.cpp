#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
vector <ll> arr;
// 펜윅트리는 세그먼트와 다르게 n으로 구현가능 (세그먼트는 통상적으로 4 * n 필요)
ll tree[1000001];
ll ans, n;
// 구간트리의 노드에는 나보다 큰 숫자의 출현 수를 기록 
// 이건 펜윅으로 구현, 세그먼트를 보려면 버블 소트 문제 참고 
ll sum(int pos)
{
	// 여기선 값이 1부터 n까지 들어오므로 굳이 ++ 할 필요 x
	ll ret = 0;
	while (pos > 0)
	{
		ret += tree[pos];
		// 다음 구간으로 가기 위해 최하위 비트를 지운다 
		pos &= (pos - 1);
	}
	return ret;
}
void update(ll pos, ll value)
{
	while (pos <= n)
	{
		tree[pos] += value;
		// 다음 구간으로 넘어가면서 갱신 
		// pos & -pos는 오른쪽에서 마지막 비트를 남기기 위해 사용 
		// 처음 pos부터 거꾸로 더하면서 올라가면서 갱신해줘야되는 구간들을 찾아간다 
		// 리프부터 루트까지 거슬러 올라간다고 생각하자 
		pos += (pos & -pos);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	ll temp;
	for (ll i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	ll idx;
	// sum(k)는 k까지 출현한 숫자들의 합 
	// 돌면서 나보다 작은 구간 [1, arr[i]]에 나보다 큰 수가 몇개 있는지 찾는다
	// 나보다 큰 수 개수 = sum(n) - sum(arr[i])   
	// 그동안 update를 하면서 나보다 작은 구간에 얼마나 수가 출현했는지 알 수 있기 때문 
	for (int i = 0; i < n; i++)
	{
		ans += (sum(n) - sum(arr[i]));
		update(arr[i], 1);
	}
	cout << ans << endl;
	return 0;
}
