#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, ans;
int cost_sum;
int cost[100];
int memory[100];
// 가격의 합을 index로 쓰고 해당 가격에서 최대한 메모리를 취하는 방식 
int cache[10001];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
		cost_sum += cost[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = cost_sum; j >= cost[i]; j--)
			cache[j] = max(cache[j - cost[i]] + memory[i], cache[j]);
	}
	for (int i = 0; i <= cost_sum; i++)
	{
		if (cache[i] >= m)
		{
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}