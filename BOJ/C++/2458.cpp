#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n, m, ans;
int arr[501][501];
#define INF 210000000
/*
플로이드 쓰면 쉽게 풀리는 문제
내가 방문 가능한 노드 개수 + 나를 방문한 노드 개수 - 1 (자기자신 제외)를 구하면 됨
플로이드로 한번 돌면 해결
왜 플로이드에선 가운데 노드가 항상 3중 포문 제일 위에 있어야 하는가? -> 알아보기
*/
void floyd()
{	
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a-1][b-1] = 1;
	}
	floyd();
	int cnt;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] > 0 && arr[j][i] < INF)
				cnt++;
		}
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 0 && arr[i][j] < INF)
				cnt++;
		}
		if (cnt == n - 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
