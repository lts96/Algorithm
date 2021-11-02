#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
long long arr[2097160];
long long cache[2097160];
int s, n, k;
long long ans;
/*
이진 트리를 사용하기 위해 1번은 0으로 채우고 인덱스 2번부터 입력값을 집어넣자
루트까지 거리가 같으려면 일단 내 자식 좌 우 에지는 길이가 같아야 한다. -> 모든 노드에 대해 좌 우 자식들의 값이 같아야 한다는 소리
에지 값을 노드라고 생각하고 풀자
내 값과 내 자식간 차이값을 그때그때 더해주면 전체 값이 나오게 된다
이해가 안되면 위에 나온 예시 중 쉬운거 하나를 직접 해보자
*/
long long dp(int idx)
{
	// idx가 리프일때 
	if (idx >= s && idx <= n)
	{
		ans += arr[idx];
		return arr[idx];
	}
	// left = 내 왼쪽에서 가장 긴 길이 
	long long left = dp(idx * 2);
	long long right = dp(idx * 2 + 1);
	long long result = left + right;
	// 내 자식들의 차이값을 답에 더해줘서 양쪽 간선이 동일하게 만듬 
	ans += arr[idx] + abs(left - right);
	// 루트까지 가장 긴 간선을 찾기 위해 좌 우 비교 
	return arr[idx] + max(left, right);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	n = 0;
	for (int i = 1; i <= k; i++)
		n += pow(2, i);
	n++;
	for (int i = 2; i <= n; i++)
		cin >> arr[i];
	s = n - pow(2, k) + 1;
	dp(1);
	cout << ans << endl;
	return 0;
}
