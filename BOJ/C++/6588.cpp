#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
int n, k , cnt;
int p , ans;
bool prime[1000001];
void print(int a, int b)
{
	cout << a + b << " = " << a << " + " << b << "\n";
}
int main()
{

	int input = 1;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 1000003; i++)
	{
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	for (int i = 2; (i*i) <= 1000000; i++)
	{
		for (int j = i * 2; j <= 1000000; j += i)
		{
			prime[j] = false;
		}
	}
	prime[2] = false;

	while (1)
	{
		cin >> input;
		if (input == 0)
			break;
		bool flag = false;
		for (int i = 3; i < 1000000; i++)
		{
			int a = prime[i];
			if (a && prime[input - i])
			{
				print(i, input - i);
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}