#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;
int arr[4][8];
int k;
void swap(int index , int flag)
{
	if (flag == -1) // 시계 반대 방향 회전
	{
		int temp = arr[index][0];
		for (int i = 0; i < 7; i++)
			arr[index][i] = arr[index][i + 1];
		arr[index][7] = temp;
	}
	else  //시계 회전 
	{
		int temp = arr[index][7];
		for(int i = 7; i > 0 ; i--)
			arr[index][i] = arr[index][i - 1];
		arr[index][0] = temp;
	}
}
void rotate(int t , int r , int flag)   // 무한 루프 돔 
{
	if (t == 0)
	{
		if ((arr[t][2] != arr[t + 1][6]) && (flag != 1))
		{
			rotate(t + 1, r * -1 , -1);
		}
	}
	else if (t == 3)
	{
		if ((arr[t][6] != arr[t - 1][2]) && (flag != -1))
		{
			rotate(t - 1, r * -1 , 1);
		}
	}
	else // 2 ,3번째 톱니바퀴
	{
		if ((arr[t][2] != arr[t + 1][6]) && (flag != 1))  // 오른쪽 판정
		{
			rotate(t + 1, r * -1, -1);
		}
		if ((arr[t][6] != arr[t - 1][2]) && (flag != -1))  // 왼쪽 판정
		{
			rotate(t - 1, r * -1 , 1);
		}
	}
	swap(t , r);  // 나 자신이 회전
	return;
}
int main(void)
{
	int ans = 0;
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
			scanf("%1d", &arr[i][j]);
	}
	cin >> k;
	int t, r;
	for (int i = 0; i < k; i++)
	{
		cin >> t >> r;
		rotate(t - 1 , r , 0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][0] != 0)
			ans += pow(2,i);
	}
	for (int i = 0; i < 4; i++)
	{
		//for (int j = 0; j < 8; j++)
			//cout << arr[i][j] << " ";
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}