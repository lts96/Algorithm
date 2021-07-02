#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector <int> v;
vector <int> ans;
int mid;
double average;
int frequent;
int range;
int cnt[8002];
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		v.push_back(temp);
		cnt[temp + 4000]++;
	}
	sort(v.begin(), v.end());
	range = v[n - 1] - v[0];
	mid = v[n / 2];
	average = sum / (double)n;
	int max = 0;
	for (int i = 0; i < 8002; i++)
	{
		if (max < cnt[i])
			max = cnt[i];
	}
	for (int i = 0; i < 8002; i++)
	{
		if (max == cnt[i])
			ans.push_back(i- 4000);
	}
	if (ans.size() == 1)
		frequent = ans[0];
	else
		frequent = ans[1];
	cout << round(average) << endl;  // round는 반올림 함수
	cout << mid << endl;
	cout << frequent << endl;
	cout << range << endl;
	return 0;
}