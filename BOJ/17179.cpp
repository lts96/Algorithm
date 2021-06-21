#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
int n, m , l , ans = -1;
int * arr , *cut;
using namespace std;
// 2110 문제와 판박이 -> 가장 작은 조각 = 가장 인접한 공유기 거리 
int main(void)
{
	cin >> n >> m >> l;
	arr = new int[m+2];
	cut = new int[n];
	for (int i = 1; i < m+1; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		cin >> cut[i];
	arr[0] = 0;
	arr[m + 1] = l;
	sort(arr, arr + m);
	for (int test = 0; test < n; test++)
	{
		ans = -1;
		int c = cut[test];
		int left = 1, right = l, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			int index = 0, count = -1;
			for (int i = 1; i < m+2; i++)
			{
				if (arr[i] - arr[index] >= mid)
				{
					count++;
					index = i;
				}
			}
			if (count >= c)
			{
				left = mid + 1;
				if (ans < mid)
					ans = mid;
			}
			else
				right = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}