#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
// 백트래킹 문제, 수열 조건을 만족하는지 확인하면서 만족하면 다음 depth로 진행
int n;
int selected[83];
bool backtracking(int idx)
{
	bool flag = false;
	if (idx == n)
	{
		for (int i = 0; i < n; i++)
			cout << selected[i];
		return true;
	}
	if (idx == 0)
	{
		for (int i = 1; i <= 3; i++)
		{
			selected[idx] = i;
			flag = backtracking(idx + 1);
			if (flag)
				break;
		}
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			bool check = false;
			if (i == selected[idx - 1])
				continue;
			selected[idx] = i;
			if (idx >= 3)
			{
				for (int k = 2; k <= (idx + 1) / 2; k++)
				{
					check = false;
					for (int j = 0; j < k; j++)
					{
						if (selected[idx - k - j] != selected[idx - j])
							check = true;
					}
					if (check != true)
						break;
				}
			}
			else
				check = true;
			if(check)
				flag = backtracking(idx + 1);
			if (flag)
				break;
		}
	}
	return flag;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	backtracking(0);
	return 0;
}
