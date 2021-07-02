#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int n, m;
int ans;
int arr[21][21];
int arr_copy[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[21][21];
queue <pair <int, int>> q;
vector <pair<pair <int, int>, pair <int, int >>> v;
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

void bfs(int num)
{
	int x, y, cnt = 1, rcnt = 0, nx, ny, s;
	int color,cx,cy;
	color = num;
	// 중심 찾기용 배열 
	vector <pair <int, int>> v2;
	bool visit2[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit2[i][j] = false;
		}
	}
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		if(arr[x][y]!= 0)
			v2.push_back(make_pair(x, y));
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				//무지개 블록은 다른 블록 그룹도 써야하므로 방문 처리 별도
				if (arr[nx][ny] == 0 && !visit2[nx][ny])
				{
					rcnt++;
					visit2[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (arr[nx][ny] == color && !visit[nx][ny])
				{
					visit[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	if (cnt >= 1 && (cnt + rcnt >= 2))
	{
		cx = v2[0].first;
		cy = v2[0].second;
		v.push_back(make_pair(make_pair(cnt + rcnt, rcnt), make_pair(cx, cy)));
	}
	v2.clear();
	return;
}
bool find_group()
{
	int x, y, cnt, rcnt;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			visit[i][j] = false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				if (arr[i][j] < 0)
					continue;
				else if (arr[i][j] > 0)
				{
					visit[i][j] = true;
					q.push(make_pair(i, j));
					bfs(arr[i][j]);
				}
			}
		}
	}

	if (v.size() == 0)
		return false;
	else 
		return true;
}
void fall() //이상 무 
{
	int cnt;
	int arr3[21][21];
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if(arr[i][j] != -1)
				arr_copy[i][j] = -2;
			else 
				arr_copy[i][j] = -1;
			arr3[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cnt = 0;
			if (arr[i][j] == -1 || arr[i][j] == -2)
				continue;
			for (int k = i + 1; k < n; k++)
			{
				if (arr[k][j] == -1)
					break;
				if (arr[k][j] == -2) // 빈 공간일때
					cnt++;
			}
			arr3[i][j] = cnt;
			arr_copy[i + cnt][j] = arr[i][j];
		}
	}


	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			arr[i][j] = arr_copy[i][j];
	}

	return;
}
void rotate() // 이상 무 
{
	// 반시계 회전 식  기억하기  x -> n-1-y , y -> x
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			arr_copy[i][j] = -2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr_copy[n-1-j][i] = arr[i][j];
	}
	
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			arr[i][j] = arr_copy[i][j];
	}
	return;
}
void run()
{
	sort(v.begin(), v.end());
	/*
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;
	*/
	int tx, ty, color, x, y, nx, ny, cnt = 0;
	tx = v[v.size() - 1].second.first;
	ty = v[v.size() - 1].second.second;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			visit[i][j] = false;
	}
	color = arr[tx][ty];
	arr[tx][ty] = -2;
	visit[tx][ty] = true;
	cnt++;
	q.push(make_pair(tx, ty));
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if ((arr[nx][ny] == 0 || arr[nx][ny] == color)&& !visit[nx][ny])
				{
					visit[nx][ny] = true;
					arr[nx][ny] = -2;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	ans += (cnt * cnt);
	//print();
	fall();
	rotate();
	fall();
	//print();
	v.clear();
	return;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		if (find_group())
		{
			run();
		}
		else
			break;
	}
	cout << ans << "\n";
	return 0;
}