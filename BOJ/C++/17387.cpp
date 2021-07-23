#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
// ccw를 이용해서 선분이 교차하는지 안하는지 판정하는 문제 
// 추가적으로 고려할 것  -> 2개의 선분이 아예 안만날수도 있음
// 이전 코드는 x축에 평행할때랑 y축에 평행할때 전처리가 부족해서 틀렸다 
// x축과 y축 경우를 pair 안쓰면 매우 귀찮게 처리해야됨 
long long ccw(long long s)
{
	long long temp;
	if (s > 0) // 반시계 
		temp = 1;
	else if (s == 0) // 평행
		temp = 0;
	else if (s < 0) // 시계
		temp = -1;
	return temp;
}
/*
반례 
0 0 0 3
0 4 0 5
0

1 1 1 3
1 0 1 -4
0
*/
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	// a,b,c,d
	long long x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	// ccw (a,b,c)
	long long s1 = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);
	// ccw (a,b,d)
	long long s2 = (x1 * y2 + x2 * y4 + x4 * y1) - (x1 * y4 + x4 * y2 + x2 * y1);
	// ccw (c,d,a)
	long long s3 = (x3 * y4 + x4 * y1 + x1 * y3) - (x3 * y1 + x1 * y4 + x4 * y3);
	// ccw (c,d,b)
	long long s4 = (x3 * y4 + x4 * y2 + x2 * y3) - (x3 * y2 + x2 * y4 + x4 * y3);
	s1 = ccw(s1);
	s2 = ccw(s2);
	s3 = ccw(s3);
	s4 = ccw(s4);
	//cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
	// 같은 직선 상에 있을때  	
	if (s1 * s2 == 0 && s3 * s4 == 0)
	{	
		// pair를 안쓰면 y축에 일직선일때랑 x축에 일직선일때 따로 처리해야된다
		pair<int, int> a = make_pair(x1, y1);
		pair<int, int> b = make_pair(x2, y2);
		pair<int, int> c = make_pair(x3, y3);
		pair<int, int> d = make_pair(x4, y4);
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c ,d);
		// a는 min(x1,x2)  b는 max (x1,x2) c는 min(x3,x4)  d는 max (x3,x4)
		if (a <= d && c <= b)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	// 교차할때 
	if (s1 * s2 <= 0 && s3 * s4 <= 0)
		cout << 1 << endl;
	else
		cout << 0<< endl;
	return 0;
}
