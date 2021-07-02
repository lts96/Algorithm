#include <iostream>
#include <algorithm>
using namespace std; 
int k;
int ans;
int arr[1000]; 
int main(void)
{
	cin >> k; 
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + k);
	for (int i = 0; i < k; i++)
	{
		ans += arr[i] * (k - i);
	}
	cout << ans;
	//system("pause"); 
	return 0; 
}