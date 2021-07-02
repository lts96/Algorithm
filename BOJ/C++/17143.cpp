#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <list>
using namespace std;
int r, c, m;
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,1,-1 };
int arr[101][101];  
int arr_copy[101][101];
vector<int> v[101][101];
int ans;
int shark[10001][5];   // 0은 크기  1은 속력  2는 방향 3,4는 좌표 
void fishing(int idx)
{
	for (int i = 1; i <= r; i++)
	{
		if (arr[i][idx] > 0)
		{
			ans += arr[i][idx];
			for(int j=0; j<5; j++)  // 잡힌 상어 정보 초기화 
				shark[arr[i][idx]][j] = 0;
			arr[i][idx] = 0;
			break;
		}
	}
	return;
}
void print()
{
	cout << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return;
}
void moving()
{
	int n;
	int speed, dist ,weight;
	int x,y,nx, ny;
	int target;
	for (int i = 1; i <= 10000; i++)
	{
		if (shark[i][0] == 0)
			continue;
		dist = shark[i][2];
		weight = shark[i][0];
		x = shark[i][3];
		y = shark[i][4];
		arr[x][y] = 0;
		if (dist < 2)
			n = r;
		else
			n = c;
		speed = shark[i][1] % ((n-1) * 2);
		//cout << weight << " " << speed << " " << x << " " << y << endl;
		while (speed != 0)
		{
			// 방향 전환 
			if (dist < 2)
			{
				if (dist == 0 && x == 1)
					dist++;
				else if(dist == 1 && x == r)
					dist--;
			}
			else if (dist >= 2)
			{
				if (dist == 2 && y == c)
					dist++;
				else if(dist == 3 && y == 1)
					dist--;
			}
			x += dx[dist];
			y += dy[dist];
			speed--;
		}
		nx = x;
		ny = y;
		//cout << weight << " " << speed << " " << nx << " " << ny << endl;
		shark[i][2] = dist;
		shark[i][3] = nx;
		shark[i][4] = ny;
		if (arr_copy[nx][ny] < weight)
		{
			target = arr_copy[nx][ny];
			for (int j = 0; j < 5; j++)  
				shark[target][j] = 0;
			arr_copy[nx][ny] = weight;
		}
		else
		{
			for (int j = 0; j < 5; j++)
				shark[weight][j] = 0;
		}
	}
	


	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			arr[i][j] = arr_copy[i][j];
			arr_copy[i][j] = 0;
		}
	}


	return;
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> m;
	int x,y, s, d, z;
	for (int i = 0; i < m; i++)
	{
		cin >>x >> y >> s >> d >> z;
		arr[x][y] = z;
		shark[z][0] = z;
		shark[z][1] = s;
		shark[z][2] = d-1;
		shark[z][3] = x;
		shark[z][4] = y;
	}
	for (int i = 1; i <= c; i++)
	{
		fishing(i);
		//print();
		moving();
		//print();
	}
	cout << ans << "\n";
	return 0;
}