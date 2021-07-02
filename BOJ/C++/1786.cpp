#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int ans;
vector<int> pi;
vector<int> locate;
void setPi(string s)  // 전처리 과정 (pi 배열을 미리 계산해놔야함)
{
	int m = s.length();
	int j = 0;
	pi.assign(m, 0);
	for (int i = 1; i < m; i++) // pi[0] 은 어차피 0 , 그래서 1부터 시작? 
	{
		while ((j > 0) && (s[i] != s[j])) // kmp 처럼 뛰어넘는 부분
			j = pi[j - 1];
		if (s[i] == s[j])  // j는 0부터 i는 1부터 비교 시작 
			pi[i] = ++j;    // j는 0부터이므로 +1 해주고 전달 
	}
	return;
}
void kmp(string t, string p)  // 위 함수와 동일한 방식 사용 
{
	int n = t.length(), m = p.length(), j = 0;
	setPi(p);
	for (int i = 0; i < n; i++)  // 맨 처음부터 비교해야하므로 0 시작 
	{
		while ((j > 0) && (t[i] != p[j]))
			j = pi[j - 1];  // j가 점프 (타겟은 그대로 , 아래가 움직인다고 생각하면 이해하기 쉬움)
		if (t[i] == p[j])
		{
			if (j == m - 1) // 완전히 일치할때 
			{
				ans++;
				locate.push_back(i - m + 1);  // 일치하기 시작한 위치 저장 
				j = pi[j]; // 다음으로 건너뛰기 
			}
			else  // 이어서 진행 
				j++;
		}
	}

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);   // 공백도 문자 취급이라서 무조건 getline으로 다 받아줘야됨
	kmp(s1, s2);
	//cout << s1 << ":" << s2 << endl;
	cout << ans << endl;
	for (int i = 0; i < locate.size(); i++)
		cout << locate[i] + 1 << " ";
	//system("pause");
	return 0;
}