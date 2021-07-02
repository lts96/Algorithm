#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n; 
	cin >> n;
	int temp , ans = 0;
	for (int i = 1; i <= n; i++)
	{
		temp = i;
		while(temp % 5 == 0 && (temp > 0))
		{
			ans++;
			temp /= 5;
		}
	}
	cout << ans << endl;
	return 0;
}