#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
int n, m , zero;
int arr[9][9];
vector <pair <int, int>> pos;
vector <pair <int, int>> center;
vector<int> set(int i);
bool isFinish();
void sdoku(int i)
{
	if (i == pos.size())
	{
		if (isFinish())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					cout << arr[i][j] << " ";
				cout << "\n";
			}
			exit(0);
		}
		return;
	}
	int x, y;
	x = pos[i].first;
	y = pos[i].second;
	vector<int> p = set(i);

	for (int j = 0; j < p.size(); j++)
	{
		arr[x][y] = p[j];
		sdoku(i + 1);
	}
	p.clear();
	arr[x][y] = 0;
	return;
}
vector<int> set(int i)  // 아직까진 정상
{
	int x = pos[i].first;
	int y = pos[i].second;
	vector <int> p;
	bool check[9];
	for (int i = 0; i < 9; i++)  // 최종적으로 여기 true라고 적힌 숫자만 세팅 가능 
		check[i] = true;
	// 가로 체크 
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][y] > 0)
			check[arr[i][y]-1] = false;
	}
	// 세로 체크 
	for (int i = 0; i < 9; i++)
	{
		if (arr[x][i] > 0)
			check[arr[x][i] - 1] = false;
	}
	// 사각형 체크  1 - 우선 가장 가까이 있는 중앙 좌표를 찾는다
	int dist = 10000;
	int cx, cy , m;
	for (int i = 0; i < 9; i++)
	{
		m = pow(abs(center[i].first - x), 2) + pow(abs(center[i].second - y), 2);
		if (dist > m)
		{
			dist = m;
			cx = center[i].first;
			cy = center[i].second;
		}
	}
	// 가장 가까운 중앙좌표를 이용해 사각형 검사 실행 
	for (int i = cx - 1; i <= cx + 1; i++)
	{
		for (int j = cy - 1; j <= cy + 1; j++)
		{
			if (arr[i][j] > 0)
				check[arr[i][j] - 1] = false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (check[i])
			p.push_back(i + 1);
	}
	return p;
}
bool isFinish()
{
	bool flag = true;
	int cnt[9];
	for (int i = 0; i < 9; i++)
		cnt[i] = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] > 0)
				cnt[arr[i][j] - 1]++;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (cnt[i] != 9)
			flag = false;
	}
	return flag;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j])
			{
				zero++;
				pos.push_back(make_pair(i, j));
			}
		}
	}
	center.push_back(make_pair(1, 1));
	center.push_back(make_pair(4, 1));
	center.push_back(make_pair(7, 1));
	center.push_back(make_pair(1, 4));
	center.push_back(make_pair(4, 4));
	center.push_back(make_pair(7, 4));
	center.push_back(make_pair(1, 7));
	center.push_back(make_pair(4, 7));
	center.push_back(make_pair(7, 7));
	sdoku(0);
	return 0;
}