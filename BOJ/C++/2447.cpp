#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h> 
int n;
int arr[6561][6561];
using namespace std;
void star(int cnt, int x1, int y1 , int x2 , int y2)
{
	if (cnt == 3)
	{
		arr[(x1+x2)/2][(y1+y2)/2] = 1;
		return;
	}
	int temp = cnt / 3;
	for (int i = x1 + temp; i <= x2- temp ; i++)  // 가운데 빈 공간 
	{
		for (int j = y1+temp; j <= y2-temp; j++)
			arr[i][j] = 1;
	}
	// 나머지 8개 하위 공간 
	star(temp, x1, y1, x1 + temp - 1, y1 + temp - 1);
	star(temp, x1+temp, y1, x1 - 1 + (2*temp), y1 + temp - 1);
	star(temp, x1+(temp*2), y1, x2, y1 + temp - 1);
	star(temp, x1, y1+temp, x1 + temp - 1, y1 + (temp*2) - 1);
	star(temp, x1 + (temp * 2), y1 + temp, x2, y1 + (temp * 2) - 1);
	star(temp, x1, y1 + (temp * 2), x1 + temp - 1, y2);
	star(temp, x1 + temp, y1 + (temp*2), x1 - 1 + (2 * temp), y2);
	star(temp, x1 + (temp * 2), y1 + (temp*2), x2, y2);
	return;
}
int main(void)
{
	cin >> n;
	star(n, 0,0,n-1, n-1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}