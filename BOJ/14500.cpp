#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
int n, m , ans;
int arr[501][501];

void rect1(int x, int y) // 1자 막대 
{
	int temp;
	if (y + 3 < m)
	{
		temp = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x][y + 3];
		ans = max(ans, temp);
 	}
	if (x + 3 < n)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 3][y];
		ans = max(ans, temp);
	}
}
void rect2(int x, int y) // 정사각형
{
	int temp;
	if (x + 1 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x + 1][y + 1];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y - 1 >= 0)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x + 1][y - 1];
		ans = max(ans, temp);
	}
	if (x - 1 >= 0 && y + 1 < m)
	{
		temp = arr[x][y] + arr[x - 1][y] + arr[x][y + 1] + arr[x - 1][y + 1];
		ans = max(ans, temp);
	}
	if (x - 1 >= 0 && y - 1 >= 0)
	{
		temp = arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x - 1][y - 1];
		ans = max(ans, temp);
	}
}
void rect3(int x, int y) // ㅗ 모양
{
	int temp;
	if (y + 2 < m && x + 1 < n)
	{
		temp = arr[x][y] + arr[x][y+1] + arr[x][y + 2] + arr[x + 1][y + 1];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y - 1 >= 0)
	{
		temp = arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x + 1][y - 1];
		ans = max(ans, temp);
	}
	if (x -1 >=0  && y +2 < m)
	{
		temp = arr[x][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x + 1][y + 1] + arr[x+1][y ] + arr[x+2][y];
		ans = max(ans, temp);
	}
}
void rect4(int x, int y) // 번개 모양
{
	int temp;
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y+ 1];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x+ 1][y] + arr[x + 1][y+ 1] + arr[x][y + 1] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x+ 2][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x][y + 1];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x][y] + arr[x][y+ 1] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
		ans = max(ans, temp);
	}
}
void rect5(int x, int y) // ㄴ 모양
{
	int temp;
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x+ 2][y + 1];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x][y+ 1] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x][y+ 1] + arr[x + 1][y+ 1] + arr[x + 2][y + 1];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x+ 1][y] + arr[x + 1][y+ 1] + arr[x+ 1][y + 2] + arr[x][y + 2];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y+1] + arr[x + 1][y+ 1] + arr[x + 2][y+ 1] + arr[x + 2][y];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x][y] + arr[x + 1][y] + arr[x + 1][y+ 1] + arr[x + 1][y + 2];
		ans = max(ans, temp);
	}
	if (x + 2 < n && y + 1 < m)
	{
		temp = arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 2][y];
		ans = max(ans, temp);
	}
	if (x + 1 < n && y + 2 < m)
	{
		temp = arr[x][y] + arr[x][y+ 1] + arr[x][y + 2] + arr[x + 1][y + 2];
		ans = max(ans, temp);
	}
}

void search()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rect1(i, j);
			rect2(i, j);
			rect3(i, j);
			rect4(i, j);
			rect5(i, j);
		}
	}
}
int main(void)
{
	int cmd;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	search();
	cout << ans << endl;
	return 0;
}