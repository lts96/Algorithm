#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int arr[100001];
int cache[100001];
int n, ans = -200000000;
int main(void)
{
	bool flag = true;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cache[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= 0 && cache[i - 1] >= 0)  // 둘다 양수면 무조건 추가
		{
			if (flag)
				cache[i] = arr[i] + cache[i - 1];
			else
			{
				cache[i] = arr[i];
				flag = true;
			}
		}
		if (arr[i] < 0 && cache[i - 1] < 0)  // 둘다 음수면 무조건 큰 쪽
		{
			if (flag)
			{
				if (cache[i - 1] > arr[i])
				{
					cache[i] = cache[i - 1];
					flag = false;
				}
				else
				{
					cache[i] = arr[i];
					flag = true;
				}
			}
			else
			{
				cache[i] = arr[i];
				flag = true;
			}
		}
		if (arr[i] >= 0 && cache[i - 1] < 0)  // 무조건 새로 시작 
			cache[i] = arr[i];
		if (arr[i] < 0 && cache[i - 1] >= 0)
		{
			if (flag)  // 이전 것을 선택했는지 안했는지 체크용 (연속이 되나 안되나)
			{
				if (arr[i] + cache[i - 1] >= 0)
					cache[i] = arr[i] + cache[i - 1];
				else
				{
					cache[i] = cache[i - 1];
					flag = false;
				}
			}
			else  // 연속이 아닐 경우 
			{
				cache[i] = arr[i];
				flag = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans <= cache[i])
			ans = cache[i];
	}
	cout << ans << endl;
}