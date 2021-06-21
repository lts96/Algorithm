#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
// 카운팅 정렬은 각 수의 최대 크기가 작고 자주 나올때 사용 
int arr[10001];
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp;
	cin >> n;
	for (int i = 1; i <= n; i++) // 몇번 나왔는지 카운트 
	{
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i <= 10000; i++)  // 여기를 n으로 했다가 틀림 -> n이 10000보다 클수도 있다 
	{
		while (arr[i] > 0)
		{
			arr[i]--;
			cout << i << "\n";
		}
	}
	return 0;
}