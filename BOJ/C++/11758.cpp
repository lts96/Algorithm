#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
// 벡터 외적? 을 이용한 삼각형 넓이 구해서 그걸로 판정
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int s = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);
	if (s > 0)
		cout << 1 << endl;
	else if (s == 0)
		cout << 0 << endl;
	else if (s < 0)
		cout << -1 << endl;
	return 0;
}