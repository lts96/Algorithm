#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
int n, k;
int *arr;

int main(void)
{
    ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> k;
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> arr[i]; 
	sort(arr, arr + n);
	cout << arr[k-1];
	//system("pause");
	return 0;
}