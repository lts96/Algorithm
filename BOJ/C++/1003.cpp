#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
int n, t;
int *arr;
int ans[50][2];
int zero, one;
void fibonacci(int n) 
{
	if (n == 0)
	{
		zero = 1; one = 0;
		ans[n][0] = 1; 
		ans[n][1] = 0;
	}
	if (n == 1)
	{
		zero = 0; one = 1;
		ans[n][0] = 0;
		ans[n][1] = 1;
	}
	if (n == 2)
	{
		zero = 1; one = 1;
		ans[n][0] = 1;
		ans[n][1] = 1;
	}
	if (n > 2)
	{
		if (ans[n][0]!=0&&ans[n][1]!=0)
		{
			zero = ans[n][0];
			one = ans[n][1];
		}
	    else
		{
			for (int i = 3; i <= n; i++)
			{
				ans[i][0] = ans[i - 1][0] + ans[i - 2][0];
				ans[i][1] = ans[i - 1][1] + ans[i - 2][1];
			}
			zero = ans[n][0];
			one = ans[n][1];
		}
	}
}



int main(void)
{
	cin >> t;
	arr = (int*)malloc(sizeof(int)*t);
	for (int i=0;i<t;i++)
	cin >> arr[i];
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;
	ans[2][0] = 1;
	ans[2][1] = 1;
	for (int i = 0; i < t; i++)
	{
		fibonacci(arr[i]);
		cout << zero <<" " << one << endl; 
		zero = 0; 
		one = 0;
	}

	//system("pause");
	return 0;
}
