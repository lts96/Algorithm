#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 9999999999;
int visit[6];
int m,n,k;
int arr[51][51], arr_copy[51][51];
int info[6][3];
void rotate(int r, int c, int s)
{
	int temp1, temp2;
	for (int d = 1; d <= s; d++)
	{
		temp1 = arr[r - d][c + d];
		// 위부터
		for (int i = c + d; i > c - d; i--)
			arr[r - d][i] = arr[r - d][i - 1];
		// 왼쪽 
		for (int i = r - d; i < r + d ; i++)
			arr[i][c - d] = arr[i + 1][c - d];
		// 아래
		for (int i = c - d; i < c + d ; i++)
			arr[r + d][i] = arr[r + d][i + 1];
		temp2 = arr[r - d][c + d];
		arr[r - d][c + d] = temp1;
		for (int i = r + d; i > r - d; i--)
			arr[i][c + d] = arr[i - 1][c + d];
		arr[r - d][c + d] = temp2;
	}
	return;
}
void select(int c)
{
	int index, temp;
	if (c == k)
	{
		//순서대로 회전 
		for (int i = 0; i < k; i++)
		{
			index = visit[i];
			if (index)
				rotate(info[index-1][0], info[index-1][1], info[index-1][2]);
		}
		// 배열 값 계산 
		for (int i = 1; i <= m; i++)
		{
			temp = 0;
			for (int j = 1; j <= n; j++)
				temp += arr[i][j];
			ans = min(ans, temp);
		}

		// 원래 배열 복원
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				arr[i][j] = arr_copy[i][j];
		}
		return;
	}
	for (int i = 0; i < k; i++)
	{
		if (!visit[i])
		{
			visit[i] = c+1;
			select(c + 1);
			visit[i] = 0;
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			arr_copy[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < k; i++)
		cin >> info[i][0] >> info[i][1] >> info[i][2];
	select(0);
	cout << ans << "\n";
	return 0;
}