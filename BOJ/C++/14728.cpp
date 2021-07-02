#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int total,n, ans;
int time[100];
int score[100];
int cache[100][10001];
int dp(int t, int index)
{
	if (t <= 0 || index == n)
		return 0;
	if (cache[index][t] != 0)
		return cache[index][t];
	// 담았을때
	if (time[index] <= t)
		cache[index][t] = dp(t - time[index], index+1) + score[index];
	// 담지 않았을때
	cache[index][t] = max(cache[index][t], dp(t, index + 1));
	return cache[index][t];
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> total;
	for (int i = 0; i < n; i++)
		cin >> time[i] >> score[i];
	ans = dp(total,0);
	cout << ans << "\n";
	return 0;
}