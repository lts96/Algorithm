#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
int arr[21][21];
int p[402][4][4];
int d[402];
int ans;
int smell[21][21][2];
int shark[402][2];   // 상어 위치 정보 저장 
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	/*
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << smell[i][j][0] << " ";
		cout << "\n";
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << smell[i][j][1] << " ";
		cout << "\n";
	}
	*/
	return;
}
void move(int time)
{
	for (int i = 0; i < n; i++)  // 자기자리에 냄새 뿌리기 
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 0)
			{
				smell[i][j][0] = arr[i][j];
				smell[i][j][1] = k;
			}
		}
	}
	int direct;
	int idx;
	int x, y;
	bool flag = false;
	int original_d;
	for (int i = 0; i < n; i++)  // 상어 이동  
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 0)
			{
				flag = false;   // 이동했는지 안했는지 체크용 
				idx = arr[i][j];
				x = i;
				y = j;
				//cout <<"before :" << x << " " << y << endl;
				original_d = d[idx];
				for (int k = 0; k < 4; k++)
				{
					x = i;
					y = j;
					direct = p[idx][d[idx]-1][k];
					if (direct == 1)
						x = i - 1;
					else if (direct == 2)
						x = i + 1;
					else if (direct == 3)
						y = j - 1;
					else if (direct == 4)
						y = j + 1;
					if (x >= 0 && x < n && y >= 0 && y < n)
					{
						if (smell[x][y][0] == 0)
						{
							shark[idx][0] = x;
							shark[idx][1] = y;
							flag = true;
							d[idx] = direct;
							//cout << "after :" <<direct <<" "<< x << " " << y << endl;
						}
					}
					if (flag)
						break;
				}
				if (!flag)
				{
					x = i;
					y = j;
					d[idx] = original_d;
					for (int k = 0; k < 4; k++)
					{
						x = i;
						y = j;
						direct = p[idx][d[idx]-1][k];
						if (direct == 1)
							x = i-1;
						else if (direct == 2)
							x = i+1;
						else if (direct == 3)
							y = j-1;
						else if (direct == 4)
							y = j + 1;
						if (x >= 0 && x < n && y >= 0 && y < n)
						{
							if (smell[x][y][0] == idx)
							{
								shark[idx][0] = x;
								shark[idx][1] = y;
								flag = true;
								d[idx] = direct;
							}
						}
						if (flag)
							break;
					}
				}
			}
			arr[i][j] = 0;
		}
	}
	// 상어 좌표 표시   
	for (int i = 1; i <= m; i++)
	{
		x = shark[i][0];
		y = shark[i][1];
		if (x == -1 && y == -1) // 이미 쫒겨난 상어
			continue;
		if (arr[x][y] == 0)
			arr[x][y] = i;
		else if (arr[x][y] > 0)
		{
			if (i < arr[x][y]) // 나보다 크면 쫒아냄 
			{
				shark[arr[x][y]][0] = -1;
				shark[arr[x][y]][1] = -1;
				arr[x][y] = i;
			}
			else // 내가 쫒겨남 
			{
				shark[i][0] = -1;
				shark[i][1] = -1;
			}
		}
	}
	// 냄새 지우기 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (smell[i][j][0] > 0)
			{
				smell[i][j][1]--;
				if (smell[i][j][1] == 0)
					smell[i][j][0] = 0;
			}
		}
	}
	return;
}
bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > 1)
				return false;
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
			{
				shark[arr[i][j]][0] = i;
				shark[arr[i][j]][1] = j;
			}
		}
	}
	int temp;
	for (int i = 1; i <= m; i++)
	{
		cin >> temp;
		d[i] = temp;
	}
	for (int k = 1; k <= m; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cin >> p[k][i][j];
		}
	}
	for (int i = 1; i <= 1000; i++)
	{
		move(i);
		if (check())
		{
			ans = i;
			break;
		}
		//cout << "time : " << i << "\n";
		//print();
	}
	if (ans == 0)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}