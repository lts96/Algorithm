#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
string decoding(string s)
{
	int idx = 0; 
	int n = s.length();
	bool error = false;
	bool zero = false;  // 0이 반복되도 되는 상황인지 체크용
	bool one = false;
	if (n == 1 || s[n - 1] == '0')  // 끝은 무조건 1이어야함
		return "NO";
	while (1)
	{
		if (idx >= n)
			break;
		if (s[idx] == '0') // 01 규칙
		{
			if (idx + 1 <= n - 1 && s[idx + 1] == '1')
			{
				idx += 2;
				continue;
			}
			else
			{
				error = true;
				break;
			}
		}
		else
		{
			if ((idx + 2 <= n - 1) && (s[idx + 1] == '0' && s[idx+2]=='0'))
			{
				idx += 3;
				int cnt = 0;
				while (idx < n)
				{
					if (s[idx] == '0')
						idx++;
					else
						break;
				}
				while (idx < n)
				{
					if (s[idx] == '1')
					{
						idx++;
						cnt++;
					}
					else
						break;
				}
				if (cnt == 0)
				{
					error = true;
					break;
				}
				if ((idx + 1 < n && s[idx + 1] == '0') && cnt > 1)
				{
					idx--;
					continue;
				}
			}
			else
			{
				error = true;
				break;
			}
		}
	}
	if (error)
		return "NO";
	return "YES";
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << decoding(s) << "\n";
	}
	return 0;
}
