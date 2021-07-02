#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n , min_ans = 2100000000 , max_ans = -2100000000;
int num[11];
int arr[4];  // 각 연산자 개수 + - * /
void dfs(int cnt, int value)
{
	if (cnt == n)
	{
		if (value >= max_ans)
			max_ans = value;
		if (value <= min_ans)
			min_ans = value;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[i] == 0) // 사용할 연산자 개수가 없으면 pass
				continue;
			arr[i]--;  // 특정 연산자 사용
			if (i == 0)
			{
				dfs(cnt + 1, value + num[cnt]);
			}
			else if (i == 1)
			{
				dfs(cnt + 1, value - num[cnt]);
			}
			else if (i == 2)
			{
				dfs(cnt + 1, value * num[cnt]);
			}
			else
			{
				dfs(cnt + 1 , value / num[cnt]);
			}
			arr[i]++;  // 사용하기 전으로 돌아감
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	dfs(1, num[0]);
	cout << max_ans << "\n" << min_ans << endl;
	return 0;
}