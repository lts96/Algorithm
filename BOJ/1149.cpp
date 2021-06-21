#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;
int arr[1000][3];    
// 0 red 1 green 2 blue  // 접근 방식이 잘못됨 같은 숫자가 나오면 다음에 고르는게 잘못될 수도 있다.
// 만약 3개의 값이 모두 같다면? 그 다음걸 봐야됨 
// 기존 방식으론 계속 예외 발생  아예 다른 방법으로 접근할것  


int main(void)
{
	long long min = 90000000000;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1];
		cin >> arr[i][2];
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (arr[i][0] < arr[i][1]) //blue
		{
			arr[i - 1][2] += arr[i][0];
		}
		else
		{
			arr[i - 1][2] += arr[i][1];
		}
		if (arr[i][0] < arr[i][2]) //green
		{
			arr[i - 1][1] += arr[i][0];
		}
		else
		{
			arr[i - 1][1] += arr[i][2];
		}
		if (arr[i][1] < arr[i][2]) //red
		{
			arr[i - 1][0] += arr[i][1];
		}
		else
		{
			arr[i - 1][0] += arr[i][2];
		}
	}

	/*

	for (int i = 0; i < n; i++)
	{
		cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << endl;
	}
	*/
	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] <= min)
			min = arr[0][i];
	}
	cout << min;
	//system("pause");
	return 0;
}