#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
int n, ans;
int arr[50][9];// 각 선수의 타율 정보 
int order[9];  // 각 선수의 타순 
int mound[9];  // 각 선수가 현재 몇 루에 위치하는지 체크 
bool selected[9];
int record[9];
// 17281 야구 문제 



void baseball() // 순서가 정해지면 거기에 따라 점수 계산 
{
	int out = 0;
	int score = 0;
	int player[9];
	int start = 0;  // 마지막 위치 
	for (int i = 0; i < 9; i++)  // 순서에 따라서 선수 번호 재정렬?
	{
		player[order[i]] = i;
		mound[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		while (out < 3)  // 아웃이 3개 나와야 다음 이닝으로 넘어간다
		{
			int temp = player[start];  // 현재 타자
			if (arr[i][temp] == 0)
				out++;
			else if (arr[i][temp] == 4) // 홈런 
			{
				score++;
				for (int j = 0; j < 9; j++)
				{
					if (mound[j] > 0)
						score++;
					mound[j] = 0;
				}
			}
			else  // 1 2 3 루타 
			{
				for (int j = 0; j < 9; j++)
				{
					if (mound[j] > 0)
					{
						mound[j] += arr[i][temp];
						if (mound[j] >= 4)
						{
							mound[j] = 0;
							score++;
						}
					}
				}
				mound[temp] += arr[i][temp];
			}

			// 다음 선수로 넘어가기 
			start++;
			if (start == 9)
				start = 0;
		}
		if (out == 3)
		{
			for (int j = 0; j < 9; j++)  // 이닝 끝나면 타자 정보 초기화 
				mound[j] = 0;
			out = 0;
		}
	}
	if (score >= ans)
	{
		ans = score;
		for (int i = 0; i < 9; i++)
			record[i] = player[i];
	}
	return;
}



void select(int cnt)   // 순서 브루트포스 -> 8! = 40320
{
	if (cnt == 9)
	{
		/*
		cout << "타석 : ";
		for (int i = 0; i < 9; i++)
		{
		cout << order[i] << " , ";
		}
		cout << "\n";
		*/
		baseball();
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (selected[i] == false)
		{
			order[cnt] = i;
			selected[i] = true;
			select(cnt + 1);
			selected[i] = false;
		}
	}
}



int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}
	for (int j = 0; j < 9; j++)
		order[j] = -1;
	order[0] = 3;   // 1번 선수는 4번 타자로 정해짐 
	selected[3] = true;
	select(1);

	cout << ans << endl;
	//system("pause");
	return 0;
}