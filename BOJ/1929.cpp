#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
bool primeNum[1000003];

// 계속 틀렸던 이유   소수의 제곱 수가  소수라고 나옴 
// 예외 994009 = 997 (소수)의 제곱
int main(void)
{
	int n, m;
	cin >> m >> n;

	for (int i = 0; i < 1000003; i++)
	{
		primeNum[i] = true;
	}
	primeNum[1] = false;
	// 주의 사항 -> 무조건 처음부터 체로 걸러야됨 
	for (int i = 2; (i*i) <= 1000000; i++)
	{
		for (int j = i * 2; j <= 1000000; j += i)     // j가 i*2 부터 시작하는 이유는 i가 소수일때 자기자신을 false 처리하면 안되기 때문
		{
			primeNum[j] = false;
		}                                     // j+= i 는 i의 배수만 찾아가서 바꾸겠다는 얘기 , 그리고 반드시 j는 1000000 까지 가야함 
	}										 // 만약 j <= n 까지만 가면 n 뒷부분이 죄다 true로 남게되서 과다 출력 
	/*
	for (long long i = m; i <= n; i++)                  // 잘못된 코드 부분 
 	{
		if (primeNum[i] == false)
			continue;
		for (int j = 0; j < prime.size(); j++)     // 이게 문제 , 1부터 진행할 경우 prime이 충분히 쌓이기 때문에 문제가 없지만 
												  // 중간부터 진행할 경우 prime이 해당 수의 제곱근 까지 쌓여있지 않으므로 제대로 검사 못함. 
												  // 알고리즘 자체가 잘못됨 , 무조건 처음부터 검사하게 해야됨 
		{
			if (prime[j] * prime[j] < i)
			{
				if (i % prime[j] == 0)
				{
					primeNum[i] = false;
					break;
				}
			}
			else if (prime[j] * prime[j] == i)
			{
				primeNum[i] = false;
				break;
			}
			else
			{
				break;
			}
		}
		if (primeNum[i] == true)
		{
			prime.push_back(i);
		}
	}
	*/
	for (int i = m; i <=n; i++)
	{
		if (primeNum[i] == true)
			printf("%d\n", i);
	}
	return 0;
}