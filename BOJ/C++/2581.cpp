#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int m , n , ans;
vector <int> v;
int main(void)
{
	int temp;
	int min = 10000000 , sum = 0;
	cin >> m >> n;
	
	for (int i = m; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			v.push_back(i);
			if (i < min)
				min = i;
		}
	}
	if (v.empty())
	{
		cout << "-1" << endl;
		//system("pause");
		return 0;
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			ans += v[i];
		}
	}
	cout << ans << endl;
	cout << min << endl;
	
	//system("pause");
	return 0;
}