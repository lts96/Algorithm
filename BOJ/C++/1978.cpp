#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n , ans;
vector <int> v;
int main(void)
{
	int temp;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 1; j <= arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			ans++;
			v.push_back(arr[i]);
		}

	}
	cout << ans << endl;
	//for (int i = 0; i < v.size(); i++)
		//cout << v[i] << " ";
	//system("pause");
	return 0;
}