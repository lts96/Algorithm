#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n, ans;
vector <string> arr;
int alpha[26];
int cnt[26];
// 그리디 문제 , 자리수가 빠른 알파벳 순으로 높은 숫자 부여
// 반례있음  길이가 큰 거 위주로 주다가 길이가 1칸 작지만 반복적으로 나오는 경우가 있음
// 각 알파벳이 나타나는 자리수의 합을 구해야 한다 
// 그래야 2번째 자리 수가 더 많이 나타나서 첫번째 자리수 값보다 높은 값을 
// 받아야하는 경우도 계산 가능 
int main(void)
{
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	char c;
	int idx , num = 9;
	vector <pair <int, int>> v;
	// 출현한 문자 체크해주면서 알파벳 별 자리수를 더해주기 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			c = arr[i][j];
			idx = c - 'A';
			cnt[idx] += pow(10, arr[i].size() - 1 - j);
		}
	}

	for (int i = 0; i < 26; i++)
	{
		alpha[i] = -1;
		if (cnt[i] > 0)
			v.push_back(make_pair(cnt[i] * -1, i));
	}
	
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		idx = v[i].second;
		if (alpha[idx] == -1)
			alpha[idx] = num--;
	}

	// 계산 부분
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			c = arr[i][j];
			idx = c - 'A';
			ans += (alpha[idx] * pow(10, arr[i].size() - 1 - j));
		}
	}
	cout << ans << endl;
	return 0;
}
