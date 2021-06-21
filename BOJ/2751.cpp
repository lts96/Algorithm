#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
priority_queue <int , vector<int> , greater<int>> pq;

int main(void)   // 힙 사용 -> nlogn
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int n , temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		pq.push(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}