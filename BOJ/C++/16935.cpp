#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
#include <stack>
using namespace std;
int n, m, r;
int arr[101][101];
int arr_copy[101][101];
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j])
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}
void clear()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			arr_copy[i][j] = 0;
	}
	return;
}
void copy_arr()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			arr[i][j] = arr_copy[i][j];
	}
	return;
}
void func1()
{
	clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr_copy[n - 1 - i][j] = arr[i][j];
	}
	copy_arr();
	return;
}
void func2()
{
	clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr_copy[i][m-1-j] = arr[i][j];
	}
	copy_arr();
	return;
}
void func3()
{
	clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr_copy[j][n-1-i] = arr[i][j];
	}
	copy_arr();
	// n,m swap
	int temp = m;
	m = n;
	n = temp;
	return;
}
void func4()
{
	for (int i = 0; i < 3; i++)
		func3();
	return;
}
void func5()
{
	clear();
	// 1 -> 2
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
			arr_copy[i][j+ m/2] = arr[i][j];
	}
	// 2 -> 3
	for (int i = 0; i < n/2; i++)
	{
		for (int j = m/2; j < m; j++)
			arr_copy[i + n/2][j] = arr[i][j];
	}
	// 3 -> 4
	for (int i = n / 2; i < n; i++)
	{
		for (int j = m/2; j < m; j++)
			arr_copy[i][j -  m/2] = arr[i][j];
	}
	// 4 -> 1
	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m/2; j++)
			arr_copy[i - n/2][j] = arr[i][j];
	}
	copy_arr();
	return;
}
void func6()
{
	clear();
	// 1 -> 4
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
			arr_copy[i + n/2][j] = arr[i][j];
	}
	// 4 -> 3
	for (int i = n/2; i < n; i++)
	{
		for (int j = 0; j < m/2; j++)
			arr_copy[i][j + m/2] = arr[i][j];
	}
	// 3 -> 2
	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
			arr_copy[i - n/2][j] = arr[i][j];
	}
	// 2 -> 1
	for (int i = 0; i < n/2; i++)
	{
		for (int j = m/2; j < m; j++)
			arr_copy[i][j- m/2] = arr[i][j];
	}
	copy_arr();
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	int input;
	for (int i = 0; i < r; i++)
	{
		cin >> input;
		if (input == 1)
			func1();
		else if (input == 2)
			func2();
		else if (input == 3)
			func3();
		else if (input == 4)
			func4();
		else if (input == 5)
			func5();
		else
			func6();
	}
	print();
	return 0;
}
