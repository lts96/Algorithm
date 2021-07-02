#include <iostream>
#include <stdlib.h>
using namespace std;
int n; 
int arr[50][3]; 
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1]; 
		arr[i][2]++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
			{
				arr[i][2]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i][2] << " "; 
	}
	//system("pause");
	return 0;
}