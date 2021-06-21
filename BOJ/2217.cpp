#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std; 
int n;
int *rope;
int ans;
int main(void)
{
	cin >> n;
	rope = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i]; 
	}
	sort(rope, rope + n);
	ans = rope[n - 1]; 
	for (int i = 1; i<=n; i++)
	{
		if (ans < rope[n - i] * i)
			ans = rope[n - i] * i;
	}
	cout << ans;
	//system("pause"); 
	return 0;
}