#include <iostream>
#include <stdlib.h>

using namespace std; 
unsigned long long ans[101];
int n, test; 


unsigned long long wave(int count)
{
	if (count <= 5)
		return ans[count]; 
	if (ans[count] != 0)
		return ans[count];
	else
		return ans[count] = wave(count - 2) + wave(count - 3); 
}
int main(void)
{
	cin >> test; 
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		ans[1] = ans[2] = ans[3] = 1;
		ans[4] = ans[5] = 2;
		wave(n);
		cout << ans[n] << endl;
	}
	//system("pause");
	return 0; 
}