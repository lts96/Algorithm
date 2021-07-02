#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#define size 4000001
using namespace std;
bool prime[size];
int arr[300001];
int m, n , ans;
// 해결 방법 -> 4백만 까지 소수 구해서 arr에 저장   (소수 개수 약 280000개)
// 투포인터 알고리즘 사용해서 부분합을 구해서 비교하면 끝 
// 투포인터 헷갈리면 백준 부분합 문제 다시 참고할 것 

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	prime[0] = prime[1] = false;
	for (int i = 1; i <= 4000000; i++)
	{
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	for (int i = 2; (i*i) <= 4000000; i++)
	{
		if (!prime[i])
			continue;
		for (int j = i * 2; j <= 4000000; j += i)
		{
			prime[j] = false;
		}
	}
	int count = 2;
	for (int i = 2; i < size; i++)
	{
		if (prime[i])
		{
			arr[count] = i;
			count++;
		}
	}
	
		
	int start = 0; 
	int end = 0;
	int sum = 0;
	
	while (start < count)
	{
		if (sum > n)
		{
			sum -= arr[start];
			start++;
		}
		else if (end == count-1)
		{
			if (sum == n) 
			{
				ans++;
			}
			sum -= arr[start];
			start++;
		}
		else
		{
			if (sum == n)
			{
				ans++;
			}
			end++;
			sum += arr[end];
		}
	}
	cout << ans << "\n";
	return 0;
}