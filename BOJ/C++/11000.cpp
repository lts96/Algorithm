#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
priority_queue<pair <int, int>, vector <pair <int , int>>,greater<pair<int , int>>> pq;
priority_queue<int,vector <int>, greater<int>> dest;
vector <pair <int, int>> arr;

// 그리디 문제 , 종료 시간을 담을 dest 큐 하나만 써도 됨 
// 강의 시간 빠른 순으로 소팅한다음 하나씩 보면서 현재 dest의 top과 비교 
// 비교해서 더 빠르면 dest에 강의 추가, 아니면 dest에서 하나 pop 하고 내 종료시간 하나 추가 
// dest의 사이즈가 최종 강의실 개수 = 답이 된다 
int main(void)
{
	cin >> n;
	int s,d, t;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		pq.push(make_pair(s, t));
	}
	d = pq.top().second;
	pq.pop();
	dest.push(d);
	while (!pq.empty())
	{
		s = pq.top().first;
		d = pq.top().second;
		t = dest.top();
		if (s >= t)
		{
			dest.pop();
			dest.push(d);
		}
		else
			dest.push(d);
		pq.pop();
	}
	cout << dest.size() << endl;
	return 0;
}
