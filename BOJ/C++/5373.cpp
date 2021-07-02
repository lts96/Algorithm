#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
char cube[6][3][3];
int test, n;
//인덱스 :  윗면 0  앞면 1 아래면 2 뒷면 3  왼쪽면 4  오른쪽 면 5
void print(int idx)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << cube[idx][i][j];
		cout << "\n";
	}
	return;
}
void rotate(int idx , int d)
{
	int copy[3][3];
	int temp[4][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			copy[i][j] = cube[idx][i][j];
	}

	if (d == 1)  // 시계
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cube[idx][i][j] = copy[2 - j][i];
		}
		if (idx == 4)  // 왼쪽면 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = cube[i][j][0];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					cube[(i+1) % 4][j][0] = temp[i][j];
			}
		}
		else if (idx == 5) // 오른쪽 면 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = cube[i][j][2];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					cube[i][j][2] = temp[(i+1) % 4][j];
			}
		}
		else if (idx == 1)  // 앞면
		{
			for (int i = 0; i < 3; i++)
				temp[0][i] = cube[0][2][i];
			for (int i = 0; i < 3; i++)  // 왼 -> 위
				cube[0][2][i] = cube[4][2][i];
			for (int i = 0; i < 3; i++)  // 아래 -> 왼 
				cube[4][2][i] = cube[2][0][2-i];
			for (int i = 0; i < 3; i++)  // 오 -> 아래 
				cube[2][0][i] = cube[5][0][i];
			for (int i = 0; i < 3; i++)
				cube[5][0][2-i] = temp[0][i];
		}
		else if (idx == 3)  // 뒷면 
		{
			for (int i = 0; i < 3; i++)  // 아래 복사 
				temp[0][i] = cube[2][2][i];
			for (int i = 0; i < 3; i++)  // 왼 -> 아래
				cube[2][2][i] = cube[4][0][2-i];
			for (int i = 0; i < 3; i++)  // 위 -> 왼
				cube[4][0][i] = cube[0][0][i];
			for (int i = 0; i < 3; i++)  // 오 -> 위
				cube[0][0][i] = cube[5][2][2 - i];
			for (int i = 0; i < 3; i++)  // 아래 -> 오
				cube[5][2][i] = temp[0][i];
		}
		else if (idx == 0)  // 윗면 
		{
			for (int i = 0; i < 3; i++)    // 뒷면 저장
				temp[0][i] = cube[3][2][i];
			for (int i = 0; i < 3; i++)    // 왼 -> 뒤
				cube[3][2][i] = cube[4][2-i][2];
			for (int i = 0; i < 3; i++)    // 앞 -> 왼
				cube[4][i][2] = cube[1][0][i];
			for (int i = 0; i < 3; i++)    // 오 -> 앞
				cube[1][0][i] = cube[5][i][2];
			for (int i = 0; i < 3; i++)    // 뒤 -> 오
				cube[5][2-i][2] = temp[0][i];
		}
		else // 아래면 
		{
			for (int i = 0; i < 3; i++)    // 앞면 저장
				temp[0][i] = cube[1][2][i];
			for (int i = 0; i < 3; i++)    // 왼 -> 앞
				cube[1][2][i] = cube[4][i][0];
			for (int i = 0; i < 3; i++)    // 뒤 -> 왼
				cube[4][i][0] = cube[3][0][2-i];
			for (int i = 0; i < 3; i++)    // 오 -> 뒤
				cube[3][0][i] = cube[5][2-i][0];
			for (int i = 0; i < 3; i++)    // 앞 -> 오
				cube[5][i][0] = temp[0][i];
		}
	}
	else // 반시계
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cube[idx][i][j] = copy[j][2-i];
		}
		if (idx == 4)  // 왼쪽면 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = cube[i][j][0];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					cube[i][j][0] = temp[(i + 1) % 4][j];
			}
		}
		else if (idx == 5) // 오른쪽 면 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = cube[i][j][2];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					cube[(i + 1) % 4][j][2] = temp[i][j];
			}
		}
		else if (idx == 1)  // 앞면
		{
			for (int i = 0; i < 3; i++)
				temp[0][i] = cube[0][2][i];
			for (int i = 0; i < 3; i++)  // 오 -> 앞
				cube[0][2][i] = cube[5][0][2-i];
			for (int i = 0; i < 3; i++)  // 아래 -> 오 
				cube[5][0][i] = cube[2][0][i];
			for (int i = 0; i < 3; i++)  // 왼 -> 아래 
				cube[2][0][i] = cube[4][2][2-i];
			for (int i = 0; i < 3; i++)  // 앞 -> 왼
				cube[4][2][i] = temp[0][i];
		}
		else if (idx == 3)  // 뒷면 
		{
			for (int i = 0; i < 3; i++)  // 아래 복사 
				temp[0][i] = cube[2][2][i];
			for (int i = 0; i < 3; i++)  // 오 -> 아래
				cube[2][2][i] = cube[5][2][i];
			for (int i = 0; i < 3; i++)  // 위 -> 오
				cube[5][2][i] = cube[0][0][2-i];
			for (int i = 0; i < 3; i++)  // 왼 -> 위
				cube[0][0][i] = cube[4][0][i];
			for (int i = 0; i < 3; i++)  // 아래 -> 왼
				cube[4][0][2-i] = temp[0][i];
		}
		else if (idx == 0)  // 윗면 
		{
			for (int i = 0; i < 3; i++)    // 뒷면 저장
				temp[0][i] = cube[3][2][i];
			for (int i = 0; i < 3; i++)    // 오 -> 뒤
				cube[3][2][i] = cube[5][2 - i][2];
			for (int i = 0; i < 3; i++)    // 앞 -> 오
				cube[5][i][2] = cube[1][0][i];
			for (int i = 0; i < 3; i++)    // 왼 -> 앞
				cube[1][0][i] = cube[4][i][2];
			for (int i = 0; i < 3; i++)    // 왼 -> 뒤
				cube[4][2-i][2] = temp[0][i];
		}
		else // 아래면 
		{
			for (int i = 0; i < 3; i++)    // 앞면 저장
				temp[0][i] = cube[1][2][i];
			for (int i = 0; i < 3; i++)    // 오 -> 앞
				cube[1][2][i] = cube[5][i][0];
			for (int i = 0; i < 3; i++)    // 뒤 -> 오
				cube[5][i][0] = cube[3][0][2 - i];
			for (int i = 0; i < 3; i++)    // 왼 -> 뒤
				cube[3][0][i] = cube[4][2 - i][0];
			for (int i = 0; i < 3; i++)    // 앞 -> 왼
				cube[4][i][0] = temp[0][i];
		}
	}
}
void clear()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cube[0][i][j] = 'w';
			cube[1][i][j] = 'r';
			cube[2][i][j] = 'y';
			cube[3][i][j] = 'o';
			cube[4][i][j] = 'g';
			cube[5][i][j] = 'b';
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	string s;
	int idx = 0, direct = 0;
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		clear();
		for (int j = 0; j < n; j++)
		{
			cin >> s;
			if (s[0] == 'U')
				idx = 0;
			else if (s[0] == 'F')
				idx = 1;
			else if (s[0] == 'D')
				idx = 2;
			else if (s[0] == 'B')
				idx = 3;
			else if (s[0] == 'L')
				idx = 4;
			else
				idx = 5;

			if (s[1] == '+')
				direct = 1;
			else 
				direct = -1;
			rotate(idx, direct);
		}
		print(0);
		
	}
	return 0;
}