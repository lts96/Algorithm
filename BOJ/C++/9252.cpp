#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
int n, m;

int dp[4001][4001];
int ans;
stack<char> s;
using namespace std;
int main()
{
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	for (int i = 1; i <= s2.length(); i++)
	{
		for (int j = 1; j <= s1.length(); j++)
		{

			if (s1.at(j - 1) == s2.at(i - 1))
			{
				// 문자열이 연속할때
				if (i >= 1 && j >= 1)
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else // 연속하지 않더라도 문자열간  부분집합이 존재
			{
				// 2개의 문자열 1,2가 있다고 했을때 1이 2에 속할때 개수와 2가 1에 속할때 개수중
				// 큰 것을 고른다.
				// 어차피 지금 문자는 다르므로 더할 필요 x 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}

		}
	}
	for (int i = 1; i <= s2.length(); i++)
	{
		for (int j = 1; j <= s1.length(); j++)
		{
			//cout << dp[i][j] << " ";

			if (dp[i][j] > ans)
				ans = dp[i][j];
		}
		//cout << endl;
	}
	cout << ans << endl;
	int count = 0;
	int x = s2.length();
	int y = s1.length();
	while (count != ans) //뒤에서부터 문자 추적 , 나랑 같은 거 쭉 가다가 나랑 대각선 비교해서 넘어가는 식
	{
		if (dp[x][y] == dp[x - 1][y])
			x--;
		else if (dp[x][y] == dp[x][y - 1])
			y--;
		else
		{
			if (dp[x][y] == dp[x - 1][y - 1]+1)
			{
				s.push(s1.at(y - 1));
				count++;
				x--;
				y--;
			}
		}
	}
	for (int i = 0; i < ans; i++)
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}