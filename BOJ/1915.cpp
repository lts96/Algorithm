#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int n, m;
unsigned long long ans;
int** arr;
int** cache;
// 백준 1915      중요 사항  현재 내 arr 값이 0 이면 cache 가 0이어야 함 
// 안그러면 나오는 반례   
// 3 3
// 111
// 100
// 101

int findMin(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else if (c <= b && c <= a)
		return c;
}

int main(void)
{
	cin >> n >> m;
	arr = new int* [n];
	cache = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		cache[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
			cache[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if ((cache[i - 1][j - 1] == cache[i][j - 1]) && (cache[i-1][j - 1] == cache[i - 1][j]))  // 다 같을때
			{
				if (arr[i][j] == 1) // 현재 지점이 1일때
				{
					cache[i][j] = cache[i - 1][j - 1] + 1;
				}
			}
			else // 3개의 값이 다 같지는 않을때 -> 정사각형 x    현재 내가 0이면 내 위치에서 만들 수 있는 정사각형은 0
			{
				if (arr[i][j] == 1)
				{
					cache[i][j] = min(min(cache[i-1][j-1] , cache[i][j-1]), cache[i-1][j])+ 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ans < cache[i][j])
				ans = cache[i][j];
		}
	}

	cout << ans * ans << endl;
	return 0;
}