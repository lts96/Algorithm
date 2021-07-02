#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
vector<int> arr;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 1; i < n; i++)
	{
		int g = gcd(arr[0], arr[i]);
		cout << arr[0] / g << "/" << arr[i] / g << "\n";
	}
	return 0;
}