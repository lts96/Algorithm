#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
int n, k, ans;
int arr[101];
stack<int> s[101];
/*
아이디어만 잘 생각하면 금방 풀림
입력받는 순서대로 도로 큐에 넣어서 들어가는지 시험해본다고 생각
가장 최근에 들어간 숫자와 비교해서 내가 더 작으면 그쪽 큐에는 못들어가고 다른 곳을 찾아야됨
어떤 큐에도 들어갈 수 없다면 불가능한 경우인것
*/
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	// 모든 경우가 가능해짐 
	if (k >= n)
	{
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	bool flag;
	for (int i = 1; i <= n; i++)
	{
		flag = false;
		for (int j = 1; j <= k; j++)
		{
			if (s[j].empty())
			{
				flag = true;
				s[j].push(arr[i]);
				break;
			}
			else if(s[j].top() < arr[i])
			{
				flag = true;
				s[j].push(arr[i]);
				break;
			}
			//cout << arr[i] << " " << " stack [" << i << "]\n";
		}
		if (!flag)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
