#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, h, ans = -1;
vector <pair <int, int>> pos;
int arr[11][31];

inline bool test()
{
	int x, y, next;

	for (int i = 1; i <= n; i++)
	{
		x = i;
		for (int j = 1; j <= h; j++)
		{
			if (arr[x][j] != 0)
				x++;
			else if (arr[x - 1][j] != 0)
				x--;
		}
		if (x != i)
			return false;
	}
	return true;
}
void select(int c, int t)
{
	if (c == t)
	{
		if (test())
			ans = t;
		return;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			// 내 왼쪽 오른쪽 모두 비교해서 사다리가 있으면 pass 
			if ((arr[i - 1][j] > 0 || arr[i][j] > 0) || arr[i + 1][j] > 0)
				continue;
			arr[i][j] = 1;
			select(c + 1, t);
			arr[i][j] = 0;
			while (j < h) 
			{
				if (arr[i-1][j] || arr[i+1][j])
					break;
				j++;
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[b][a] = b + 1;
	}

	if (test())
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= 3; i++)
	{
		select(0, i);
		if (ans != -1)
		{
			cout << ans << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}