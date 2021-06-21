#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
bool num[10001];

void d(int n)
{
	int temp = 0;
	if (n < 10)
		temp = 2 * n;
	else if (n >= 10 && n < 100)
		temp = n + (n / 10) + (n % 10);
	else if (n >= 100 && n < 1000)
		temp = n + (n / 100) + (n / 10 % 10) + (n % 10);
	else if (n >= 1000 && n < 10000)
		temp = n + (n / 1000) + (n / 100 % 10) + (n / 10 % 10) + (n % 10);
	if(temp <= 10000)
		num[temp] = true;
	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	for (int i = 1; i <= 10000; i++)
		d(i);
	for (int i = 1; i <= 10000; i++)
	{
		if (!num[i])
			cout << i << "\n";
	}
	return 0;
}