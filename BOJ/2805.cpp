#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
int n , m;
int tree;
int arr[1000000];
long long ans;
using namespace std;
long long sum(int k)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > k)
			sum += arr[i] - k;
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > tree)
			tree = arr[i];
	}
	int first = 0; 
	int last = tree;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2; 
		long long result = sum(mid);
		if (result == m)
		{
			if (mid > ans)
				ans = mid;
			break;
		}
		else
		{
			if (result < m)
			{
				last = mid - 1;
			}
			else if (result > m)
			{
				if (mid > ans)
					ans = mid;
				first = mid + 1;
			}
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}