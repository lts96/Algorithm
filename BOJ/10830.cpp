#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
long long n, b;
vector <long long> pw;
long long matrix[5][5] , arr[5][5] , ans[5][5];
void clear()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			arr[i][j] = matrix[i][j];
	}
	return;
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return;
}
long long multiple(int x, int y)
{
	long long temp = 0;
	for (int i = 0; i < n; i++)
		temp = (temp + (arr[x][i] * arr[i][y])) % 1000;
	return temp;
}
void run(long long target)
{
	int cnt = 0;
	int arr2[5][5];
	while (cnt != target)  //arr을 계속 제곱 
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				arr2[i][j] = multiple(i, j);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = arr2[i][j];
		}
	}
	//print();
	// 이러고 ans와 arr을 곱 
	int arr3[5][5];   
	for (int i = 0; i < n; i++)  //행렬 곱셈하면서 값이 변함 -> 방지하기 위해 arr3으로 분리
	{
		for (int j = 0; j < n; j++)
		{
			long long temp = 0;
			for (int k = 0; k < n; k++)
				temp = (temp + (ans[i][k] * arr[k][j])) % 1000;
			arr3[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ans[i][j] = arr3[i][j];
	}
	clear();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			arr[i][j] = matrix[i][j];
			if (i == j)
				ans[i][j] = 1;
		}
	}
	int p = 36;
	while (b > 1)
	{
		long long temp = pow(2, p);
		if (b / temp)
		{
			b -= temp;
			pw.push_back(p);
		}
		p--;
	}
	if (b == 1)
		pw.push_back(0);
	for (int i = 0; i < pw.size(); i++)
	{
		//cout << pw[i] << endl;
		run(pw[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}