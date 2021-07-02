#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
unsigned int ans;
int n;
unsigned int arr[1000001];
unsigned int binary(int count)
{
	if (count == 1)
		return 1; 
	if (count == 2)
		return 2;
	if (arr[count] != 0)
		return arr[count];
	if (count != 1 && count != 2)
	{
		return arr[count] = (binary(count - 2) + binary(count - 1)) % 15746; 
	}
}

int main(void)
{
	cin >> n; 
	ans = binary(n);
	cout << ans << endl;
	//system("pause");
	return 0;
}