#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double x1, y1, r1, x2, y2, r2, ans = 0, d;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (d >= r1 + r2)
	{
		cout << fixed;
		cout.precision(3);
		cout << ans << "\n";
		//system("pause");
		return 0;
	}
	else if (!d || d + min(r1, r2) < max(r1, r2))
	{
		ans = pow(min(r1, r2), 2) * M_PI;
		cout << fixed;
		cout.precision(3);
		cout << ans << "\n";
		//system("pause");
		return 0;
	}
	double theta1 = 2 * acos((r1*r1 + d * d - r2 * r2) / (2 * r1*d));
	double theta2 = 2 * acos((r2*r2 + d * d - r1 * r1) / (2 * r2*d));
	ans = (r1*r1 * (theta1 - sin(theta1)) + r2 * r2 * (theta2 - sin(theta2))) / 2;
	cout << fixed;
	cout.precision(3);
	cout << ans << "\n";
	//system("pause");
	return 0;
}