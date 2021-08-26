#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
ll tree[500001];
vector <pair<int, int>> arr;
vector <ll> ans;
ll n;
// inverse counting과 좌표 압축 문제 
// 아직도 inverse counting에 대해 좀 헷갈림 -> 더 많이 풀어보기 
ll sum(int pos)
{
	ll ret = 0;
	while (pos > 0)
	{
		ret += tree[pos];
		pos &= (pos - 1);
	}
	return ret;
} 
void update(ll pos, ll value)
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	ll idx, temp;
	for (int i = 0; i < n; i++)
	{
		cin >> idx;
		arr.push_back({ idx, i + 1});
	}
	sort(arr.begin(), arr.end());
	vector <pair <ll, ll>> ans;
  // 좌표 압축하고 난 다음에 뒤에서부터 돌면서 나보다 앞 구간에서 나보다 실력이 좋은 사람 개수를 찾음 
  // 나보다 실력이 좋고 앞에 있다 -> 그만큼 예상 등수가 밀림 
  // 그리고 등수 조절을 위해서 + 1 
  // 쿼리 순서대로 출력해야 하므로 정답 배열에 넣고 정렬함 
	for (int i = arr.size()-1; i >= 0; i--)
	{
		idx = arr[i].second;
		temp = sum(idx) + 1;
		ans.push_back({ idx, temp });
		update(idx, 1);
	}
	sort(ans.begin(), ans.end());
	for (auto k : ans)
		cout << k.second << "\n";
	return 0;
}
