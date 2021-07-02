#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h> 
int n, h , ans = 21000000;
int height[500001];
double * up , * down ;  
using namespace std;

int main(void)
{
	cin >> n >> h;
	int m = n / 2;
	up = new double[m];  //종유석
	down = new double[m]; // 석순 
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1) // i가 홀수라면 
			cin >> up[i / 2];
		else
			cin >> down[i / 2];
	}
	sort(up, up + m);
	sort(down, down + m);

	int left, right, mid , cnt_down, cnt_up ,result;
	for (int i = 1; i <= h; i++)
	{
		left = 0, right = m-1 , cnt_down = 0 , cnt_up = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			double d = i - 0.5;
			if (down[mid] >= d )
			{
				right = mid - 1;
				cnt_down = m - mid;
			}
			else 
				left = mid + 1;
		}
		left = 0, right = m - 1;
		while (left <= right) // 여기가 문제 
		{
			mid = (left + right) / 2;
			double d = (h - i) + 0.5;
			if (up[mid] >= d)
			{
				right = mid - 1;
				cnt_up = m - mid;
			}
			else
				left = mid + 1;
		}
		result = cnt_down + cnt_up;
		//cout << cnt_down << " " << cnt_up << endl;
		if (ans > result)
			ans = result;
		height[i] = result;
	}
	int count = 0;
	for (int i = 1; i <= h; i++)
	{
		if (height[i] == ans)
			count++;
		//cout << height[i] << " ";
	}
	cout << ans << " " << count << endl;
	delete[] up;
	delete[] down;
	return 0;
}