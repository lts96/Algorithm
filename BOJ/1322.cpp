#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
long long x, k;
int arr[90];
int y[90];
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x >> k;
	long long cnt = 0 , index = 89;
	while (x != 0)
	{
		arr[index] = 1 & x;
		x = x >> 1;
		index--;
	}
	int temp , start = 89;
	while (k != 0)
	{
		temp = 1 & k;
		k = k >> 1;
		for (int i = start; i >= 0; i--)
		{
			if (arr[i] == 0)
			{
				y[i] = temp;
				start = i - 1;
				break;
			}
		}
	}
	for (int i = 89; i >= 0; i--)
	{
		if (y[i] == 1)
			start = i;
	}
	long long ans = 1;
	for (int i = start+1; i < 90; i++)
	{
		if (y[i] == 0)
			ans = ans << 1;
		else
		{
			ans = ans << 1;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}