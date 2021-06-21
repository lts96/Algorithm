#include <iostream>
#include <stdlib.h>
#pragma warning (disable:4996)
char **arr;
int mini = 10000;
int n, m;
using namespace std;
void coloring(int x, int y)
{
	int count = 0;
	if (arr[x][y] == 'W')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0 && arr[x+i][y+j] != 'W')
					count++;
				if ((i + j) % 2 != 0 && arr[x+i][y+j] == 'W')
					count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0 && arr[x+i][y+j] != 'B')
					count++;
				if ((i + j) % 2 != 0 && arr[x+i][y+j] == 'B')
					count++;
			}
		}
	}
	if (count <= 64 - count)
	{
		if ( count <= mini)
			mini = count;
	}
	if (count >= 64 - count)
	{
		if (64 - count <= mini)
			mini = 64 - count;
	}
}


void select()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + 8 <= n && j + 8 <= m)
			{
				coloring(i, j);
			}
		}
	}
}




int main(void)
{
	cin >> n >> m;
	arr = new char*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	select();
	cout << mini << endl;
	//system("pause");
	return 0;
}