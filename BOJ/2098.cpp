#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
int ans , n;
int w[17][17];
int dp[17][65537];
// dp [i][j] -> i 는 내가 지금 있는 도시 , j는 내가 여태까지 방문한 도시들
// dp의 인덱스를 비트 마스크  index 하나로 내가 어떤 도시를 갔고 어디를 안갔는지
// 파악가능해야함.
int fin;
int travel(int cur, int visit)
{
	if (visit == fin)
    {
		if (w[cur][0])
			return w[cur][0];  // 내가 출발한 곳이 1이므로 마지막엔 1로 돌아와야함
		else
			return 2100000000; 
    }    // 이 경우는 마지막 도시에서 원점으로 돌아올 수 없는 경우
	int &ret = dp[cur][visit];
	if (ret != 0)
		return ret;
	ret = 2100000000;
	for (int i = 0; i <= n; i++) 
	{
		if (!(visit & (1 << i)) && w[cur][i]!=0)// 방문 안한 도시 찾기 , 방문하면서 비트 켜주기 
		{					  				 // w[cur][i] == 0 이면 못감 -> 제외 
			ret = min(ret, travel(i, visit | (1 << i)) + w[cur][i]);
			// i를 1로 시작하게 되면 visit와 비트 연산에서 하나가 더 켜짐 -> 에러
		}
	}
	return ret;
}
int main()
{
	cin >> n;
	fin = (1 << n) - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	}
	
	// 사실 어디서 출발하든 상관없음 -> 무조건 순회가 가능한 케이스를 주고 
	// 어차피 다 한번씩은 방문해야되기 때문 
	
	ans = travel(0,1);
	cout << ans << endl; 
	return 0;
}

