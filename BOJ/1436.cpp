#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;
int n;
int ans;
int main(void)
{ 
	cin >> n;
	int count = 0;
	for (int i = 666; i < 50000000; i++)
	{
		char s[10];
		sprintf(s, "%d", i);
		string str(s);
		if (str.find("666")!=string::npos)
		{
			count++;
			if (count == n)
			{
				ans = i;
				cout << ans << endl;
				//system("pause");
				return 0;
			}
		}
	}
	//system("pause");
	return 0;
}