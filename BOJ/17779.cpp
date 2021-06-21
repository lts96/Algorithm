#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int sector[5];
int n, ans = 987654321;
int arr[21][21];
int arr2[21][21];
void print()
{
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr2[i][j] << " ";
		cout << endl;
	}
	return;
}
void divide(int x, int y, int d1, int d2)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			arr2[i][j] = 0;
	}
	// 구역 5 선그리기 
	for (int i = 0; i <= d1; i++)
		arr2[x + i][y - i] = 5;
	for (int i = 0; i <= d2; i++)
		arr2[x + i][y + i] = 5;
	for (int i = 0; i <= d2; i++)
		arr2[x + d1 + i][y - d1 + i] = 5;
	for (int i = 0; i <= d1; i++)
		arr2[x + d2 + i][y + d2 - i] = 5;
	// 구역 5 내부 채우기 
	
	int s,d;
	for (int i = 1; i <= n; i++)
	{
		s = 0, d = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr2[i][j] == 5 && s == 0)
				s = j;
			else if (arr2[i][j] == 5 && s != 0)
				d = j;
		}
		if (s != 0 && d != 0)
		{
			for (int j = s; j <= d; j++)
				arr2[i][j] = 5;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr2[i][j] == 5)
			{
				sector[4] += arr[i][j];
				continue;
			}
			if (i < x + d1 && j <= y)
			{
				sector[0] += arr[i][j];
				arr2[i][j] = 1;
			}
			else if (i <= x + d2 && y < j && j <= n)
			{
				sector[1] += arr[i][j];
				arr2[i][j] = 2;
			}
			else if (x + d1 <= i && i <= n && j < y - d1 + d2)
			{
				sector[2] += arr[i][j];
				arr2[i][j] = 3;
			}
			else if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n)
			{
				sector[3] += arr[i][j];
				arr2[i][j] = 4;
			}
		}
	}
	sort(sector, sector + 5);
	int ret = sector[4] - sector[0];
	ans = min(ans, ret);
	for (int i = 0; i < 5; i++)
		sector[i] = 0;

	//print();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			for (int d1 = 1; d1 <= y-1; d1++)
			{
				for (int d2 = 1; d2 <= n-y; d2++)
				{
					if (x + d1 + d2 <= n)
						divide(x, y, d1, d2);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}