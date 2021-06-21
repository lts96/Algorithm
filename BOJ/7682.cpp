#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int board[3][3];
int arr[3][3];
vector <pair<int, int>> xpos;
vector <pair<int, int>> opos;
int cnt;
bool boardline()  // 완성된게 있나 검사 
{
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			if (board[i][0] != 0)
				return true;
		}
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			if (board[0][i] != 0)
				return true;
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		if (board[0][0] != 0)
			return true;
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
	{
		if (board[1][1] != 0)
			return true;
	}
	return false;
}
bool line()  // 완성된게 있나 검사 
{
	for (int i = 0; i < 3; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
		{
			if (arr[i][0] != 0)
				return true;
		}
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			if (arr[0][i] != 0)
				return true;
		}
	}
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
	{
		if (arr[0][0] != 0)
			return true;
	}
	if ((arr[2][0] == arr[1][1]) && (arr[1][1] == arr[0][2]))
	{
		if (arr[1][1] != 0)
			return true;
	}
	return false;
}
bool check()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != arr[i][j])
				return false;
		}
	}
	return true;
}
bool tictaktoe(int d)
{
	bool result = false;
	if (d == cnt)
		return check();
	if (d % 2 == 0)  // x 둘 차례 
	{
		int x, y;
		for (int i = 0; i < xpos.size(); i++)
		{
			x = xpos[i].first;
			y = xpos[i].second;
			if (arr[x][y] != 0)
				continue;
			arr[x][y] = 1;
			if (line())
			{
				if (check())
				{
					arr[x][y] = 0;
					return true;
				}
				else
				{
					arr[x][y] = 0;
					continue;
				}
			}
			result |= tictaktoe(d + 1);
			arr[x][y] = 0;	
		}
	}
	else    // O 차례 
	{
		int x, y;
		for (int i = 0; i < opos.size(); i++)
		{
			x = opos[i].first;
			y = opos[i].second;
			if (arr[x][y] != 0)
				continue;
			arr[x][y] = 2;
			if (line())
			{
				if (check())
				{
					arr[x][y] = 0;
					return true;
				}
				else
				{
					arr[x][y] = 0;
					continue;
				}
			}
			result |= tictaktoe(d + 1);
			arr[x][y] = 0;
		}
	}
	return result;
}
bool empty()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
				return true;
		}
	}
	return false;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s , ans;
	while (1)
	{
		cin >> s;
		cnt = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				arr[i][j] = board[i][j] = 0;
		}
		if (s.compare("end") == 0)
			break;
		for (int i = 0; i < 9; i++)
		{
			if (s[i] == 'X')
			{
				board[i / 3][i % 3] = 1;
				xpos.push_back(make_pair(i / 3, i % 3));
				cnt++;
				cnt1++;
			}
			else if (s[i] == 'O')
			{
				board[i / 3][i % 3] = 2;
				opos.push_back(make_pair(i / 3, i % 3));
				cnt++;
				cnt2++;
			}
		}
		if (cnt1 < 3 && cnt2 < 3 || cnt2 > cnt1)
		{
			cout << "invalid\n";
			xpos.clear();
			opos.clear();
			continue;
		}
		if (cnt1 == cnt2 && boardline() == false)
		{
			cout << "invalid\n";
			xpos.clear();
			opos.clear();
			continue;
		}
		if (boardline()== false && empty() == true)
		{
			cout << "invalid\n";
			xpos.clear();
			opos.clear();
			continue;
		}
		if (tictaktoe(0))
			cout << "valid\n";
		else
			cout << "invalid\n";
		xpos.clear();
		opos.clear();
	}
	return 0;
}