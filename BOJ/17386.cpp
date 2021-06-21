#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
// ccw를 이용해서 선분이 교차하는지 안하는지 판정하는 문제 
// 하나의 선분을 기준으로 다른 선분의 점 2개를 ccw 해서 1, -1이 나오면 교차
// 둘다 1이 나오거나 -1이 나오거나 0이나오면 교차 x 
// 추가적으로 고려할 것  -> 2개의 선분이 아예 안만날수도 있음
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
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	long long x1, y1, x2, y2, x3, y3 , x4 , y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	long long s1 = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);
	long long s2 = (x1 * y2 + x2 * y4 + x4 * y1) - (x1 * y4 + x4 * y2 + x2 * y1);
	long long s3 = (x3 * y4 + x4 * y1 + x1 * y3) - (x3 * y1 + x1 * y4 + x4 * y3);
	long long s4 = (x3 * y4 + x4 * y2 + x2 * y3) - (x3 * y2 + x2 * y4 + x4 * y3);
	s1 = ccw(s1);
	s2 = ccw(s2);
	s3 = ccw(s3);
	s4 = ccw(s4);
	if ((s1 == 1 && s2 == -1) || (s1 == -1 && s2 == 1))
	{
		if (s3 * s4 == 1)
			cout << 0 << endl;
		else 
			cout << 1 << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}