#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

char ans[200];
int cnt[30];

// 문자열 + 그리디 문제 

int main(void)
{
	string s, fail = "I'm Sorry Hansoo";
	cin >> s;
	int n = 0;
	int l = 0;
	int r = s.length() - 1;
	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i] - 'A']++;
		n++;
	}
	// 문자열이 짝수 길이인 경우 
	if (n % 2 == 0)
	{
		// 펠린드롬이 불가능한 경우 
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] % 2 != 0)
			{
				cout << fail << endl;
				return 0;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			char c = i + 'A';
			while (cnt[i] > 0 && l < r)
			{
				//cout << cnt[i] << " " << l << " " << r << endl;
				ans[l] = ans[r] = c;
				cnt[i] -= 2;
				l++; 
				r--;
			}
		}
	}
	else
	{
		// 펠린드롬이 불가능한 경우 
		int flag = 0;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] % 2 != 0)
			{
				if (flag == 0)
					flag++;
				else
				{
					cout << fail << endl;
					return 0;
				}
			}
		}
		for (int i = 0; i < 26; i++)
		{
			char c = i + 'A';
			while (cnt[i] > 1 && l < r)
			{
				//cout << cnt[i] << " " << l << " " << r << endl;
				ans[l] = ans[r] = c;
				cnt[i] -= 2;
				l++; 
				r--;
			}
			if (cnt[i] % 2 == 1)
				ans[n / 2] = i + 'A';
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}
