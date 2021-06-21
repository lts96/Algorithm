#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
unsigned long long dp[100];
int n;
unsigned long long fibonacci(int i)
{
	if (i < 1)
		return 0;
	if (dp[i] != 0)
		return dp[i];
	return dp[i] = fibonacci(i - 1) + fibonacci(i - 2);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	cout << fibonacci(n) << "\n";
	return 0;
}