#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 100001
typedef long long ll;
ll tree[MAX * 4 + 100];
ll arr[MAX + 10];
ll n, ans, m;

/*
구간 합 대신 저 k를 더한다고 생각하자
구간 트리에 구간별 k의 합계를 저장해두고 나중에 출력할때 하나하나 더해서 계산해내면 끝
*/

void init(ll index, ll left, ll right)
{
	if (left == right)
	{
		tree[index] = arr[left];
		return;
	}
	init(index * 2, left, (left + right) / 2);
	init(index * 2 + 1, (left + right) / 2 + 1, right);
	return;
}
void print(ll index, ll left, ll right, ll x, ll y, ll sum)
{
	if (y < left || right < x)
		return;
	else
	{
		sum += tree[index];
		if (x <= left && y >= right)
		{
			cout << sum << "\n";
			return;
		}
		print(index * 2, left, (left + right) / 2, x, y, sum);
		print(index * 2 + 1, (left + right) / 2 + 1, right, x, y, sum);
	}
	return;
}
void update(ll index, ll left, ll right, ll x, ll y, ll k)
{
	if (y < left || right < x)
		return;
	else
	{
		if (x <= left && y >= right)
		{
			tree[index] += k;
			return;
		}
		update(index * 2, left, (left + right) / 2, x, y,k);
		update(index * 2 + 1, (left + right) / 2 + 1, right, x, y,k);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll a, b, c, d;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	init(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c >> d;
			update(1,1,n, b,c,d);
		}
		else
		{
			print(1,1,n, b, b, 0);
		}
	}
	return 0;
}
