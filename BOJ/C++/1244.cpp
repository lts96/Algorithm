#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
int n,m;
int arr[101];

void boy(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			if (arr[i])
				arr[i] = 0;
			else
				arr[i] = 1;
		}
	}
	return;
}
void girl(int k)
{
	for (int i = 0; i <= n; i++)
	{
		if (k + i> n || k - i < 1)
			break;
		if (arr[k + i] == arr[k - i])
		{
			if (arr[k+i])
				arr[k + i] = arr[k - i] = 0;
			else
				arr[k + i] = arr[k - i] = 1;
		}
		else
			break;
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (a == 1)
			boy(b);
		else
			girl(b);
	}
	if (n <= 20)
	{
		for (int i = 1; i <= n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		int mod = n % 20;
		int t = n / 20;
		for (int i = 0; i < t; i++)
		{
			for (int j = 1; j <= 20; j++)
				cout << arr[j + i * 20] << " ";
			cout << endl;
		}
		for(int i = 1; i <= mod; i++)
			cout << arr[i + t * 20] << " ";
		cout << endl;
	}
	return 0;
}
