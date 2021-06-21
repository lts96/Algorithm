#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int cache[51][51][51];
int w(int a, int b, int c)
{
	if ((a <= 0 || b <= 0) || c <= 0)
		return 1;
	if (cache[a][b][c] != 0)
		return cache[a][b][c];
	if ((a > 20 || b > 20) || c > 20)
		return cache[a][b][c] = w(20, 20, 20);
	if (a < b && b < c)
		return cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cache[0][0][0] = 1;
	while (1)
	{
		cin >> a >> b >> c;
		if ((a == -1 && b == -1) && c == -1)
			break;
		cout <<"w("<<a<<", "<<b <<", "<<c<<") = "<< w(a, b, c) << "\n";
	}
	return 0;
}
