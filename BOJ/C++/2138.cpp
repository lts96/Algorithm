#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
int a[100003][2];
int b[100003];
int n, ans1, ans2;
// 항상 c++ 입력과 scanf를 섞어쓸때 주의하자 
// 입력 최적화했다가 버퍼 꼬여서 계속 틀렸었음 
// 그리디 문제 : i-1번째를 완전히 정하고 넘어가는게 최선 
int run(int start)
{
	int ret = 0, flag = 0;
	// 맨 앞버튼을 눌렀을때와 안누른 경우를 구분해야한다 
	// 인덱스 위반을 피하기 위해 탐색을 1부터 시작하기 때문 
	if (start == 1)
	{
		ret++;
		a[0][start] = (a[0][start] == 0) ? 1 : 0;
		a[1][start] = (a[1][start] == 0) ? 1 : 0;
	}
	// 1부터 돌면서 i-1을 보고 내가 누를지 말지를 정하기 
	// 이렇게 하는 이유는 i-1의 값이 i번째 결과에 따라서 최종적으로 확정되기 때문 
	for (int i = 1; i < n; i++)
	{
		if (a[i-1][start] != b[i-1])
		{
			ret++;
			a[i-1][start] = (a[i-1][start] == 0) ? 1 : 0;
			a[i][start] = (a[i][start] == 0) ? 1 : 0;
			if(i < n-1)
				a[i+1][start] = (a[i+1][start] == 0) ? 1 : 0;
		}
	}
	// 같은지 체크 
	for (int i = 0; i < n; i++)
	{
		if (a[i][start] != b[i])
			flag++;
	}
	if (flag != 0)
		return -1;
	else
		return ret;
}

int main(void)
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &a[i][0]);
		a[i][1] = a[i][0];
	}
	for(int i=0; i<n; i++)
		scanf("%1d", &b[i]);
	ans1 = run(0);
	ans2 = run(1);
	if (ans1 == -1 && ans2 == -1)
	{
		cout << ans1 << endl;
		return 0;
	}
	if (ans1 == -1 || ans2 == -1)
	{
		if (ans1 == -1)
			cout << ans2 << endl;
		else if (ans2 == -1)
			cout << ans1 << endl;
		return 0;
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}
