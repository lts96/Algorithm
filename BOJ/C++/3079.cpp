#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
/*

프로그래머스에 똑같은 문제 그대로 있음
* 예제는 맞았는데 10퍼에서 틀림
* 중간에 int로 해놔서 오버플로우 났던게 문제 -> 전부 long long 하니까 통과

이분 탐색 응용문제 
시간을 기준으로 parametic search를 하는 문제
주어진 시간 동안 모든 사람이 통과 가능한지를 분별함수로 두고 
모든 사람이 통과 가능한 최소한의 시간을 찾는 문제 
이분 탐색 오랜만이라 무엇을 기준으로 삼아야 할지 헷갈려서 어려웠음 
*/
using namespace std;
unsigned long long n, m;
vector <int> arr;
unsigned long long ans = ULLONG_MAX-1;

// 주어진 시간 time 동안 모든 사람이 통과 가능한지 체크용 
unsigned long long passed(unsigned long long time)
{
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += (time / arr[i]);
	return sum;
}

int main(void)
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	unsigned long long left = 0, right = arr[n-1]*m, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		unsigned long long result = passed(mid);
		if (result >= m)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
