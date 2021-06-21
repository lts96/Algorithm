#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unsigned long long n, temp, ans = 0, sum = 0;
	cin >> n;
	vector <unsigned long long> p, d;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> temp;
		d.push_back(temp);
	}
	d.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		p.push_back(temp);
	}
	for (int i = 0; i < n - 1; i++)
	{
		sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum += (d[j - 1] * p[i]);
			if (p[i] >= p[j])
			{
				i = j - 1;
				break;
			}
			if(j == n-1)
				i = j;
		}
		ans += sum;
		//cout << sum << " ";
	}
	//cout << endl;
	cout << ans;
	return 0;
}

