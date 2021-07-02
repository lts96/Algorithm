#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[500][500];
int cx, cy, ans;
int dx[4] = {0,1,0,-1};
int dy[4] = { -1,0,1,0};
int total;
// 왼쪽 0  아래 1 오른쪽 2 위 3
// 1칸씩 이동해야됨 
void sand(int x, int y, int v, int percent)
{
	if ((x >= 0 && x < n) && (y >= 0 && y < n))
		arr[x][y] += (v * percent) / 100;
	return;
}
void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}
void tornado(int x1, int y1, int x2, int y2, int d)
{
	//cout << x2 << " " << y2 << endl;
	int temp = arr[x2][y2];   // 현재 중심 모래 = y 
	arr[x2][y2] = 0;
	// 현재 중심 x2  y2 
	int ax = x2 + dx[d];
	int ay = y2 + dy[d];
	//sand(ax, ay, temp, 55);
	int a = temp;
	
	ax += dx[d];
	ay += dy[d];
	sand(ax, ay, temp, 5);
	a -= (temp * 5) / 100;

	ax = x2 + dx[(d + 1) % 4];
	ay = y2 + dy[(d + 1) % 4];
	sand(ax, ay, temp, 7);
	a -= (temp * 7) / 100;

	ax += dx[(d + 1) % 4];
	ay += dy[(d + 1) % 4];
	sand(ax, ay, temp, 2);
	a -= (temp * 2) / 100;

	int index = d-1;
	if (index < 0)
		index = 3;
	ax = x2 + dx[index];
	ay = y2 + dy[index];
	sand(ax, ay, temp, 7);
	a -= (temp * 7) / 100;

	ax += dx[index];
	ay += dy[index];
	sand(ax, ay, temp, 2);
	a -= (temp * 2) / 100;
	
	ax = x2 + dx[d] + dx[(d + 1) % 4];
	ay = y2 + dy[d] + dy[(d + 1) % 4];
	sand(ax, ay, temp, 10);
	a -= (temp * 10) / 100;

	ax = x2 + dx[d] + dx[index];
	ay = y2 + dy[d] + dy[index];
	sand(ax, ay, temp, 10);
	a -= (temp * 10) / 100;

	ax = x2 - dx[d] + dx[(d + 1) % 4];
	ay = y2 - dy[d] + dy[(d + 1) % 4];
	sand(ax, ay, temp, 1);
	a -= (temp * 1) / 100;

	ax = x2 - dx[d] + dx[index];
	ay = y2 - dy[d] + dy[index];
	sand(ax, ay, temp, 1);
	a -= (temp * 1) / 100;

	// a부분은 모래를 보내고 남은 것이므로 단순히 55퍼를 곱해서 만들면 안됨

	ax = x2 + dx[d];
	ay = y2 + dy[d];
	if ((ax >= 0 && ax < n) && (ay >= 0 && ay < n))
		arr[ax][ay] += a;
	//print();
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
			total += arr[i][j];
		}
	}
	cx = cy = n / 2;
	int weight = 1;
	int direct = 0;
	bool flag = false;
	int tx, ty;
	while (1)
	{
		for (int i = 0; i < weight; i++)
		{
			tx = cx;
			ty = cy;
			cx = cx + dx[direct];
			cy = cy + dy[direct];
			tornado(tx, ty , cx, cy , direct);
			if (cx <= 0 && cy <= 0)
			{
				flag = true;
				break;
			}
		}
		direct = (direct + 1) % 4;
		if (flag)
			break;
		for (int i = 0; i < weight; i++)
		{
			cx = cx + dx[direct];
			cy = cy + dy[direct];
			tornado(tx, ty, cx, cy , direct);
			if (cx <= 0 && cy <= 0)
			{
				flag = true;
				break;
			}
		}
		direct = (direct + 1) % 4;
		weight++;
		if (flag)
			break;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			total -= arr[i][j];
	}
	cout << total << "\n";
	return 0;
}
