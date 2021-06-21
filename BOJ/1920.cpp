#include <iostream>
#include <stdlib.h>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std; 
int n, m;
int *arr;
int find(int value, int left , int right )
{
	int mid = (left + right) / 2;
	if (left >= right)
	{
		if (arr[mid] == value)
			return 1;
		else
			return 0;
	}
	if (arr[mid] == value)
		return 1;
	else if (arr[mid] < value)
		return find(value, mid + 1, right);
	else if (arr[mid] > value)
		return find(value, left, mid - 1);

}



int main(void)
{
	int temp; 
	int right, left;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	right = n-1;
	left = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp); 
		printf("%d\n", find(temp, left , right ));
	}
	//system("pause"); 
	return 0; 
}