#include <iostream>
#include <stdlib.h>
using namespace std; 
int n;
int ans[500][500];
//int arr[500][500];
int max = 0;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)  // 총 125250 번 실행  이상무
		{
			cin >> ans[i][j];
		}
	}
	for (int i= n-1; i>0; i--)
	{
		for (int j = 0; j <= i; j++)  // 총 125250 번 실행
		{
			if (ans[i][j] <= ans[i][j+1])
			{
				ans[i - 1][j] += ans[i][j + 1];
			}
			if (ans[i][j] > ans[i][j+1])
			{
				ans[i - 1][j] += ans[i][j];
			}
		}
	}
	/*      
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)  // 총 125250 번 실행 이상무 
		{
			cout << ans[i][j] <<" ";
		}
		cout << "\n";
	}
	//cout << a;
	*/
	cout << ans[0][0] << endl;
	//system("pause");
	return 0; 
}