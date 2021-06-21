#include <iostream>
#include <math.h>
using namespace std; 
int n;  // n < 15
long long r,c,ans;
void div(int size , int dx , int dy)
{
	long long mid = pow(2, size - 1); 
	if (size == 1)
	{
		if (c== dx && r==  dy) // 1
		{
			return;
		}
		if (c== mid + dx && r== dy) // 2
		{
			ans++;
			return;
		}
		if (c== dx && r == mid + dy) // 3 
		{
			ans += 2;
			return;
		}
		if (c== mid + dx && r == mid + dy) // 4
		{
			ans += 3;
			return;
		}
		return;
	}
	else
	{
		if (c<mid+dx && r< mid+dy) // 1
		{
			div(size-1,dx,dy);
			return;
		}
		if (c>=mid+dx && r< mid+dy) // 2
		{
			ans += mid * mid;
			div(size-1,dx+mid,dy);
			return;
		}
		if (c<mid+dx && r>=mid+dy) // 3 
		{
			ans += mid * mid * 2;
			div(size-1,dx,dy+mid);
			return;
		}
		if (c>=mid+dx && r>=mid+dy) // 4
		{
			ans += mid * mid * 3;
			div(size-1,dx+mid,dy+mid);
			return;
		}
	}
}
int main(void)
{
	cin >> n;
	cin >> r; 
	cin >> c;
	div(n,0,0);
	cout << ans;
	//system("pause");
	return 0; 
}