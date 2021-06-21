#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
int n;
int *cache;
int find_min(int a, int b, int c)
{
	if (a >= b && c >= b)
		return b; 
	if (b >= c && a >= c)
		return c; 
	if (c >= a && b >= a)
		return a; 
}
int main(void)
{
	cin >> n;
	cache = (int *)malloc(sizeof(int)*(n+1));
	for (int i = 0; i < n; i++)
	{
		cache[i] = 0;		
	}
	cache[2] = 1;  // n= 2 일때 
	cache[3] = 1;  // n= 3 일때 

	for (int i = 2; i <= n; i++) //cache[i] 번째의 값은 cache[i/2] ,i/3 , i-1 중 하나 , 결국 피보나치와 같다.
	{
		if (i % 6 == 0)
		{
			cache[i] = find_min(cache[i / 3], cache[i / 2], cache[i - 1])+1;
		}
		else if (i % 3 == 0)
		{
			cache[i] = min(cache[i / 3], cache[i - 1])+1;
		}
		else if (i % 2 == 0)
		{
			cache[i] = min(cache[i / 2], cache[i - 1])+1;
		}
		else 
		{
			cache[i] = cache[i - 1] + 1;
		}
	}

	cout << cache[n];
	//system("pause"); 
	return 0; 
}