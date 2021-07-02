#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
unsigned long long div_num = 1000000000; 
int n;
unsigned long long ans; 
unsigned long long num[10];

void stair_num(int count)
{
	unsigned long long cache[10] = {0};
	if (count == n)
	{
		return; 
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 0 )
		{
			cache[i+1]= (cache[i+1]+num[i])%div_num;
		}
		else if (i == 9)
		{
			cache[i - 1] = (cache[i - 1] + num[i]) % div_num;
		}
		else
		{
			cache[i + 1] = (cache[i + 1] + num[i]) % div_num;
			cache[i - 1] = (cache[i - 1] + num[i]) % div_num;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		num[i] = cache[i];
	}
	stair_num(count + 1);
}

int main(void)   // 값이 깨짐?
{
	cin >> n;
	for (int i = 1; i < 10; i++)
		num[i] = 1;
	num[0] = 0;
	stair_num(1);
	for (int i = 0; i < 10; i++)
	{
		ans = (ans+num[i]) % div_num;
	}
	cout << ans;
	//system("pause");
	return 0; 
}