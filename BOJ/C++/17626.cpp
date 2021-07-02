#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define SIZE 223
using namespace std;
int ans = 9999999, n;
int arr[224];
vector<int> v;
// n이 5만 까지 -> 브루트포스로 가능?   시간이 걸림 
// 50000일때 시간 over 
// 이분 탐색으로 풀어봄 -> 제곱수 2개의 합으로 vector 구성 
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= SIZE; i++)
		arr[i] = i * i;
	for (int i = 1; i <= SIZE; i++) // n이 제곱수 일때 = 답이 1일때
	{
		if (arr[i] == n)
		{
			cout << 1 << "\n";
			return 0;
		}
	}
	int sum;
	for (int i = 1; i <= SIZE; i++)
	{
		for (int j = 1; j <= SIZE; j++)
		{
			sum = arr[i] + arr[j];
			if (sum == n)
			{
				cout << 2 << "\n";
				return 0;
			}
			if(sum < n)
				v.push_back(sum);
		}
	}
	sort(v.begin(), v.end());
	int target , temp;
	for (int i = 1; i <= SIZE; i++)
	{
		target = n - arr[i];
		temp = lower_bound(v.begin(), v.end(), target) - v.begin();
		if (target == v[temp])
		{
			cout << 3 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		target = n - v[i];
		temp = lower_bound(v.begin(), v.end(), target) - v.begin();
		if (target == v[temp])
		{
			cout << 4 << "\n";
			return 0;
		}
	}
}