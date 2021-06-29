#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
using namespace std;
int n, m;
string cache[101][101];

string add(string a, string b)
{
	int diff = a.size() - b.size();
	int num1, num2, temp;
	int idx = 0;
	int arr[40];
	char c;
	for (int i = 0; i < 40; i++)
		arr[i] = 0;
	string ret;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = b.size(); i < a.size(); i++)
		arr[i] = a[i] - 48;
	for (int i = 0; i < b.size(); i++)
	{
		num1 = a[i] - 48;
		num2 = b[i] - 48;
		arr[i] += (num1 + num2);
		if (arr[i] >= 10)
		{
			arr[i + 1]++;
			arr[i] %= 10;
		}
	}
	for (int i = 0; i <= a.size(); i++)
	{
		if (arr[i] >= 10)
		{
			arr[i + 1]++;
			arr[i] %= 10;
		}
	}

	int p = 39;
	bool flag = false;
	while (p >= 0)
	{
		if (arr[p] != 0)
			flag = true;
		if (flag)
		{
			c = arr[p] + 48;
			ret.append(1, c);
		}
		p--;
	}
	return ret;
}

string dp(int x, int y)
{
	if (y > x || x < 1 || y < 1)
		return "0";
	if (cache[x][y] != "-1")
		return cache[x][y];
	string s1 = dp(x - 1, y);
	string s2 = dp(x - 1, y - 1);
	string ret = "";
	if(s1.size() >= s2.size())
		ret = add(s1 , s2);
	else 
		ret = add(s2, s1);
	return cache[x][y] = ret;
}
int main(void)
{
	cin >> n >> m;
	if (m > 50)
		m = 100 - m;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (i == j)
				cache[i][j] = "1";
			else
				cache[i][j] = "-1";
			if (j == 1)
				cache[i][j] = to_string(i);
		}
	}
	cout << dp(n, m) << "\n";
	return 0;
}