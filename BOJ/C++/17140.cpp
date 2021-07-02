#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int r,c,k, ans, x,y;  // x 행의 개수 y 열의 개수
int arr[100][100];
bool check()
{
	if (arr[r - 1][c - 1] == k)
		return true;
	return false;
}
void print()
{
	cout << "\n";
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "행 : " << x << " 열 : " << y << "\n";
	return;
}
void operationR()
{
	int length = 0;
	vector <pair <int, int>> v;
	int cnt[201];
	int t1, t2;
	for (int i = 0; i < x; i++)
	{
		for (int k = 0; k <= 200; k++)
			cnt[k] = 0;
		for (int j = 0; j < y; j++)
		{
			if (arr[i][j] > 0)
				cnt[arr[i][j]]++;
		}
		for (int k = 1; k <= 200; k++)
		{
			if (cnt[k] > 0)
				v.push_back(make_pair(cnt[k], k));
		}
		sort(v.begin(), v.end());
		int s = v.size();
		if (s > 50)
			s = 50;
		length = max(s * 2, length);
		int last = 0;
		for (int k = 0; k < s; k++)
		{
			t1 = v[k].first;
			t2 = v[k].second;
			arr[i][k * 2] = t2;
			arr[i][k * 2 + 1] = t1;
			last = k * 2 + 1;
		}
		for (int k = last+1; k < 100; k++)
			arr[i][k] = 0;
		v.clear();
	}
	y = length;
	return;
}
void operationC()
{
	int length = 0;
	vector <pair <int, int>> v;
	int cnt[201];
	int t1, t2;
	for (int j = 0; j < y; j++)
	{
		for (int k = 0; k <= 200; k++)
			cnt[k] = 0;
		for (int i = 0; i < x; i++)
		{
			if (arr[i][j] > 0)
				cnt[arr[i][j]]++;
		}
		for (int k = 1; k <= 200; k++)
		{
			if (cnt[k] > 0)
				v.push_back(make_pair(cnt[k], k));
		}
		sort(v.begin(), v.end());
		int s = v.size();
		if (s > 50)
			s = 50;
		length = max(s * 2, length);
		int last = 0;
		for (int k = 0; k < s; k++)
		{
			t1 = v[k].first;
			t2 = v[k].second;
			arr[k * 2][j] = t2;
			arr[k * 2 + 1][j] = t1;
			last = k * 2 + 1;
		}
		for (int k = last+1; k < 100; k++)
			arr[k][j] = 0;
		v.clear();
	}
	x = length;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	x = y = 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		if (ans > 100)
			break;
		if (check())
		{
			cout << ans << "\n";
			return 0;
		}
		if (x >= y)
			operationR();
		else
			operationC();
		//print();
		ans++;
	}
	cout << -1 << "\n";
	return 0;
}