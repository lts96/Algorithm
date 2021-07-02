#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m;

int arr[4001][4001];
int ans;
int main(void)
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1.at(i) == s2.at(j))
				arr[i][j] = 1;
			if (i >= 1 && j >= 1)
			{
				if (arr[i - 1][j - 1] != 0 && arr[i][j] == 1)
					arr[i][j] += arr[i - 1][j - 1];
			}
			ans = max(arr[i][j], ans);
		}
	}
	
	cout << ans << endl;
	return 0;
}