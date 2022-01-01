#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int arr[51][51][3];
int temp[51][51][6];
// cnt[i][j][0]은 해당 위치에서 파이어볼 개수
// cnt[i][j][1]은 방향이 홀수인 파이어볼 개수
// cnt[i][j][2]은 방향이 짝수인 파이어볼 개수
int cnt[51][51][3];
int n, m, k, ans;
int dx[8] = { -1, -1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
void print()
{
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j][0] << " ";
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << cnt[i][j][0] << " ";
		cout << "\n";
	}
	return;
}
// 계속 틀렸던 이유 
// 이동할때 현재 내 위치와 n이 같으면 0번째 인덱스로 이동하는 오류 있었음 -> 이동하는 부분 수정
// 그리고 분열할때 먼저 분열한 파이어볼때문에 개수가 엉키는 오류가 있었음 -> temp로 개수까지 옮겨서 계산해서 해결
void move()
{
	int dist, speed, x, y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j][0] && (cnt[i][j][0] == 4)) // 4개로 퍼지는 부분
			{
				for (int k = 0; k < 4; k++)
				{
					if (cnt[i][j][1] == 0 || cnt[i][j][2] == 0)
						dist = k * 2;
					else
						dist = k * 2 + 1;
					speed = arr[i][j][1];
					x = i + dx[dist] * speed;
					y = j + dy[dist] * speed;
					if (x > n)
					{
						x %= n;
						if (x == 0)
							x = n;
					}
					else if (x < 1)
						x = n - (abs(x) % n);
					if (y > n)
					{
						y %= n;
						if (y == 0)
							y = n;
					}
					else if (y < 1)
						y = n - (abs(y) % n);
					temp[x][y][0] += (arr[i][j][0] / 4);  // 질량 더해줌
					temp[x][y][1] += arr[i][j][1];  // 속도 더해줌
					temp[x][y][2] = dist;   // 방향 그대로
					temp[x][y][3]++;
					if (dist % 2 != 0)   // 방향이 홀수면
						temp[x][y][4]++;
					else            // 방향이 짝수면 
						temp[x][y][5]++;
				}
			}
			else if (arr[i][j][0] && cnt[i][j][0] != 4)
			{
				dist = arr[i][j][2];
				speed = arr[i][j][1];
				x = i + dx[dist] * speed;
				y = j + dy[dist] * speed;
				if (x > n)
				{
					x %= n;
					if (x == 0)
						x = n;
				}
				else if (x < 1)
					x = n - (abs(x) % n);
				if (y > n)
				{
					y %= n;
					if (y == 0)
						y = n;
				}
				else if (y < 1)
					y = n - (abs(y) % n);
				temp[x][y][0] += arr[i][j][0];  // 질량 더해줌
				temp[x][y][1] += arr[i][j][1];  // 속도 더해줌
				temp[x][y][2] = arr[i][j][2];   // 방향 그대로
				temp[x][y][3]++;
				if (dist % 2 != 0)   // 방향이 홀수면
					temp[x][y][4]++;
				else            // 방향이 짝수면 
					temp[x][y][5]++;
			}
		}
	}
	// 중복을 막기 위해 temp로 옮겼던 값들 다시 업데이트
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (k < 3)
					arr[i][j][k] = temp[i][j][k];
				else
					cnt[i][j][k - 3] = temp[i][j][k];
				temp[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cnt[i][j][0] >= 2)
			{
				arr[i][j][0] /= 5;
				if (arr[i][j][0] == 0)  // 파이어볼 소멸 
				{
					// 전부 초기화
					for (int k = 0; k < 3; k++)
					{
						arr[i][j][k] = 0;
						cnt[i][j][k] = 0;
					}
				}
				else
				{
					arr[i][j][0] *= 4;
					arr[i][j][1] /= cnt[i][j][0];
					cnt[i][j][0] = 4;
				}
			}
			else
			{
				for (int k = 0; k < 3; k++)
					cnt[i][j][k] = 0;
			}
		}
	}
	//print();
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	int a, b, c, d, e;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d >> e;
		arr[a][b][0] = c;    // 질량 
		arr[a][b][1] = d;	 // 속도 
		arr[a][b][2] = e;    // 방향
	}
	for (int i = 0; i < k; i++)
	{
		//cout << "move : " << i << endl;
		//print();
		move();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j][0])
				ans += arr[i][j][0];
		}
	}
	cout << ans << "\n";
	return 0;
}
