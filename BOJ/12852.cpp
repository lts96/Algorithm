#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;
int *cache;
int *arr;
int find_min(int a, int b, int c)
{
	if (a >= b && c >= b)
		return b;
	if (b >= c && a >= c)
		return c;
	if (c >= a && b >= a)
		return a;
}
int find_index(int x, int y, int z)
{
	int a = cache[x];
	int b = cache[y];
	int c = cache[z];
	if (a >= b && c >= b)
		return y;
	if (b >= c && a >= c)
		return z;
	if (c >= a && b >= a)
		return x;
}
int main(void)
{
	cin >> n;
	cache = (int *)malloc(sizeof(int)*(n + 1));
	arr = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i < n; i++)
	{
		cache[i] = 0;
		arr[i] = -1;
	}
	cache[2] = 1;
	cache[3] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (i % 6 == 0)
		{
			cache[i] = find_min(cache[i / 3], cache[i / 2], cache[i - 1]) + 1;
			arr[i] = find_index(i / 3, i / 2, i - 1);
		}
		else if (i % 3 == 0)
		{
			if (cache[i / 3] <= cache[i - 1])
			{
				cache[i] = cache[i / 3] + 1;
				arr[i] = i / 3;
			}
			else
			{
				cache[i] = cache[i - 1] + 1;
				arr[i] = i - 1;
			}

		}
		else if (i % 2 == 0)
		{
			if (cache[i / 2] <= cache[i - 1])
			{
				cache[i] = cache[i / 2] + 1;
				arr[i] = i / 2;
			}
			else
			{
				cache[i] = cache[i - 1] + 1;
				arr[i] = i - 1;
			}
		}
		else
		{
			cache[i] = cache[i - 1] + 1;
			arr[i] = i - 1;
		}
	}

	cout << cache[n] << "\n";
	int i = n;
	cout << i << " ";
	while (i != 1)
	{
		if (arr[i] != -1)
		{
			cout << arr[i] << " ";
			i = arr[i];
		}
	}
	//system("pause"); 
	return 0;
}