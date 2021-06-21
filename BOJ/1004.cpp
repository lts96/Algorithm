#include <iostream>
#include <math.h>

int t, sx, sy, dx, dy, n , ans;
using namespace std;
void cal_dist(int x, int y , double d)
{
	double d1 = sqrt((x - sx)* (x - sx) + (y - sy) * (y - sy));
	double d2 = sqrt((x - dx)* (x - dx) + (y - dy) * (y - dy));
	if ((d1 < d && d2 > d) || (d1 > d && d2 < d))
		ans++;
	return;
}

int main(void)
{
	cin >> t;
	int x3, y3;
	double dist;
	for (int i = 0; i < t; i++)
	{
		ans = 0;
		cin >> sx >> sy >> dx >> dy;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> x3 >> y3 >> dist;
			cal_dist(x3, y3 , dist);
		}
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}