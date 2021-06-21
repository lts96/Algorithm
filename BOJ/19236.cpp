#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1};
int arr[5][5];
int fish[17][3];
bool dead[17];
int n = 4, ans;
int deadcnt;
void swap(int x1, int y1, int x2, int y2 ,int fnum, int d)
{
	int temp;
	int num = arr[x2][y2];
	temp = arr[x1][y1];
	arr[x1][y1] = arr[x2][y2];
	arr[x2][y2] = temp;
	fish[fnum][0] = x2;
	fish[fnum][1] = y2;
	fish[fnum][2] = d;
	if (num > 0)
	{
		fish[num][0] = x1;
		fish[num][1] = y1;
	}
	return;
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j]<< " ";
		cout << endl;
	}
	return;
}
void fishMove()
{
	int d, x, y, idx;
	
	for (int i = 1; i <= 16; i++)
	{
		if (dead[i])
			continue;
		d = fish[i][2];
		for (int j = 0; j < 8; j++)
		{
			idx = d + j;
			if (idx > 8)
				idx = idx % 8;
			x = fish[i][0] + dx[idx];
			y = fish[i][1] + dy[idx];
			if (x >= 0 && x < 4 && y >= 0 && y < 4)
			{
				if (arr[x][y] != -1)
				{
					swap(fish[i][0], fish[i][1], x, y, i, idx);
					break;
				}
			}
		}
	}
	
	return;
}

void sharkMove(int depth , int sum)
{
	int d = fish[0][2];
	int x = fish[0][0];
	int y = fish[0][1];
	int nx, ny, num;
	if (deadcnt >= 16)
		return;
	fishMove();
	//cout << x << " " << y << " " << d << endl;
	int fish_copy[17][3];
	int arr_copy[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			arr_copy[i][j] = arr[i][j];
	}
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 3; j++)
			fish_copy[i][j] = fish[i][j];
	}

	for (int i = 1; i <= 3; i++)
	{
		nx = x + dx[d] * i;
		ny = y + dy[d] * i;
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4)
		{
			num = arr[nx][ny];
			if (num > 0)
			{
				//cout <<depth <<": shark eat " << num << endl;
				deadcnt++;
				fish[0][2] = fish[num][2];
				arr[nx][ny] = -1;
				arr[x][y] = 0;
				fish[0][0] = nx;
				fish[0][1] = ny;
				dead[num] = true;
				sharkMove(depth+1, sum + num);
				dead[num] = false;
				deadcnt--;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
						arr[i][j]= arr_copy[i][j];
				}
				for (int i = 0; i < 17; i++)
				{
					for (int j = 0; j < 3; j++)
						fish[i][j]= fish_copy[i][j];
				}
			}
		}
	}
	ans = max(ans, sum);
	return;
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> num;
			arr[i][j] = num;
			fish[num][0] = i;
			fish[num][1] = j;
			cin >> fish[num][2];
		}
	}
	num = arr[0][0];
	fish[0][2] = fish[num][2];  // 상어
	dead[arr[0][0]] = true;
	deadcnt++;
	arr[0][0] = -1; // 상어가 있음 
	sharkMove(0,num);
	cout << ans << "\n";
	return 0;
}