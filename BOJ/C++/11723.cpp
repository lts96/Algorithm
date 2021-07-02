#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
int s;
int convert(int x)
{
	int temp = 1;
	for (int i = 0; i < x; i++)
		temp = temp << 1;
	return temp;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int m , x , index;
	string str;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (!str.compare("add"))
		{
			cin >> x;
			index = convert(x);
			s |= index;
		}
		else if (!str.compare("check"))
		{
			cin >> x;
			index = convert(x);
			if (s & index)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!str.compare("remove"))
		{
			cin >> x;
			index = convert(x);
			s = s & (~index);
		}
		else if (!str.compare("toggle"))
		{
			cin >> x;
			index = convert(x);
			if(index & s)
				s = s & (~index);
			else 
				s |= index;
		}
		else if (!str.compare("all"))
		{
			index = 1;
			for (int i = 0; i < 20; i++)
			{
				index <<= 1;
				index++;
			}
			s = index;
		}
		else if (!str.compare("empty"))
			s &= 0;
	}
	return 0;
}