#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
int n, m, k, ans;

/*
* 디버깅하기 까다로워서 문제조건을 하나하나 제대로 구현했나 꼼꼼히 읽어보는걸로 대신
* 빨간색 뒤집을때 주의점 : 기존에 쌓여있던 말의 순서는 유지된다
* 파란색 이동할때 방향 제대로 바뀌는지 확인해야함
* 2차원 벡터를 사용, 그리고 말들의 정보를 따로 벡터에 담아서 관리하는게 그나마 수월하다
*/

// 구현 문제, 문제 조건을 자세히 읽어야 실수안함 

// 현재 말들의 상태 (겹친 상태, 방향) 저장 
vector <pair <int, int>> arr[20][20];
int map[20][20];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

// 말들의 좌표를 저장 
vector <pair <int, int>> v;


int red(int x, int y, int nx, int ny, int z)
{
	int idx, d, ret = 0;
	int p = arr[x][y].size() - z;
	// 현재 배열에서 거꾸로 뽑아서 넣어준다 
	// 기존 배열에 있는 숫자는 유지되어야 한다.
	for (int i = arr[x][y].size() - 1; i >= z; i--)
	{
		idx = arr[x][y][i].first;
		d = arr[x][y][i].second;
		arr[nx][ny].push_back({ idx, d });
		v[idx].first = nx;
		v[idx].second = ny;
	}
	
	if (arr[nx][ny].size() >= 4)
		ret++;
	for (int i = 0; i < p; i++)
		arr[x][y].pop_back();
	return ret;
}
int white(int x, int y, int nx, int ny, int z)
{
	int idx, d , ret = 0;
	int p = arr[x][y].size() - z;
	// 좌표 갱신해주고 쌓인 개수만큼 다음 좌표로 옮겨준다
	for (int i = z; i < arr[x][y].size(); i++)
	{
		idx = arr[x][y][i].first;
		d = arr[x][y][i].second;
		arr[nx][ny].push_back({ idx, d });
		v[idx].first = nx;
		v[idx].second = ny;
	}

	// 말이 4개 이상 쌓였는지 체크 
	if (arr[nx][ny].size() >= 4)
		ret++;
	for (int i = 0; i < p; i++)
		arr[x][y].pop_back();
	return ret;
}
int blue(int x, int y, int nx, int ny, int z, int d)
{
	int ret = 0;
	if (d % 2 == 1)
		d++;
	else
		d--;
	int idx = arr[x][y][z].first;
	arr[x][y][z].second = d;
	nx = x + dx[d];
	ny = y + dy[d];
	// 이동한 곳이 또 블루거나 외부면 가만히 있음
	if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 2)
	{
		if (arr[x][y].size() >= 4)
			ret++;
		return ret;
	}
	else if (map[nx][ny] == 0)
		ret = white(x, y, nx, ny, z);
	else if (map[nx][ny] == 1)
		ret = red(x, y, nx, ny, z);
	return ret;
}
void run()
{
	int x, y, z = 0, nx, ny, d = 0, ret = 0;
	while (ans <= 1000)
	{
		ans++;
		for (int i = 1; i <= k; i++)
		{
			ret = 0;
			x = v[i].first;
			y = v[i].second;
			// k번 말이 arr[x][y]에서 몇번째 층에 있는지 찾는다
			for (int j = 0; j < arr[x][y].size(); j++)
			{
				if (arr[x][y][j].first == i)
				{
					z = j;
					d = arr[x][y][j].second;
					break;
				}
			}
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 2)
				ret = blue(x, y, nx, ny, z, d);
			else if (map[nx][ny] == 0)
				ret = white(x, y, nx, ny, z);
			else if (map[nx][ny] == 1)
				ret = red(x, y, nx, ny, z);
			if (ret != 0)
				break;
		}
		if (ret != 0)
			break;
	}
	if (ans > 1000)
		ans = -1;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	int a, b, c;
	v.push_back({ -1, -1 });
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c;
		arr[a - 1][b - 1].push_back({ i + 1, c });
		v.push_back({ a - 1, b - 1 });
	}
	run();
	cout << ans << "\n";
	return 0;
}
