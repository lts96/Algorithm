#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
int map[21][21];
int dice[6];    // 최상단은 0  바닥은 5
int n, m ,k , x , y;
void roll_dice(int cmd)
{
	if (cmd == 1)
	{
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (cmd == 2)
	{
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	else if (cmd == 3)
	{
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else
	{
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
}
void run(int cmd)
{
	if (cmd == 1)
	{
		if (y + 1 < m)
		{
			y++;
			roll_dice(cmd);
		}
		else
			return;
	}
	else if (cmd == 2)
	{
		if (y - 1 >= 0)
		{
			y--;
			roll_dice(cmd);
		}
		else
			return;
	}
	else if (cmd == 3)
	{
		if (x - 1 >= 0)
		{
			x--;
			roll_dice(cmd);
		}
		else
			return;
	}
	else
	{
		if (x + 1 < n)
		{
			x++;
			roll_dice(cmd);
		}
		else
			return;
	}
	if (map[x][y] == 0)
	{
		map[x][y] = dice[5];
	}
	else
	{
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[0] << "\n";
}

int main(void)
{
	int cmd;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> cmd;
		run(cmd);
	}
	return 0;
}