#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int test,n;
int prime[10001];
int main(void)
{
	cin >> test;
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = 1;
	}
	prime[1] = 0;
	for (int i = 2; (i*i) <= 10000; i++)   // 에라스토테네스의 체 기본형태 
	{
		if (prime[i])
		{
			for (int j = i * 2; j <= 10000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		int p1; int p2;
		for (int j = 2; j <= n/2; j++)
		{
			if (prime[j] == 1 && prime[n - j] == 1)
			{
				p1 = j;
				p2 = n - j;
			}
		}
		cout << p1 << " " << p2 << endl;
	}
	
	return 0; 
}