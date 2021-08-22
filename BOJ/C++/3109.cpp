#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int r, c;
int ans[3];
char arr[10001][501];
bool visit[10001][501];
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
// 계속 틀렸던 이유 
// 정답을 재귀 내에서 갱신하면 하나의 루트에서 최대 3개까지 답이 나오게 됨 
// 그리고 방문 처리를 중간에 다시 되돌리면 시간초과나 나버림 
// 실패한 길이더라도 일단 방문했으면 그대로 둬야함 -> 어차피 다른 시작점에서 오더라도 실패할게 분명하기 때문
// 그리고 내 자식 중에서 끝까지 도달한 경우가 있으면 바로 리턴해야한다 
// 좀더 자세한건 검색 참고  
void print()
{
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
int dfs(int x, int y, int idx)
{
	if (y == c - 1)
		return 1;
	int nx, ny, ret = 0;
	for (int i = 0; i < 3; i++)
	{
		nx = x + dx[(i + idx) % 3];
		ny = y + dy[(i + idx) % 3];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
		{
			if (arr[nx][ny] != 'x' && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				ret += dfs(nx, ny, idx);
				// 이게 제일 중요 
				if (ret)
					return 1;
			}
		}
	}
	return 0;
}
int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				visit[i][j] = false;
		}
		for (int i = 0; i < r; i++)
		{
			// 하나의 길이 완전히 끝나고 나서 결과를 더해야함 
			ans[k] += dfs(i, 0, k);
		}
	}
	cout << max(max(ans[0], ans[1]), ans[2]) << endl;
	return 0;
}
