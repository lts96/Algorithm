#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, less<int>> pq;
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp;
	cin >> n;
	while (n != 0)
	{
		temp = n % 10;
		pq.push(temp);
		n /= 10;
	}
	while (!pq.empty())  
	{
		temp = pq.top();
		cout << temp;    // 출력 실수 -> 줄바꿈 x 
		pq.pop();
	}
	return 0;
}