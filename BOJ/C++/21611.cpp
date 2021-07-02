#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int arr[51][51];
int magic[101][2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m, ans;
void print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return;
}
void pull()
{
	int x = (n - 1) / 2, y = (n - 1) / 2;
	int s = 1, nx, ny;
	int idx = 0;
	int dx2[4] = {0,1,0,-1};
	int dy2[4] = {-1,0,1,0};

	// 값이 0이 아닌 블록 저장용
	vector <int> v;
	while (x >= 0 && x <n && y >= 0 && y < n)
	{
		for (int i = 1; i <= s; i++)
		{
			nx = x + dx2[idx] * i;
			ny = y + dy2[idx] * i;
			//cout << s << " [" << nx << " " << ny  << "] " << arr[nx][ny] << endl;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] > 0)
					v.push_back(arr[nx][ny]);
			}
		}
		x = nx;
		y = ny;
		if (idx % 2 != 0)  
			s++;
		idx++;
		if (idx >= 4)
			idx %= 4;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	
	x = (n - 1) / 2;
	y = (n - 1) / 2;
	s = 1, idx = 0;
	int cnt = 0;
	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		for (int i = 1; i <= s; i++)
		{
			nx = x + dx2[idx] * i;
			ny = y + dy2[idx] * i;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if(cnt < v.size())
					arr[nx][ny] = v[cnt];
				cnt++;
			}
		}
		x = nx;
		y = ny;
		if (idx % 2 != 0)
			s++;
		idx++;
		if (idx >= 4)
			idx %= 4;
	}
	//print();
	v.clear();
	return;
}
void destroy(int d, int s)
{
	int x = (n-1)/2, y = (n-1)/2;
	int nx, ny;
	for (int i = 1; i <= s; i++)
	{
		nx = x + (dx[d] * i);
		ny = y + (dy[d] * i);
		arr[nx][ny] = 0;
	}
	pull();
	return;
}
bool check()
{
	bool flag = false;
	int x = (n - 1) / 2, y = (n - 1) / 2;
	int s = 1, nx, ny;
	int idx = 0;
	int dx2[4] = { 0,1,0,-1 };
	int dy2[4] = { -1,0,1,0 };
	vector <int> v;
	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		for (int i = 1; i <= s; i++)
		{
			nx = x + dx2[idx] * i;
			ny = y + dy2[idx] * i;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] > 0)
					v.push_back(arr[nx][ny]);
			}
		}
		x = nx;
		y = ny;
		if (idx % 2 != 0)
			s++;
		idx++;
		if (idx >= 4)
			idx %= 4;
	}
	int prev = -1;
	int cnt = 1;
	int score = 0;
	vector <int> v2;
	for (int i = 0; i < v.size(); i++)  //연속하는 블록 찾기 
	{
		if (v[i] != prev)
		{
			prev = v[i];
			cnt = 1;
		}
		else
			cnt++;
		if (i == v.size() - 1)
		{
			v2.push_back(cnt);
			if (cnt >= 4)
			{
				flag = true;
				score = v[i];
				for (int j = i; j >= i - cnt; j--)
					v[j] = 0;
				ans += (score * cnt);
			}
		}
		else if (v[i] != v[i + 1])
		{
			v2.push_back(cnt);
			if (cnt >= 4)
			{
				flag = true;
				score = v[i];
				for (int j = i; j > i - cnt; j--)
					v[j] = 0;
				ans += (score * cnt);
			}
		}
	}
	v2.clear();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
			v2.push_back(v[i]);
	}
	
	if (flag == true)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = 0;
		}

		x = (n - 1) / 2;
		y = (n - 1) / 2;
		s = 1, idx = 0;
		int cnt = 0;
		while (x >= 0 && x < n && y >= 0 && y < n)
		{
			for (int i = 1; i <= s; i++)
			{
				nx = x + dx2[idx] * i;
				ny = y + dy2[idx] * i;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (cnt < v2.size())
						arr[nx][ny] = v2[cnt];
					cnt++;
				}
			}
			x = nx;
			y = ny;
			if (idx % 2 != 0)
				s++;
			idx++;
			if (idx >= 4)
				idx %= 4;
		}
	}
	v.clear();
	v2.clear();
	return flag;
}
void change()
{
	int x = (n - 1) / 2, y = (n - 1) / 2;
	int s = 1, nx, ny;
	int idx = 0;
	int dx2[4] = { 0,1,0,-1 };
	int dy2[4] = { -1,0,1,0 };
	vector <int> v;
	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		for (int i = 1; i <= s; i++)
		{
			nx = x + dx2[idx] * i;
			ny = y + dy2[idx] * i;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] > 0)
					v.push_back(arr[nx][ny]);
			}
		}
		x = nx;
		y = ny;
		if (idx % 2 != 0)
			s++;
		idx++;
		if (idx >= 4)
			idx %= 4;
	}
	int prev = -1;
	int cnt = 1;
	int num = 0;
	vector <int> v2;
	for (int i = 0; i < v.size(); i++)  //연속하는 블록 찾기 
	{
		if (v[i] != prev)
		{
			prev = v[i];
			cnt = 1;
		}
		else
			cnt++;
		if (i == v.size() - 1)
		{
			num = v[i];
			v2.push_back(cnt);
			v2.push_back(num);
		}
		else if (v[i] != v[i + 1])
		{
			num = v[i];
			v2.push_back(cnt);
			v2.push_back(num);
		}
	}
	// 기존 배열 초기화 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}
	x = (n - 1) / 2;
	y = (n - 1) / 2;
	s = 1, idx = 0;
	cnt = 0;
	while (x >= 0 && x < n && y >= 0 && y < n)
	{
		for (int i = 1; i <= s; i++)
		{
			nx = x + dx2[idx] * i;
			ny = y + dy2[idx] * i;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (cnt < v2.size())
					arr[nx][ny] = v2[cnt];
				cnt++;
			}
		}
		x = nx;
		y = ny;
		if (idx % 2 != 0)
			s++;
		idx++;
		if (idx >= 4)
			idx %= 4;
	}
	v.clear();
	v2.clear();
	return;
}
void run()
{
	for (int i = 0; i < m; i++)
	{
		destroy(magic[i][0]-1, magic[i][1]);
		while (1)
		{
			if (!check())
				break;
			//print();
		}
		change();
		//print();
	}
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
	for (int i = 0; i < m; i++)
		cin >> magic[i][0] >> magic[i][1];
	run();
	cout << ans << "\n";
	return 0;
}