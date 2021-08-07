#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
int n, ans;
int arr[501][501];
int h, w;
// 값만 비교해서 더 쉽게 풀수도 있었음 -> 나중에 해보기 
void print()
{
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return;
}
void count_rain()
{
	int temp, wall;
	for (int i = 0; i < h; i++)
	{
		temp = wall = 0;
		//양쪽 맨 끝 블럭이 빈 공간이면 어차피 물이 고일 수 없음
		// 가로로 돌면서 물이 고일 수 있는 부분인지 체크 
		for (int j = 1; j < w-1; j++)
		{
			if (arr[i][j] == 0 && arr[i][j - 1] == 1)
			{
				wall = 1;
				arr[i][j] = 2;
				continue;
			}
			if (wall == 1 && arr[i][j] == 0)
			{
				arr[i][j] = 2;
				if (arr[i][j + 1] == 1)
					wall = 0;
			}
		}
		// 예외처리 부분 -> 맨 끝 블록이 비어있는 경우 
		if (wall == 1)
		{
			for (int j = w - 1; j >= 0; j--)
			{
				if (arr[i][j] != 1)
					arr[i][j] = 0;
				else 
					break;
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == 2)
				ans++;
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> h >> w;
	int input;
	for (int i = 0; i < w; i++)
	{
		cin >> input;
		for (int j = 0; j < input; j++)
			arr[h - 1 - j][i] = 1;
	}
	count_rain();
	//print();
	cout << ans << endl;
	return 0;
}
