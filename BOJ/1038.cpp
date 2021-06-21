#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std; 
long long ans,n;
queue <long long> q;
long long v[1026]; 
bool arr[10]; 
// 자기 보다 작은 수가 몇개 있느냐에 따라 감소할수 있는 수의 개수가 달라짐. 
// 1일때 1보다 작은 수는 0뿐이므로 0이 있냐 없냐에 따라 2개
// 2일때 1,0 이 있으므로 가능한 조합의 수는 2^2  = 4개 
// 비트 마스크 사용? 
bool bitset(int a, int b)
{
	return (a&(1 << b)) > 0;
}
long long brute()  // 마지막 감소하는 수는 9876543210 이다.  long long 사용
{
	long long temp=0;
	int size = 0;
	for (int i = 1; i <= 1023; i++)
	{
		for (int j = 0; j <=9; j++)
		{
			if (bitset(i, j) == 1)
			{
				q.push(j);
			}
		}
		size = q.size();
		for (long long j = 0; j < size; j++)
		{
			temp += q.front()*pow((long long) 10,j);
			q.pop();
		}
		v[i - 1] = temp;
		temp = 0;
	}
	
	// 다 집어넣고 순서대로 sort
	sort(v+1,v+1023);

		if (n<1023)
			return v[n];
		else
			return -1;
}

int main(void)  
{
	cin >> n; 
	ans = brute();
	cout << ans; 
	//system("pause");
	return 0;
}