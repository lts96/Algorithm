#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n,k, up, down;
int arr[201];  // 벨트 내구도
bool robot[201];  // 로봇 위치체크 
void rotate()
{
	if (up == 0)
		up = 2 * n - 1;
	else
		up--;
	if (down == 0)
		down = 2 * n - 1;
	else
		down--;
	return;
}
void moveRobot()
{
	int next;
	if (down > up)
	{
		for (int i = down; i >= up; i--)
		{
			if (robot[i])
			{
				if (i == down)   // 내려가는 위치면 로봇 제거
					robot[i] = false;
				else 
				{
					if (arr[i + 1] > 0 && !robot[i+1])  // 내려가는 위치가 아니고 내구도 남아있으면
					{
						if (i + 1 != down)
							robot[i + 1] = true;
						robot[i] = false;
						arr[i + 1]--;
					}
				}
			}
		}
	}
	else
	{
		for (int i = down; i >= 0; i--)
		{
			if (robot[i])
			{
				if (i == down)   // 내려가는 위치면 로봇 제거
					robot[i] = false;
				else
				{
					if (arr[i + 1] > 0 && !robot[i + 1])  // 내려가는 위치가 아니고 내구도 남아있으면
					{
						if(i + 1 != down)
							robot[i + 1] = true;
						robot[i] = false;
						arr[i + 1]--;
					}
				}
			}
		}
		for (int i = 2 * n - 1; i >= up; i--)
		{
			if (robot[i])
			{
				if (i == 2 * n - 1)
				{
					if (arr[0] > 0 && !robot[0])
					{
						if (0 != down)
							robot[0] = true;
						robot[2 * n - 1] = false;
						arr[0]--;
					}
				}
				else
				{
					if (arr[i + 1] > 0 && !robot[i + 1])
					{
						if (i + 1 != down)
							robot[i + 1] = true;
						robot[i] = false;
						arr[i + 1]--;
					}
				}
			}
		}
	}
	return;
}
void setRobot(int p)
{
	if (robot[p] == false && arr[p] > 0)
	{
		robot[p] = true;
		arr[p]--;
	}
	return;
}
int check()
{
	int result = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (arr[i] == 0)
			result++;
	}
	return result;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int ans = 0;
	up = 0;
	down = n-1;
	for (int i = 0; i < 2 * n; i++)
		cin >> arr[i];
	while (1)
	{
		ans++;
		rotate();
		moveRobot();
		setRobot(up);
		/*
		cout << "up : " << up << " down : " << down << " ans : " << ans << "\n";
		for (int i = 0; i < 2 * n; i++)
			cout << arr[i] << " ";
		cout << endl;
		*/
		if (check() >= k)
			break;
	}

	cout << ans << "\n";
	return 0;
}