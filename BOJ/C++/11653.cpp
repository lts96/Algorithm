#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp;
	cin >> n;
	// 어차피 순서대로 가도 합성수로 나누기 전에 소수로 나누면서 걸러진다 
	temp = n;
	for (int i = 2; (i*i) <= temp; i++)
	{
		while (!(n % i))
		{
			n /= i;
			cout << i << "\n";
		}
	}
	// 만약 n 이 두 소수의 곱일 경우  한쪽이 sqrt(n) 이상의 소수 일 수 있음
	if (n != 1)
		cout << n << endl;
	
	return 0;
}