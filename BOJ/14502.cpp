#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility>
#include <vector>
//#include <windows.h>   // 나중에 지울것
using namespace std;
int width, length;
int arr[8][8], arr_copy[8][8];
vector <int> ans_arr;
int ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue <pair<int, int> > q;
int pos[3][2];
void bfs()
{
	int x, y;
	int temp;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i] >= 0 && x + dx[i] <= width - 1) && (y + dy[i] >= 0 && y + dy[i] <= length - 1))
			{
				if (arr[x + dx[i]][y + dy[i]] == 0)
				{
					arr[x + dx[i]][y + dy[i]] = 2;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
		}
		q.pop();
	}
}
void find()
{
	int temp = 0;
	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (arr[i][j] == 0)
			{
				temp++;
			}
			else if (arr[i][j] != 3)
				arr[i][j] = arr_copy[i][j];
		}
	}
	if (temp >= ans)
	{
		ans = temp;
	}
}
int set_wall(int count)
{
	if (count == 3)
	{
		
		find();
		return 1;
	}
	else
	{
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (arr[i][j] == 0)
				{
					arr[i][j] = 3;
					pos[count][0] = i;
					pos[count][1] = j;
					set_wall(count + 1);
					arr[i][j] = 0;
				}
			}
		}

	}
	return 0;
}
int main(void)
{
	int a;
	cin >> length;
	cin >> width;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = 1;
			arr_copy[i][j] = 1;
		}
	}



	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < width; i++)
		{
			cin >> arr[i][j];
			arr_copy[i][j] = arr[i][j];

		}
	}
	set_wall(0);
	cout << ans << endl;
	//system("pause"); 
	return 0;
}