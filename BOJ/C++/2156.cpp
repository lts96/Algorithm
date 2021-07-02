#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;
int wine[10000];
int cache[10000];
int ans = 0;

// 2차원으로 cache 마다 연속으로 몇개 마셨는지 상태 나타내면서 푸는 방법도 있음
// 계단 오르기 문제와 다른점 : 마지막 잔을 반드시 마실 필요가 없음, 따라서 마지막을 안마시는 
// cache[i] = max(cache[i-1] , cache[i]); 경우를 비교해줘야됨
// 지금은 bottom - up으로 했지만 나중에 top - down 재귀로도 해볼것

int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> wine[i];
	cache[0] = wine[0]; 
	cache[1] = max(wine[0], wine[0] + wine[1]);
    
    
    // 여기 초기화 실수해서 삽질함   1 2 , 1 3 만 비교하고 2 3 을 빼먹음
	cache[2] = max(max(wine[0] + wine[1], wine[0] + wine[2]),wine[1]+ wine[2]);
	
	for (int i = 3; i < n; i++)
	{
		cache[i] = max(cache[i-2]+ wine[i], cache[i-3]+ wine[i-1]+ wine[i]);
        cache[i] = max(cache[i-1] , cache[i]);
	}
	for(int i=0;i<n;i++)
    {
        if(cache[i]>= ans)
            ans= cache[i];
    }
	cout << ans << endl;
	//system("pause");
	return 0;
}