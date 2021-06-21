#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>
using namespace std;
int n, ans;
int direct[5];
int arr[21][21];
int arr_copy[21][21];
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
void up()
{
	// 우선 이동
	int v[21];
	int index;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 21; i++)  
			v[i] = 0;
		index = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] > 0)  // 이렇게 옮겼다가 다시 가져오면 블록을 이동시킨것과 같다
			{
				v[index] = arr[i][j];
				index++;
				arr[i][j] = 0;
			}
		}
		//print();
		index = 0;
		while (index <= n-2)  // 합치는 순서는 해당 방향 가까운거 우선 
		{
			if (v[index] > 0 && v[index] == v[index + 1])
			{
				v[index] *= 2;
				v[index + 1] = 0;
				index += 2;    // 합친걸 또 합치는 경우를 피하기 위해 +2
			}
			else
				index++;
		}
		index = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > 0)       // 이렇게 하면 0을 거르고 가져오므로 자연스럽게 합치고 이동된 형태로 들어옴
			{
				arr[index][j] = v[i];
				index++;
			}
		}
		//print();
	}
	return;
}
void down()
{
	int v[21];
	int index;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 21; i++)
			v[i] = 0;
		index = n-1;
		for (int i = n-1; i >= 0; i--)
		{
			if (arr[i][j] > 0)
			{
				v[index] = arr[i][j];
				index--;
				arr[i][j] = 0;
			}
		}
		//print();
		index = n-1;
		while (index > 0)
		{
			if (v[index] > 0 && v[index] == v[index - 1])
			{
				v[index] *= 2;
				v[index - 1] = 0;
				index -= 2;
			}
			else
				index--;
		}
		index = n - 1;
		for (int i = n-1; i >= 0; i--)
		{
			if (v[i] > 0)
			{
				arr[index][j] = v[i];
				index--;
			}
		}
		//print();
	}
	return;
}
void left()
{
	// 우선 이동
	int v[21];
	int index;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 21; j++)
			v[j] = 0;
		index = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 0)
			{
				v[index] = arr[i][j];
				index++;
				arr[i][j] = 0;
			}
		}
		//print();
		index = 0;
		while (index <= n - 2)
		{
			if (v[index] > 0 && v[index] == v[index + 1])
			{
				v[index] *= 2;
				v[index + 1] = 0;
				index += 2;
			}
			else
				index++;
		}
		index = 0;
		for (int j = 0; j < n; j++)
		{
			if (v[j] > 0)
			{
				arr[i][index] = v[j];
				index++;
			}
		}
		//print();
	}
	return;
}
void right()
{
	int v[21];
	int index;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 21; j++)
			v[j] = 0;
		index = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[i][j] > 0)
			{
				v[index] = arr[i][j];
				index--;
				arr[i][j] = 0;
			}
		}
		//print();
		index = n - 1;
		while (index > 0)
		{
			if (v[index] > 0 && v[index] == v[index - 1])
			{
				v[index] *= 2;
				v[index - 1] = 0;
				index -= 2;
			}
			else
				index--;
		}
		index = n - 1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (v[j] > 0)
			{
				arr[i][index] = v[j];
				index--;
			}
		}
		//print();
	}
	return;
}
void dfs(int d)
{
	if (d == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			if (direct[i] == 0)
				up();
			else if (direct[i] == 1)
				down();
			else if (direct[i] == 2)
				left();
			else
				right();
		}
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp = max(temp, arr[i][j]);
				arr[i][j] = arr_copy[i][j];
			}
		}
		ans = max(temp, ans);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		direct[d] = i;
		dfs(d + 1);
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr_copy[i][j] = arr[i][j];
		}
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}