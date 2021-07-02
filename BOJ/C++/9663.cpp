#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
int n;
int* arr;
int ans;
bool setQueen(int index) // 놔도 되는지 안되는지 판정용
{
	for (int i = 0; i < index; i++)
	{
		if (abs(arr[i] - arr[index]) == abs(i-index))
			return false;
		if (arr[i] == arr[index])
			return false;
	}
	return true;
}
void dfs(int r)
{
	if (r == n -1)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[r + 1] = i;
			if (setQueen(r + 1))
				dfs(r + 1);
			else
				arr[r + 1] = -1;
		}
	}
	arr[r] = -1;
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr = new int[n];
		arr[0] = i;
		dfs(0);
	}
	cout << ans << endl;
	return 0;
}