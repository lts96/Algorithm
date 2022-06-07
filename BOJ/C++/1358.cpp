#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int n, m, ans;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	double a, b, d1, d2;
	for (int i = 0; i < p; i++)
	{
		cin >> a >> b;
		if ((a >= x && a <= x + w) && (b >= y && b <= y + h))
			ans++;
		else 
		{
			d1 = dist(a, b, x, y + h / 2);
			d2 = dist(a, b, x + w, y + h / 2);
			if (d1 <= h / 2 || d2 <= h / 2)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
