#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
# define diff 65
int r, c, ans;
char arr[21][21];
bool alpha[26];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
// dfs로 끝까지 가면서 백트래킹으로 select 했다가 풀었다가 하는 문제 
// 이런 유형이 은근 자주 나오니 문제의 형식이나 패턴을 기억해두면 좋을거 같다 
void dfs(int x, int y, int select)
{
	int nx, ny, idx;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		idx = arr[nx][ny] - diff;
		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			if (!alpha[idx])
			{
				alpha[idx] = true;
				dfs(nx, ny, select + 1);
				alpha[idx] = false;
			}
		}
	}
	ans = max(ans, select);
	return;
}
int main(void)
{
	cin >> r >> c;
	string str;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < c; j++)
			arr[i][j] = str[j];
	}
	alpha[arr[0][0] - diff] = true;
	dfs(0, 0, 1);
	cout << ans << endl;
	return 0;
}
