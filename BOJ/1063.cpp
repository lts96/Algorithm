#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int n;
int arr[8][8];
int a, b, c, d;
int dx[8] = {0,0,1,-1,-1,-1 ,1,1};
int dy[8] = {1,-1,0,0,1 ,-1,1,-1};
void move(int i)
{
	a += dx[i];
	b += dy[i];
	int flag = 0;
	if ((a == c) && (b ==d))
	{
		c += dx[i];
		d += dy[i];
		flag++;
	}
	if ((a >= 0) && (a <= 7))
	{
		if ((b >= 0) && (b <= 7))
		{
			if ((c >= 0) && (c <= 7))
			{
				if ((d >= 0) && (d <= 7))
				{
					return;
				}
			}
		}
	}
	if (flag > 0)
	{
		c -= dx[i];
		d -= dy[i];
	}
	a -= dx[i];
	b -= dy[i];
	return;
}

int main(void)  
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2 >> n;
	char c1 = s1[0]-65;
	char c2 = -s1[1]+56;
	char c3 = s2[0]-65;
	char c4 = -s2[1]+56;
	a = (int)c2;
	b = (int)c1;
	c = (int)c4;
	d = (int)c3;
	string s;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "R")
			input = 0;
		else if (s == "L")
			input = 1;
		else if (s == "B")
			input = 2;
		else  if (s == "T")
			input = 3;
		else if (s == "RT")
			input = 4;
		else if (s == "LT")
			input = 5;
		else if (s == "RB")
			input = 6;
		else if (s == "LB")
			input = 7;
		move(input);
		//cout << a << b << c << d << endl;
	}
	c1 = c2 = c3 = c4 = 0;
	c1 = b + 65;
	c3 = d + 65;
	c2 = -a + 56;
	c4 = -c + 56;
	s1[0] = c1;
	s1[1] = c2;
	s2[0] = c3;
	s2[1] = c4;
	cout << s1 << endl;
	cout << s2 << endl;
	//system("pause");
	return 0;
}