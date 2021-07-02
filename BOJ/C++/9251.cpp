#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m;

int dp[4001][4001];
int ans;

// 부분 문자열 c가 있다고 하자 (양쪽 모두 공유)
// c가 모두의 부분 수열이 될 수 있는 범위는 c가 일치한 index ~ 문자열 끝까지
// 따라서 c가 일치하면 해당 행 뒷부분은 전부 c가 부분으로 들어갈 수 있으므로 1로 처리
int main(void)
{
	string s1, s2 , s3;
	cin >> s1;
	cin >> s2;
	for (int i = 1; i <= s2.length(); i++)
	{
		for (int j = 1; j <= s1.length(); j++)
		{
		
			if (s1.at(j-1) == s2.at(i-1))
			{
				// 문자열이 연속할때
				if(i>=1&& j>=1)
				dp[i][j] = dp[i-1][j-1]+1; 
			}
			else // 연속하지 않더라도 문자열간  부분집합이 존재
			{
				// 2개의 문자열 1,2가 있다고 했을때 1이 2에 속할때 개수와 2가 1에 속할때 개수중
				// 큰 것을 고른다.
				// 어차피 지금 문자는 다르므로 더할 필요 x 
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
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
	return 0;
}