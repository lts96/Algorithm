#include <iostream>
#include <algorithm>
using namespace std; 
int n; 
int k;
int ans;
int arr[10]; 
int main(void)
{
	cin >> n;
	cin >> k; 
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//sort(arr, arr + n);
	for (int i = n-1; i >=0; i--)
	{
		if (k >= arr[i])
		{
			ans += k / arr[i]; 
			k= k % arr[i];
		}
	}
	cout << ans;
	//system("pause"); 
	return 0; 
}