#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n, ans;
int stair[400];
int cache[400];

//점화식이 잘못됨 
//마지막 계단에서 2가지 경우로 나뉨  n-2 번째 계단에서 올라올때 / n-3 , n-1을 밟고 올라올때
// 연속 3칸을 밟을수 없기때문데 n-1을 밟는 경우 n-3 또한 밟아야 한다.

int stair_down(int count)
{
	if (cache[count] != 0)
	{
		return cache[count];
	}
	else
	{
		if (count == 0)
		{
			return cache[count] = stair[count];
		}
		if (count == 1)
		{
			return cache[count] = max(stair[count] + stair[count - 1], stair[count]);
		}
		if (count == 2)
		{
			return cache[count] = max(stair[count - 2] + stair[count], stair[count - 1] + stair[count]);
		}
		else if(count > 2)
			return cache[count] = stair[count] + max(stair[count - 1] + stair_down(count-3), stair_down(count - 2));
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];
	cache[0] = stair[0]; 
	cache[1] = max(stair[0] + stair[1], stair[1]);
	cache[2] = max(stair[2] + stair[0], stair[1] + stair[2]);
	ans = stair_down(n-1);
	//for (int i = 0; i < n; i++)
	//cout << i+1 << " : " << cache[i]<< endl;

	cout << ans << endl;
	//system("pause");
	return 0;
}