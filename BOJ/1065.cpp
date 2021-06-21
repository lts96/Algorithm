#include <iostream>
#include <stdlib.h>
using namespace std; 
int n;
int ans;
int main(void)
{
	int a, b, c;
	cin >> n;

	if (n <= 99)
		ans = n;
	else if(n>=100&&n<=1000)
	{
		ans = ans + 99;
		for (int i = 100; i <= n; i++)
		{
			a = i / 100;
			b = i / 10 % 10;
			c = i % 10;
			if ((a - b) == (b - c))
			{
				ans++;
			}
		}
	}
	cout << ans;
	//system("pause");
	return 0;
}