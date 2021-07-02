#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
using namespace std;
int n;
int arr[101][101];
int ans;
int end_x = -1, end_y = -1;
int last_d;
// 백준 15685
// 19퍼에서 틀림
vector <pair <int, int>> v;
void zero_curve(int x, int y, int d, int g)
{
	if (g == 0)
	{
		v.push_back(make_pair(x, y));
		arr[x][y] = 1;
		if (d == 0)
		{
			arr[x + 1][y] = 1;
			end_x = x + 1;
			end_y = y;
			v.push_back(make_pair(end_x, end_y));
		}
		if (d == 1)
		{
			arr[x][y - 1] = 1;
			end_x = x;
			end_y = y - 1;
			v.push_back(make_pair(end_x, end_y));
		}
		if (d == 2)
		{
			arr[x - 1][y] = 1;
			end_x = x - 1;
			end_y = y;
			v.push_back(make_pair(end_x, end_y));
		}
		if (d == 3)
		{
			arr[x][y + 1] = 1;
			end_x = x;
			end_y = y + 1;
			v.push_back(make_pair(end_x, end_y));
		}
		return;
	}
	
}

int main(void)
{	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, d ,g;
		cin >> x >> y >> d >> g;
		zero_curve(x, y, d, 0);
		if (g > 0)
		{
			for (int j = 0; j < g; j++)
			{
				int size = v.size() - 1;
				end_x = v.back().first;
				end_y = v.back().second;
				for (int h = size; h >= 0; h--)
				{
					int dx = end_x - v[h].first;
					int dy = end_y - v[h].second;
					int temp = dx;
					dx = dy + end_x;
					dy = -temp + end_y;
					arr[dx][dy] = 1;
					v.push_back(make_pair(dx, dy));
				}
			}
		}
		while (!v.empty())
			v.pop_back();
		end_x = end_y = -1;
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)  // 사각형 검사 ok
		{
			if ((arr[i][j] == 1 && arr[i][j + 1] == 1) && (arr[i + 1][j] == 1 && arr[i + 1][j + 1]))
			{
				ans++;
			}
		}
	}
	/*
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << arr[j][i] << " "; 
		}
		cout << endl;
	}
	*/
	cout << ans << endl;
	//system("pause");
	return 0;
}