#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;

int main(void)
{
	int test; 
	cin >> test; 
	for (int h = 0; h < test; h++)
	{
		bool flag = false;
		int x, y , dist , ans = 0 , warp = 1; 
		cin >> x >> y;
		dist = y - x;
		if (dist == 1)
		{
			cout << "1" << endl;
		}
		if (dist == 2)
		{
			cout << "2" << endl;
		}
		if (dist == 3)
		{
			cout << "3" << endl;
		}
		if (dist == 4)
		{
			cout << "3" << endl;
		}
		else if (dist > 4)
		{
			while (dist > 0)
			{
				for (int i = 0; i < 2; i++)
				{
					dist -= warp;
					ans++;
					if (dist <= 0)
					{
						flag = true;
						break;
					}
				}
				if (flag)
					break;
				warp++;
			}
			cout << ans << endl;
		}
	}
	//system("pause");
	return 0;
}
