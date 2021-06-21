#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h> 
int n;
using namespace std;
// 점화식 2^n -1 번 
// 내가 1-> 2 n-1개를 옮기고 맨 아래를 3으로 옮김 , 마지막으로 2->3 n-1개를 옮기면 끝

void hanoi(int cnt , int a , int b , int c)  // a 시작점 , b 경유지 , c 목적지 
{
	if (cnt == 1)
	{
		cout << a << " " << c << "\n";
		return;
	}
	hanoi(cnt - 1, a, c , b);
	cout << a << " " << c << "\n";  // 이게 문제 
	hanoi(cnt - 1, b, a, c);
	return;
}

int main(void)
{
	cin >> n;
	unsigned long long k = pow(2, n) - 1;  // 틀렸던 이유 -> 옮긴 횟수 오버플로우
	cout << k << endl;
	hanoi(n, 1, 2 ,3);
	return 0;
}