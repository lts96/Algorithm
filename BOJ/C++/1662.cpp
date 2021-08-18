#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
stack<pair <int, int>> s;
int ans;

int main(void)
{
	string str;
	cin >> str;
	int n = str.size();
	int cnt = 0;
	int temp;
	char c;
	for (int i = 0; i < n; i++)
	{
		c = str[i];
		// 그냥 문자일때는 페어 뒤에 0
		// 이미 압축이 풀린 문자일때는 뒤에 1로 구분
		// 직접 문자를 넣다 뺐다 하는건 스택이 터질거 같아서 길이만 가지고 연산해서 품 
		if (c != ')')
		{
			if (c == '(')
				s.push({ -1, 0 });
			else
				s.push({ c - 48, 0 });
		}
		else 
		{
			cnt = 0;
			while (s.top().first != -1)
			{
				if (s.top().second == 0)
					cnt++;
				else
					cnt += s.top().first;
				s.pop();
			}
			// -1 제거 
			s.pop();
			temp = s.top().first;
			s.pop();
			s.push({ temp * cnt, 1 });
		}
	}
	while (!s.empty())
	{
		if (s.top().second == 0)
			ans++;
		else
			ans += s.top().first;
		s.pop();
	}
	cout << ans << endl;
    return 0;
}
