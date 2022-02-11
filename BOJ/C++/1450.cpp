#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
ll n, c;
ll arr[31];
bool selected[31];
ll ans[2];
vector <ll> w[2];
/*
	반례 : 4 6 
	1 5 3 2
	정답 : 10
*/
// meet in the middle과 이분 탐색을 둘다 써서 해결 
// 경우를 앞과 뒤로 나눠서 각각 모든 경우의 수를 탐색
// 거기서 나온 무게를 벡터에 저장하고 합이 c이하가 되는 경우를 이분탐색으로 찾음
// 디버깅을 하는 과정이 아직 부족함, 반례를 찾거나 로직을 
void napsack(ll idx, ll sum, ll MAX, ll limit, ll pos)
{
	if (idx == MAX)
	{
		ans[pos]++;
		w[pos].push_back(sum);
		return;
	}
	if (sum + arr[idx] <= limit)
	{
		selected[idx] = true;
		napsack(idx + 1, sum + arr[idx], MAX, limit, pos);
	}
	selected[idx] = false;
	napsack(idx + 1, sum, MAX, limit, pos);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	// 각각의 범위에서 따로따로 무게를 구해서 벡터에 넣는다
	napsack(0, 0, n / 2, c, 0);
	napsack(n/2, 0, n, c, 1);
	sort(w[0].begin(), w[0].end());
	sort(w[1].begin(), w[1].end());
	ll idx, target, result = 0;
	// 그리고 벡터를 sort 한다음 두 개의 합이 c이하인 지점을 찾는다
	// 이분탐색 쓰면 nlogn 가능
	
	for (int i = 0; i < w[0].size(); i++)
	{
		target = c - w[0][i];
		idx = upper_bound(w[1].begin(), w[1].end(), target) - w[1].begin();
		result += idx;
	}
	cout << result << "\n";
	return 0;
}
