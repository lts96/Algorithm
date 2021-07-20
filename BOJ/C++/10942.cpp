#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int cache[2001][2001];
int arr[2001];
int n, m;
// 규칙만 찾아내면 의외로 간단했던 문제 
// dp table을 전부 갱신하는데 드는 시간 복잡도 = n * n  / 2 이므로 이중 for와 재귀로 가능
// 2차원 dp table 필요 (s ~ e 구간에 대한 정보를 담아야 하므로)
void print()
{
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << cache[i][j] << " ";
		cout << endl;
	}
	return;
}
int dp(int i, int j)
{
	if (i < 1 || j < 1 || i > n || j > n)
		return 0;
	if (cache[i][j] != -1)
		return cache[i][j];
	if (arr[i] == arr[j])
	{
		if (i == j + 1)
			return 1;
		// 나보다 작은 부분이 펠린드롬인지 확인해야됨 
		return cache[i][j] = dp(i + 1, j - 1);
	}
	// 제일 끝부분이 다르면 어차피 펠린드롬이 아니므로 재귀할 필요가 없음 
	else
		return cache[i][j] = 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int s,e;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cache[i][j] = 1;
			else
				cache[i][j] = -1;
		}
	}
	// n부터 미리 table을 채워나가면 콜 수가 줄어듬
	for (int i = n; i > 0; i--)
	{
		for (int j = n; j > 0; j--)
		{
			// s <= e 이므로 j < i는 볼 필요 없음 
			if (j <= i)
				continue;
			if (cache[i][j] != -1)
				continue;
			else
				dp(i, j);
		}
	}
	// 미리 dp table에 모든 구간에 대한 정보를 갱신해두고 찾기만 하면 끝
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		cout << cache[s][e] << "\n";
	}
	//print();
	return 0;
}
