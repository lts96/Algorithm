#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
using namespace std;
int snake[103][2];
int n , k , l, ans;
int arr[100][100];
int x, y;  // 머리 좌표
int dist = 1;  // 방향 
int schedule[104][2];
int pos = 0;
int length = 1;
int move()
{
	if (dist == 1) // 오른쪽
	{
		y++;
		if (((x < 0) || (y < 0)) || ((x > n - 1) || (y > n - 1)))
			return -1;
		// 몸통 충돌 체크 
		for (int i = 0; i < length; i++)
		{
			if ((snake[i][0] == x) && (snake[i][1] == y))
				return -1;
		}
		if (arr[x][y] == 4) 
		{
			length++;
			snake[length][0] = x;
			snake[length][1] = y;
			arr[x][y] = 0;  // 사과를 먹으면 없어져야됨 -> 이거 제대로 안읽음
			return 1;
		}
		for (int i = 1; i < length; i++)  // 머리 외 좌표 갱신 
		{
			snake[i][0] = snake[i+1][0];
			snake[i][1] = snake[i+1][1];
		}
		snake[length][0] = x; snake[length][1] = y;
	}
	else if (dist == 2) // 아래
	{
		x++;
		if (((x < 0) || (y < 0)) || ((x > n - 1) || (y > n - 1)))
			return -1;
		// 몸통 충돌 체크 
		for (int i = 0; i < length; i++)
		{
			if ((snake[i][0] == x) && (snake[i][1] == y))
				return -1;
		}
		if (arr[x][y] == 4) // 사과 섭취 
		{
			length++;
			snake[length][0] = x;
			snake[length][1] = y;
			arr[x][y] = 0;
			return 1;
		}
		
		for (int i = 1; i < length; i++)  // 머리 외 좌표 갱신 
		{
			snake[i][0] = snake[i + 1][0];
			snake[i][1] = snake[i + 1][1];
		}
		snake[length][0] = x; snake[length][1] = y;
	}
	else if (dist == 3) // 왼쪽 
	{
		y--;
		if (((x < 0) || (y < 0)) || ((x > n - 1) || (y > n - 1)))
			return -1;
		// 몸통 충돌 체크 
		for (int i = 0; i < length; i++)
		{
			if ((snake[i][0] == x) && (snake[i][1] == y))
				return -1;
		}
		if (arr[x][y] == 4) // 사과 섭취 
		{
			length++;
			snake[length][0] = x;
			snake[length][1] = y;
			arr[x][y] = 0;
			return 1;
		}
		for (int i = 1; i < length; i++)  // 머리 외 좌표 갱신 
		{
			snake[i][0] = snake[i + 1][0];
			snake[i][1] = snake[i + 1][1];
		}
		snake[length][0] = x; snake[length][1] = y;
	}
	else if (dist == 4) // 위
	{
		x--;
		if (((x < 0) || (y < 0)) || ((x > n - 1) || (y > n - 1)))
			return -1;
		// 몸통 충돌 체크 
		for (int i=0; i< length; i++)
		{
			if ((snake[i][0] == x) && (snake[i][1] == y))
				return -1;
		}
		if (arr[x][y] == 4) // 사과 섭취 
		{
			length++;
			snake[length][0] = x;
			snake[length][1] = y;
			arr[x][y] = 0;
			return 1;
		}
		for (int i = 1; i < length; i++)  // 머리 외 좌표 갱신 
		{
			snake[i][0] = snake[i + 1][0];
			snake[i][1] = snake[i + 1][1];
		}
		snake[length][0] = x; snake[length][1] = y;
	}
	return 0;
}
void turn(int t)  // ok
{
	if (t == schedule[pos][0])
	{
		if (schedule[pos][1] == 1)  // 오른쪽 회전 -> +1
		{
			if (dist < 4)
				dist++;
			else
				dist = 1;
		}
		else  // 왼쪽 회전 -> -1
		{
			if (dist > 1)
				dist--;
			else
				dist = 4;
		}
		pos++;  // 다음 스케줄로 넘어가기 
	}
	else
		return;
}
void run()
{
	int sec = 0 , result = 0;
	while (1)
	{
		sec++;
		result = move();
		//cout <<sec << " : " << x << " " << y  <<" " <<result << "\n";
		
		//for (int i = 1; i <= length; i++)
			//cout <<sec <<" -> " <<snake[i][0] << " " << snake[i][1] << "\n";
		
		if (result == -1)
			break;
		turn(sec);  
	}
	ans = sec;
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> k;
	int a, b , c ;
	char d;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		arr[a-1][b-1] = 4;
	}
	for (int i = 0; i < 103; i++)
		snake[i][0] = snake[i][1] = -1;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> c >> d;
		schedule[i][0] = c;
		if (d == 'L')
			schedule[i][1] = 3;
		else
			schedule[i][1] = 1;
	}
	run();
	cout << ans << endl;
	return 0;
}