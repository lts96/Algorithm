#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
// 15683 감시 
int n, m , ans = 10000;
int cnt;
int arr[8][8];
int direct[8];
int cctv[8][3];

void beam(int d , int x , int y)
{
	if (d == 1)  // 오른쪽
	{
		for (int i = y; i < m; i++)
		{
			if (arr[x][i] == 6)
				break;
			if (arr[x][i] == 0)
				arr[x][i] = -1;
		}
	}
	else if (d == 2) // 아래
	{
		for (int i = x; i < n; i++)
		{
			if (arr[i][y] == 6)
				break;
			if (arr[i][y] == 0)
				arr[i][y] = -1;
		}
	}
	else if (d == 3) // 왼쪽 
	{
		for (int i = y; i >= 0; i--)
		{
			if (arr[x][i] == 6)
				break;
			if (arr[x][i] == 0)
				arr[x][i] = -1;
		}
	}
	else if (d == 4) // 위 
	{
		for (int i = x; i >=0; i--)
		{
			if (arr[i][y] == 6)
				break;
			if (arr[i][y] == 0)
				arr[i][y] = -1;
		}
	}
}
void cctv_on()
{
	int temp = 0;
	for (int i = 0; i < cnt; i++)
	{
		int x = cctv[i][0];
		int y = cctv[i][1];
		int type = cctv[i][2];

		if (type == 1)
			beam( direct[i] , x, y);
		else if (type == 5)
		{
			beam(1, x, y);
			beam(2, x, y);
			beam(3, x, y);
			beam(4, x, y);
		}
		else if (type == 2)
		{
			if (direct[i] % 2 == 0)
			{
				beam(1, x, y);
				beam(3, x, y);
			}
			else
			{
				beam(2, x, y);
				beam(4, x, y);
			}
		}
		else if (type == 3)
		{
			beam(direct[i], x, y);
			if(direct[i]< 4)
				beam(direct[i]+1, x, y);
			else 
				beam(1, x, y);
		}
		else if (type == 4)
		{
			beam(direct[i], x, y);
			if (direct[i] == 1)
			{
				beam(4, x, y);
				beam(2, x, y);
			}
			else if (direct[i] == 2)
			{
				beam(1, x, y);
				beam(3, x, y);
			}
			else if (direct[i] == 3)
			{
				beam(2, x, y);
				beam(4, x, y);
			}
			else if (direct[i] == 4)
			{
				beam(1, x, y);
				beam(3, x, y);
			}
		}
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)  // 카운트 
				temp++;
			if (arr[i][j] == -1)  // 초기화
				arr[i][j] = 0;
		}
	}
	ans = min(ans, temp);
	return;
}

void run(int d)
{
	if (d == cnt)  // cctv 8개일때 최대 65536
	{
		cctv_on();
		return;
	}
	direct[d] = 1;
	run(d + 1);
	direct[d] = 2;
	run(d + 1);
	direct[d] = 3;
	run(d + 1);
	direct[d] = 4;
	run(d + 1);
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 8; i++)
		direct[i] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)
			{
				cctv[cnt][0] = i;
				cctv[cnt][1] = j;
				cctv[cnt][2] = arr[i][j];
				direct[cnt] = 1;
				cnt++;
			}
		}
	}

	run(0);
	cout << ans << endl;
	return 0;
}