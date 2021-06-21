#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
int dp[1003][1003];
int arr[1003];
int ans;
int n;
using namespace std;
// 틀렸던 이유 -> 항상 내가 먼저 시작해야되는데 turn의 시작을 n으로 
// 잡아서  n이 짝수면 명우부터 시작했음
int game(int turn, int l, int r) // l = left , r= right
{
	if (l == r)
	{
		if (turn)
			return arr[l];
		else
			return 0;
	}
	if (dp[l][r] != -1)
		return dp[l][r];
	if (turn)  // 내 차례
		return dp[l][r] = max(game(!turn, l, r - 1) + arr[r], game(!turn, l + 1, r) + arr[l]);
	else // 상대 차례
		return dp[l][r] = min(game(!turn, l, r - 1), game(!turn, l + 1, r));
}

int main()
{
	int test;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
					dp[i][j] = -1;
			}
		}
		
		ans = game(1, 1, n);  // 항상 나부터 시작해야됨
		/*
		for (int i = 1; i <= n; i++) // 틀린 이유 -> 내꺼만 봐야되는데 명우꺼도 같이 찾아서 최대 출력함
		{
			for (int j = 1; j <= n; j++)
				cout << dp[i][j] << " ";
				//ans = max(ans, dp[i][j]);
			cout << endl;
		}
		*/
		cout << ans << endl;
	}
}

