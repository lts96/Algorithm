#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int arr[21][21];
int n, m, k, ans;
int dx[4] = { 0,1,0,-1};
int dy[4] = { 1,0,-1,0};
int direction, px, py;
// dice_x[1] 이 윗면 , dice_x[3]이 아랫면
int dice_x[4] = {4, 1, 3, 6};
int dice_y[4] = {2, 1, 5, 6};
void print()
{
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
void print_dice()
{
	cout << endl;
	cout << dice_y[0] << endl;
	for (int i = 0; i < 3; i++)
		cout << dice_x[i] << " ";
	cout << endl;
	cout << dice_y[2] << endl;
	cout << dice_y[3] << endl;
	return;
}
int get_score(int sx, int sy, int target)
{
	queue <pair <int, int>> q;
	bool visit[21][21];
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
			visit[i][j] = false;
	}
	q.push({ sx, sy });
	visit[sx][sy] = true;
	int ret = 1, x,y, nx,ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == target && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					q.push({ nx, ny });
					ret++;
				}
			}
		}
	}
	return ret * target;
}
void move()
{
	// px py = 주사위의 현재 위치
	int nx = px + dx[direction];
	int ny = py + dy[direction];
	int temp;
	// 이동 가능할때
	if (nx >= 0 && nx < n && ny >= 0 && ny < m)
	{
		px = nx;
		py = ny;
	}
	else // 판에서 벗어날때
	{
		direction += 2;
		direction %= 4;
		px = px + dx[direction];
		py = py + dy[direction];
	}
	// 주사위 숫자 갱신 
	if (direction % 2 == 0)
	{
		// 동쪽으로 갈때
		if (direction == 0)
		{
			temp = dice_x[3];
			for (int i = 3; i >= 1; i--)
				dice_x[i] = dice_x[i - 1];
			dice_x[0] = temp;
			dice_y[1] = dice_x[1];
			dice_y[3] = dice_x[3];
		}
		else
		{
			temp = dice_x[0];
			for (int i = 0; i < 3; i++)
				dice_x[i] = dice_x[i + 1];
			dice_x[3] = temp;
			dice_y[1] = dice_x[1];
			dice_y[3] = dice_x[3];
		}
	}
	else
	{
		if (direction == 1)
		{
			temp = dice_y[3];
			for (int i = 3; i >= 1; i--)
				dice_y[i] = dice_y[i - 1];
			dice_y[0] = temp;
			dice_x[1] = dice_y[1];
			dice_x[3] = dice_y[3];
		}
		else
		{
			temp = dice_y[0];
			for (int i = 0; i < 3; i++)
				dice_y[i] = dice_y[i + 1];
			dice_y[3] = temp;
			dice_x[1] = dice_y[1];
			dice_x[3] = dice_y[3];
		}
	}
	return;
}
void change_direction(int a, int b)
{
	int temp;
	// 시계 90
	if (a > b)
	{
		direction++;
		if (direction >= 4)
			direction = 0;
	}
	// 반시계 90
	else if (a < b)
	{
		direction--;
		if (direction < 0)
			direction = 3;
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < k; i++)
	{
		move();
		ans += get_score(px, py, arr[px][py]);
		change_direction(dice_x[3], arr[px][py]);
		//print_dice();
		//cout << direction << endl;
	}
	cout << ans << "\n";
	return 0;
}
