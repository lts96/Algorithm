#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#define size 10001
using namespace std;
bool prime[size];
int arr[size];
int m, n , ans;
int main()
{
	int count = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 2; i <= n; i++)
		prime[i] = true;

	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
			continue;
		for (int j = i; j <= n; j += i)
			if (prime[j])
			{
				prime[j] = false;
				//cout << j << endl;
				count++;
				if (count == m)
				{
					cout << j << endl;
					return 0;
				}
			}
	}
	
	return 0;
}