#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int ans;
int main(void)
{
	int test; 
	int x1, y1, r1, x2, y2, r2;
	cin >> test; 
	for (int i = 0; i < test; i++)
	{
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		if ((x1 == x2) && (y1 == y2))  // 중심이 같을때 
		{
			if (r1 == r2) // 완전 일치
				ans = -1;
			if (r1 != r2) // 동심원
				ans = 0;
		}
		else
		{
			double dist = sqrt((x1 - x2)* (x1 - x2) + (y1 - y2)*(y1 - y2));
			if ((double) (r1 + r2 )== dist) // 외접 또는 내접 
				ans = 1; 
			if ((double)(r1 + r2) > dist)
			{
				if (r1 > r2)
				{
					if (r1 > dist + r2)
						ans = 0;
					if ((double)r1 == (double)(dist + r2))
						ans = 1; 
					if (r1 < dist + r2)
						ans = 2;
				}
				else
				{
					if (r2 > dist + r1)
						ans = 0;
					if ((double)r2 == (double)(dist + r1))
						ans = 1;
					if (r2 < dist + r1)
						ans = 2;
				}
			}
			if ((double)(r1 + r2) < dist)
				ans = 0;

		}
		cout << ans << endl;
	}

	//system("pause");
	return 0;
}
